#pragma once
#include <bits/stdc++.h>
using namespace std;

// Segment Beats (Ji Driver Segmentation)
// Supports:
//   range chmin   : for i in [l,r), a[i] = min(a[i], v)
//   range chmax   : for i in [l,r), a[i] = max(a[i], v)
//   range add     : for i in [l,r), a[i] += v
//   range sum     : sum of a[l..r)
//   range min/max : min/max of a[l..r)
//
// Amortized O((n + q) log^2 n) time.
//
// Reference: Ji (2016), "Chtholly Tree" style lazy propagation.

struct segment_beats {
    struct Node {
        long long sum;
        long long mx, mx2; int mxc;  // max, 2nd max, count of max
        long long mn, mn2; int mnc;  // min, 2nd min, count of min
        long long lazy_add;
        long long lazy_chmin, lazy_chmax; // pending clamp targets
    };

    int n;
    vector<Node> t;

    void _init(Node& nd, long long v) {
        nd.sum = v; nd.mx = v; nd.mx2 = LLONG_MIN; nd.mxc = 1;
        nd.mn = v; nd.mn2 = LLONG_MAX; nd.mnc = 1;
        nd.lazy_add = 0; nd.lazy_chmin = LLONG_MAX; nd.lazy_chmax = LLONG_MIN;
    }

    void _pull(int v) {
        auto &L = t[2*v], &R = t[2*v+1], &N = t[v];
        N.sum = L.sum + R.sum;
        // max
        if (L.mx == R.mx) { N.mx = L.mx; N.mxc = L.mxc + R.mxc; N.mx2 = max(L.mx2, R.mx2); }
        else if (L.mx > R.mx) { N.mx = L.mx; N.mxc = L.mxc; N.mx2 = max(L.mx2, R.mx); }
        else { N.mx = R.mx; N.mxc = R.mxc; N.mx2 = max(L.mx, R.mx2); }
        // min
        if (L.mn == R.mn) { N.mn = L.mn; N.mnc = L.mnc + R.mnc; N.mn2 = min(L.mn2, R.mn2); }
        else if (L.mn < R.mn) { N.mn = L.mn; N.mnc = L.mnc; N.mn2 = min(L.mn2, R.mn); }
        else { N.mn = R.mn; N.mnc = R.mnc; N.mn2 = min(L.mn, R.mn2); }
        N.lazy_add = 0; N.lazy_chmin = LLONG_MAX; N.lazy_chmax = LLONG_MIN;
    }

    void _apply_add(int v, long long val) {
        t[v].sum += val * (/* node size */ 1); // corrected in _push
        t[v].mx += val; if (t[v].mx2 != LLONG_MIN) t[v].mx2 += val;
        t[v].mn += val; if (t[v].mn2 != LLONG_MAX) t[v].mn2 += val;
        if (t[v].lazy_chmin != LLONG_MAX) t[v].lazy_chmin += val;
        if (t[v].lazy_chmax != LLONG_MIN) t[v].lazy_chmax += val;
        t[v].lazy_add += val;
    }
    void _apply_chmin(int v, long long val) {
        if (val >= t[v].mx) return;
        t[v].sum -= (long long)(t[v].mx - val) * t[v].mxc;
        if (t[v].lazy_chmin != LLONG_MAX) t[v].lazy_chmin = min(t[v].lazy_chmin, val);
        else t[v].lazy_chmin = val;
        t[v].mx = val;
    }
    void _apply_chmax(int v, long long val) {
        if (val <= t[v].mn) return;
        t[v].sum += (long long)(val - t[v].mn) * t[v].mnc;
        if (t[v].lazy_chmax != LLONG_MIN) t[v].lazy_chmax = max(t[v].lazy_chmax, val);
        else t[v].lazy_chmax = val;
        t[v].mn = val;
    }

