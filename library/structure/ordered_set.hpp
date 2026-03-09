#pragma once
#include <bits/stdc++.h>
using namespace std;

// Ordered set (multiset) using BIT for rank queries
// Values must be in [0, MAXV)  after coordinate compression.
// For arbitrary integers, use BIT + coordinate compression externally.
//
// O(log N) per operation.  N = number of distinct buckets (MAXV).
struct ordered_set {
    int n;
    vector<int> bit;
    int total = 0;

    ordered_set() = default;
    ordered_set(int n) : n(n), bit(n + 1, 0) {}

    void _add(int i, int v) { for (i++; i <= n; i += i & -i) bit[i] += v; }
    int  _sum(int i) const  { int s = 0; for (; i > 0; i -= i & -i) s += bit[i]; return s; }
    int  _sum(int l, int r) const { return l >= r ? 0 : _sum(r) - _sum(l); } // [l, r)

    void insert(int x) { _add(x,  1); ++total; }
    void erase (int x) { _add(x, -1); --total; }
    int  count (int x) const { return _sum(x, x + 1); }
    int  size  ()       const { return total; }
    bool empty ()       const { return total == 0; }

    // rank of x: number of elements < x
    int  rank(int x) const { return _sum(x); }

    // k-th (0-indexed) smallest element
    int kth(int k) const {
        assert(0 <= k && k < total);
        int pos = 0;
        for (int pw = 1 << __lg(n); pw; pw >>= 1)
            if (pos + pw <= n && bit[pos + pw] <= k)
                k -= bit[pos += pw];
        return pos; // 0-indexed value
    }

    // smallest element >= x  (lower_bound)
    int lower_bound(int x) const { return kth(rank(x)); }
    // smallest element >  x  (upper_bound)
    int upper_bound(int x) const {
        int r = rank(x + 1);
        assert(r < total);
        return kth(r);
    }
};
