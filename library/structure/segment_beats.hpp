#pragma once
#include <bits/stdc++.h>
using namespace std;

// Segment Beats (Ji Driver Segmentation)
// Supports (all queries half-open [l, r)):
//   range_chmin(l, r, x) : a[i] = min(a[i], x)
//   range_chmax(l, r, x) : a[i] = max(a[i], x)
//   range_add  (l, r, x) : a[i] += x
//   range_set  (l, r, x) : a[i] = x
//   query_max  (l, r)    : max of a[l..r)
//   query_min  (l, r)    : min of a[l..r)
//   query_sum  (l, r)    : sum of a[l..r)
//
// Amortized O((n + q) log^2 n).
// Reference: https://tjkendev.github.io/procon-library/cpp/range_query/segment_tree_beats_2.html

struct segment_beats {
    using ll = long long;
    static constexpr ll LINF = 2e18;

    int n, n0;
    // max_v, smax_v: max value, strict 2nd-max value (-LINF if none)
    // min_v, smin_v: min value, strict 2nd-min value (+LINF if none)
    vector<ll> max_v, smax_v, min_v, smin_v, sm, sz, ladd, lval;
    vector<int> max_c, min_c;

    // ---- leaf/node modifiers ----
    // addall: add x to every element of node k
    void addall(int k, ll x) {
        max_v[k] += x;
        if (smax_v[k] != -LINF) smax_v[k] += x;
        min_v[k] += x;
        if (smin_v[k] !=  LINF) smin_v[k] += x;
        sm[k] += sz[k] * x;
        if (lval[k] != LINF) lval[k] += x;
        else                 ladd[k] += x;
    }
    // setall: set every element of node k to x
    void setall(int k, ll x) {
        max_v[k] = smax_v[k] = min_v[k] = smin_v[k] = x;
        max_c[k] = min_c[k] = (int)sz[k];
        sm[k] = sz[k] * x;
        lval[k] = x; ladd[k] = 0;
    }
    // push_chmin: apply chmin(x) to node k, reducing its current max to x
    //   precondition: smax_v[k] < x < max_v[k]
    void push_chmin(int k, ll x) {
        sm[k] -= (max_v[k] - x) * max_c[k];
        if (max_v[k] == min_v[k]) min_v[k] = x;
        if (max_v[k] == smin_v[k]) smin_v[k] = x;
        max_v[k] = x;
        if (lval[k] != LINF && lval[k] > x) lval[k] = x;
    }
    // push_chmax: apply chmax(x) to node k, raising its current min to x
    //   precondition: smin_v[k] > x > min_v[k]
    void push_chmax(int k, ll x) {
        sm[k] += (x - min_v[k]) * min_c[k];
        if (max_v[k] == min_v[k]) max_v[k] = x;
        if (smax_v[k] == min_v[k]) smax_v[k] = x;
        min_v[k] = x;
        if (lval[k] != LINF && lval[k] < x) lval[k] = x;
    }

    // pull: recompute node k from its children
    void pull(int k) {
        int l = 2*k, r = 2*k+1;
        sm[k] = sm[l] + sm[r];
        // max info
        if      (max_v[l] < max_v[r]) { max_v[k]=max_v[r]; max_c[k]=max_c[r]; smax_v[k]=max(max_v[l], smax_v[r]); }
        else if (max_v[l] > max_v[r]) { max_v[k]=max_v[l]; max_c[k]=max_c[l]; smax_v[k]=max(smax_v[l], max_v[r]); }
        else                          { max_v[k]=max_v[l]; max_c[k]=max_c[l]+max_c[r]; smax_v[k]=max(smax_v[l], smax_v[r]); }
        // min info
        if      (min_v[l] < min_v[r]) { min_v[k]=min_v[l]; min_c[k]=min_c[l]; smin_v[k]=min(smin_v[l], min_v[r]); }
        else if (min_v[l] > min_v[r]) { min_v[k]=min_v[r]; min_c[k]=min_c[r]; smin_v[k]=min(min_v[l], smin_v[r]); }
        else                          { min_v[k]=min_v[l]; min_c[k]=min_c[l]+min_c[r]; smin_v[k]=min(smin_v[l], smin_v[r]); }
    }

    // push: propagate lazy values to children
    void push(int k) {
        if (k >= n0) return;  // leaf: nothing to push
        if (lval[k] != LINF) {
            setall(2*k, lval[k]); setall(2*k+1, lval[k]);
            lval[k] = LINF; ladd[k] = 0;
            return;
        }
        if (ladd[k] != 0) {
            addall(2*k, ladd[k]); addall(2*k+1, ladd[k]);
            ladd[k] = 0;
        }
        // propagate chmin / chmax bounds
        if (max_v[k] < max_v[2*k])   push_chmin(2*k,   max_v[k]);
        if (min_v[2*k] < min_v[k])   push_chmax(2*k,   min_v[k]);
        if (max_v[k] < max_v[2*k+1]) push_chmin(2*k+1, max_v[k]);
        if (min_v[2*k+1] < min_v[k]) push_chmax(2*k+1, min_v[k]);
    }