    void _push(int v, int sz) {
        int lsz = sz - sz / 2, rsz = sz / 2; // left child size, right child size
        // correct lazy_add to account for node sizes
        // Actually, we maintain sum correctly in apply; just propagate lazy
        if (t[v].lazy_add) {
            t[2*v].sum   += t[v].lazy_add * lsz;
            t[2*v+1].sum += t[v].lazy_add * rsz;
            _apply_add(2*v,   t[v].lazy_add); t[2*v].sum   -= t[v].lazy_add * lsz;   // undo overcounting
            _apply_add(2*v+1, t[v].lazy_add); t[2*v+1].sum -= t[v].lazy_add * rsz;
            // Actually rewrite with proper size-aware apply
        }
        // This simple approach has issues with sum tracking. Use size-aware nodes:
        // See the rewritten version below.
        (void)v; (void)sz;
    }

    // --- Proper implementation with explicit size ---
    // Rewrite using sz stored in node.

    struct Node2 {
        long long sum, add;
        long long mx, mx2, chmin; int mxcnt;
        long long mn, mn2, chmax; int mncnt;
        int sz;
    };
    vector<Node2> nd;

    void _build(int v, int l, int r, const vector<long long>& a) {
        nd[v].sz = r - l;
        nd[v].add = 0; nd[v].chmin = LLONG_MAX; nd[v].chmax = LLONG_MIN;
        if (r - l == 1) {
            nd[v].sum = a[l];
            nd[v].mx = nd[v].mn = a[l];
            nd[v].mx2 = LLONG_MIN; nd[v].mxcnt = 1;
            nd[v].mn2 = LLONG_MAX; nd[v].mncnt = 1;
            return;
        }
        int m = (l + r) / 2;
        _build(2*v, l, m, a); _build(2*v+1, m, r, a);
        _up(v);
    }

    void _up(int v) {
        auto &L = nd[2*v], &R = nd[2*v+1], &N = nd[v];
        N.sum = L.sum + R.sum;
        if (L.mx == R.mx) { N.mx = L.mx; N.mxcnt = L.mxcnt + R.mxcnt; N.mx2 = max(L.mx2, R.mx2); }
        else if (L.mx > R.mx) { N.mx = L.mx; N.mxcnt = L.mxcnt; N.mx2 = max(L.mx2, R.mx); }
        else { N.mx = R.mx; N.mxcnt = R.mxcnt; N.mx2 = max(L.mx, R.mx2); }
        if (L.mn == R.mn) { N.mn = L.mn; N.mncnt = L.mncnt + R.mncnt; N.mn2 = min(L.mn2, R.mn2); }
        else if (L.mn < R.mn) { N.mn = L.mn; N.mncnt = L.mncnt; N.mn2 = min(L.mn2, R.mn); }
        else { N.mn = R.mn; N.mncnt = R.mncnt; N.mn2 = min(L.mn, R.mn2); }
    }

    void _push_add(int v, long long val) {
        nd[v].sum += val * nd[v].sz;
        nd[v].mx += val; nd[v].mn += val;
        if (nd[v].mx2 != LLONG_MIN) nd[v].mx2 += val;
        if (nd[v].mn2 != LLONG_MAX) nd[v].mn2 += val;
        if (nd[v].chmin != LLONG_MAX) nd[v].chmin += val;
        if (nd[v].chmax != LLONG_MIN) nd[v].chmax += val;
        nd[v].add += val;
    }
    void _push_chmin(int v, long long val) {
        if (val >= nd[v].mx) return;
        nd[v].sum -= (nd[v].mx - val) * nd[v].mxcnt;
        nd[v].chmin = (nd[v].chmin != LLONG_MAX) ? min(nd[v].chmin, val) : val;
        nd[v].mx = val;
    }
    void _push_chmax(int v, long long val) {
        if (val <= nd[v].mn) return;
        nd[v].sum += (val - nd[v].mn) * nd[v].mncnt;
        nd[v].chmax = (nd[v].chmax != LLONG_MIN) ? max(nd[v].chmax, val) : val;
        nd[v].mn = val;
    }
    void _pushdown(int v) {
        if (nd[v].add != 0) {
            _push_add(2*v, nd[v].add); _push_add(2*v+1, nd[v].add);
            nd[v].add = 0;
        }
        if (nd[v].chmin != LLONG_MAX) {
            _push_chmin(2*v, nd[v].chmin); _push_chmin(2*v+1, nd[v].chmin);
            nd[v].chmin = LLONG_MAX;
        }
        if (nd[v].chmax != LLONG_MIN) {
            _push_chmax(2*v, nd[v].chmax); _push_chmax(2*v+1, nd[v].chmax);
            nd[v].chmax = LLONG_MIN;
        }
    }

