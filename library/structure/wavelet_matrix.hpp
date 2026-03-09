#pragma once
#include <bits/stdc++.h>
using namespace std;

// Wavelet Matrix
// Operations on a static sequence a[0..n)  of non-negative integers.
// All values must be < (1 << B) after coordinate compression.
//
// O(n B) build,  O(B) per query  (B = number of bits, default 20)
//
// Queries:
//   kth(l, r, k)              k-th (0-indexed) smallest in a[l..r)
//   count(l, r, x)            number of occurrences of x in a[l..r)
//   count_lt(l, r, x)         number of elements < x in a[l..r)
//   range_freq(l, r, lo, hi)  count of elements in [lo, hi) in a[l..r)

template <int B = 20>
struct wavelet_matrix {
    // Succinct bit vector with rank
    struct bv {
        vector<uint32_t> blk;
        vector<int> cum;
        int n;
        template <class F>
        void build(int sz, F get) {
            n = sz;
            blk.assign((n + 31) >> 5, 0);
            cum.resize(blk.size() + 1, 0);
            for (int i = 0; i < n; i++) if (get(i)) blk[i >> 5] |= 1u << (i & 31);
            for (int i = 0; i < (int)blk.size(); i++)
                cum[i+1] = cum[i] + __builtin_popcount(blk[i]);
        }
        // number of 1s in [0, i)
        int rank1(int i) const {
            if (i <= 0) return 0;
            return cum[i >> 5] + __builtin_popcount(blk[i >> 5] & ((1u << (i & 31)) - 1));
        }
        int rank0(int i) const { return i - rank1(i); }
        int total1() const { return cum.back(); }
    };

    int n;
    array<bv, B> bvs;
    array<int, B> mid; // number of 0s at each level

    wavelet_matrix() = default;

    // Build from vector. Values must be in [0, 2^B).
    void build(vector<int> v) {
        n = v.size();
        for (int d = B - 1; d >= 0; d--) {
            bvs[d].build(n, [&](int i){ return (v[i] >> d) & 1; });
            mid[d] = bvs[d].rank0(n);
            vector<int> a0, a1;
            for (int x : v) ((x >> d) & 1 ? a1 : a0).push_back(x);
            v = a0; v.insert(v.end(), a1.begin(), a1.end());
        }
    }

    pair<int,int> _down(int d, int l, int r, int bit) const {
        int l0 = bvs[d].rank0(l), r0 = bvs[d].rank0(r);
        if (bit == 0) return {l0, r0};
        return {mid[d] + l - l0, mid[d] + r - r0};
    }

    // k-th (0-indexed) smallest in a[l..r)
    int kth(int l, int r, int k) const {
        int res = 0;
        for (int d = B - 1; d >= 0; d--) {
            int cnt0 = bvs[d].rank0(r) - bvs[d].rank0(l);
            if (k < cnt0) { tie(l, r) = _down(d, l, r, 0); }
            else { k -= cnt0; res |= (1 << d); tie(l, r) = _down(d, l, r, 1); }
        }
        return res;
    }

    // number of elements < x in a[l..r)
    int count_lt(int l, int r, int x) const {
        int cnt = 0;
        for (int d = B - 1; d >= 0; d--) {
            int b = (x >> d) & 1;
            if (b) cnt += bvs[d].rank0(r) - bvs[d].rank0(l);
            tie(l, r) = _down(d, l, r, b);
        }
        return cnt;
    }

    // number of occurrences of x in a[l..r)
    int count(int l, int r, int x) const {
        for (int d = B - 1; d >= 0; d--)
            tie(l, r) = _down(d, l, r, (x >> d) & 1);
        return r - l;
    }

    // number of elements in [lo, hi) in a[l..r)
    int range_freq(int l, int r, int lo, int hi) const {
        return count_lt(l, r, hi) - count_lt(l, r, lo);
    }
};

// Wavelet matrix with sum support  (O(B) sum_lt queries)
// Stores prefix sums at each level of the wavelet matrix.
template <int B = 20>
struct wavelet_matrix_sum : wavelet_matrix<B> {
    using base = wavelet_matrix<B>;
    array<vector<long long>, B> lpsum;

    void build(vector<int> v) {
        base::build(v);
        int n = v.size();
        for (int d = B - 1; d >= 0; d--) {
            lpsum[d].resize(n + 1, 0);
            vector<int> a0, a1;
            for (int x : v) ((x >> d) & 1 ? a1 : a0).push_back(x);
            for (int i = 0; i < (int)a0.size(); i++) lpsum[d][i+1] = lpsum[d][i] + a0[i];
            int off = a0.size();
            for (int i = 0; i < (int)a1.size(); i++) lpsum[d][off+i+1] = lpsum[d][off+i] + a1[i];
            v = a0; v.insert(v.end(), a1.begin(), a1.end());
        }
    }

    // sum of elements < x in a[l..r)  O(B)
    long long sum_lt(int l, int r, int x) const {
        long long s = 0;
        int cl = l, cr = r;
        for (int d = B - 1; d >= 0; d--) {
            int b = (x >> d) & 1;
            int l0 = base::bvs[d].rank0(cl), r0 = base::bvs[d].rank0(cr);
            if (b) {
                s += lpsum[d][r0] - lpsum[d][l0];
                cl = base::mid[d] + (cl - l0);
                cr = base::mid[d] + (cr - r0);
            } else {
                cl = l0; cr = r0;
            }
        }
        return s;
    }

    // sum of elements in [lo, hi) in a[l..r)
    long long range_sum(int l, int r, int lo, int hi) const {
        return sum_lt(l, r, hi) - sum_lt(l, r, lo);
    }
};