    // ---- range operations ----
    void _chmin(ll x, int a, int b, int k, int l, int r) {
        if (b <= l || r <= a || max_v[k] <= x) return;
        if (a <= l && r <= b && smax_v[k] < x) { push_chmin(k, x); return; }
        push(k); int m = (l+r)/2;
        _chmin(x,a,b,2*k,l,m); _chmin(x,a,b,2*k+1,m,r); pull(k);
    }
    void _chmax(ll x, int a, int b, int k, int l, int r) {
        if (b <= l || r <= a || x <= min_v[k]) return;
        if (a <= l && r <= b && x < smin_v[k]) { push_chmax(k, x); return; }
        push(k); int m = (l+r)/2;
        _chmax(x,a,b,2*k,l,m); _chmax(x,a,b,2*k+1,m,r); pull(k);
    }
    void _add(ll x, int a, int b, int k, int l, int r) {
        if (b <= l || r <= a) return;
        if (a <= l && r <= b) { addall(k, x); return; }
        push(k); int m = (l+r)/2;
        _add(x,a,b,2*k,l,m); _add(x,a,b,2*k+1,m,r); pull(k);
    }
    void _set(ll x, int a, int b, int k, int l, int r) {
        if (b <= l || r <= a) return;
        if (a <= l && r <= b) { setall(k, x); return; }
        push(k); int m = (l+r)/2;
        _set(x,a,b,2*k,l,m); _set(x,a,b,2*k+1,m,r); pull(k);
    }
    ll _qmax(int a, int b, int k, int l, int r) {
        if (b <= l || r <= a) return -LINF;
        if (a <= l && r <= b) return max_v[k];
        push(k); int m = (l+r)/2;
        return max(_qmax(a,b,2*k,l,m), _qmax(a,b,2*k+1,m,r));
    }
    ll _qmin(int a, int b, int k, int l, int r) {
        if (b <= l || r <= a) return LINF;
        if (a <= l && r <= b) return min_v[k];
        push(k); int m = (l+r)/2;
        return min(_qmin(a,b,2*k,l,m), _qmin(a,b,2*k+1,m,r));
    }
    ll _qsum(int a, int b, int k, int l, int r) {
        if (b <= l || r <= a) return 0;
        if (a <= l && r <= b) return sm[k];
        push(k); int m = (l+r)/2;
        return _qsum(a,b,2*k,l,m) + _qsum(a,b,2*k+1,m,r);
    }

    // ---- construction ----
    void _init(int n_, const ll* a) {
        n = n_; n0 = 1; while (n0 < n) n0 <<= 1;
        int sz2 = 2 * n0 + 2;
        max_v.assign(sz2, -LINF); smax_v.assign(sz2, -LINF); max_c.assign(sz2, 0);
        min_v.assign(sz2,  LINF); smin_v.assign(sz2,  LINF); min_c.assign(sz2, 0);
        sm.assign(sz2, 0); sz.assign(sz2, 0);
        ladd.assign(sz2, 0); lval.assign(sz2, LINF);
        // set sizes (sz[k] = number of REAL elements covered)
        // We need sz for addall/setall. Use len = 1 for each leaf.
        // sz at leaves: real leaves have sz=1, padding leaves have sz=0.
        // Propagate up.
        for (int i = n0; i < n0 + n; i++) sz[i] = 1;
        for (int i = n0 - 1; i >= 1; i--) sz[i] = sz[2*i] + sz[2*i+1];
        // Note: we also need sz for addall/setall at non-leaf nodes.
        // Actually, for addall we use sm[k] += sz[k] * x,
        // so sz[k] must count only real elements.
        // Initialize leaves
        for (int i = 0; i < n; i++) {
            int k = n0 + i;
            ll v = (a ? a[i] : 0LL);
            max_v[k] = smax_v[k] = min_v[k] = smin_v[k] = v;
            max_c[k] = min_c[k] = 1;
            sm[k] = v;
        }
        // padding leaves: already -LINF / LINF / count=0
        for (int i = n0 - 1; i >= 1; i--) pull(i);
    }

public:
    segment_beats() = default;
    segment_beats(int n, ll init_val = 0) {
        vector<ll> a(n, init_val);
        _init(n, a.data());
    }
    segment_beats(const vector<ll>& a) { _init((int)a.size(), a.data()); }

    // half-open intervals [l, r)
    void range_chmin(int l, int r, ll x) { _chmin(x, l, r, 1, 0, n0); }
    void range_chmax(int l, int r, ll x) { _chmax(x, l, r, 1, 0, n0); }
    void range_add  (int l, int r, ll x) { _add  (x, l, r, 1, 0, n0); }
    void range_set  (int l, int r, ll x) { _set  (x, l, r, 1, 0, n0); }
    ll query_max(int l, int r) { return _qmax(l, r, 1, 0, n0); }
    ll query_min(int l, int r) { return _qmin(l, r, 1, 0, n0); }
    ll query_sum(int l, int r) { return _qsum(l, r, 1, 0, n0); }
};