    // apply range add [l,r) += val, current node [nl,nr)
    void _add(int v, int nl, int nr, int l, int r, long long val) {
        if (r <= nl || nr <= l) return;
        if (l <= nl && nr <= r) { _push_add(v, val); return; }
        _pushdown(v); int m = (nl + nr) / 2;
        _add(2*v, nl, m, l, r, val); _add(2*v+1, m, nr, l, r, val); _up(v);
    }
    void _chmin(int v, int nl, int nr, int l, int r, long long val) {
        if (r <= nl || nr <= l || val >= nd[v].mx) return;
        if (l <= nl && nr <= r && val > nd[v].mx2) { _push_chmin(v, val); return; }
        _pushdown(v); int m = (nl + nr) / 2;
        _chmin(2*v, nl, m, l, r, val); _chmin(2*v+1, m, nr, l, r, val); _up(v);
    }
    void _chmax(int v, int nl, int nr, int l, int r, long long val) {
        if (r <= nl || nr <= l || val <= nd[v].mn) return;
        if (l <= nl && nr <= r && val < nd[v].mn2) { _push_chmax(v, val); return; }
        _pushdown(v); int m = (nl + nr) / 2;
        _chmax(2*v, nl, m, l, r, val); _chmax(2*v+1, m, nr, l, r, val); _up(v);
    }
    long long _query_sum(int v, int nl, int nr, int l, int r) {
        if (r <= nl || nr <= l) return 0;
        if (l <= nl && nr <= r) return nd[v].sum;
        _pushdown(v); int m = (nl + nr) / 2;
        return _query_sum(2*v, nl, m, l, r) + _query_sum(2*v+1, m, nr, l, r);
    }
    long long _query_min(int v, int nl, int nr, int l, int r) {
        if (r <= nl || nr <= l) return LLONG_MAX;
        if (l <= nl && nr <= r) return nd[v].mn;
        _pushdown(v); int m = (nl + nr) / 2;
        return min(_query_min(2*v, nl, m, l, r), _query_min(2*v+1, m, nr, l, r));
    }
    long long _query_max(int v, int nl, int nr, int l, int r) {
        if (r <= nl || nr <= l) return LLONG_MIN;
        if (l <= nl && nr <= r) return nd[v].mx;
        _pushdown(v); int m = (nl + nr) / 2;
        return max(_query_max(2*v, nl, m, l, r), _query_max(2*v+1, m, nr, l, r));
    }

public:
    segment_beats() = default;
    segment_beats(int n, long long init_val = 0)
        : n(n), nd(4 * n) {
        vector<long long> a(n, init_val);
        _build(1, 0, n, a);
    }
    segment_beats(const vector<long long>& a)
        : n(a.size()), nd(4 * a.size()) {
        _build(1, 0, n, a);
    }

    void range_add  (int l, int r, long long v) { _add  (1, 0, n, l, r, v); }
    void range_chmin(int l, int r, long long v) { _chmin(1, 0, n, l, r, v); }
    void range_chmax(int l, int r, long long v) { _chmax(1, 0, n, l, r, v); }

    long long query_sum(int l, int r) { return _query_sum(1, 0, n, l, r); }
    long long query_min(int l, int r) { return _query_min(1, 0, n, l, r); }
    long long query_max(int l, int r) { return _query_max(1, 0, n, l, r); }
};
