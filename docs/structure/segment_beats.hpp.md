---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/library_checker_range_chmin_chmax_add_range_sum.test.cpp
    title: verify/library_checker_range_chmin_chmax_add_range_sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"structure/segment_beats.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n// Segment Beats (Ji Driver Segmentation)\n// Supports:\n\
    //   range chmin   : for i in [l,r), a[i] = min(a[i], v)\n//   range chmax   :\
    \ for i in [l,r), a[i] = max(a[i], v)\n//   range add     : for i in [l,r), a[i]\
    \ += v\n//   range sum     : sum of a[l..r)\n//   range min/max : min/max of a[l..r)\n\
    //\n// Amortized O((n + q) log^2 n) time.\n//\n// Reference: Ji (2016), \"Chtholly\
    \ Tree\" style lazy propagation.\n\nstruct segment_beats {\n    struct Node {\n\
    \        long long sum;\n        long long mx, mx2; int mxc;  // max, 2nd max,\
    \ count of max\n        long long mn, mn2; int mnc;  // min, 2nd min, count of\
    \ min\n        long long lazy_add;\n        long long lazy_chmin, lazy_chmax;\
    \ // pending clamp targets\n    };\n\n    int n;\n    vector<Node> t;\n\n    void\
    \ _init(Node& nd, long long v) {\n        nd.sum = v; nd.mx = v; nd.mx2 = LLONG_MIN;\
    \ nd.mxc = 1;\n        nd.mn = v; nd.mn2 = LLONG_MAX; nd.mnc = 1;\n        nd.lazy_add\
    \ = 0; nd.lazy_chmin = LLONG_MAX; nd.lazy_chmax = LLONG_MIN;\n    }\n\n    void\
    \ _pull(int v) {\n        auto &L = t[2*v], &R = t[2*v+1], &N = t[v];\n      \
    \  N.sum = L.sum + R.sum;\n        // max\n        if (L.mx == R.mx) { N.mx =\
    \ L.mx; N.mxc = L.mxc + R.mxc; N.mx2 = max(L.mx2, R.mx2); }\n        else if (L.mx\
    \ > R.mx) { N.mx = L.mx; N.mxc = L.mxc; N.mx2 = max(L.mx2, R.mx); }\n        else\
    \ { N.mx = R.mx; N.mxc = R.mxc; N.mx2 = max(L.mx, R.mx2); }\n        // min\n\
    \        if (L.mn == R.mn) { N.mn = L.mn; N.mnc = L.mnc + R.mnc; N.mn2 = min(L.mn2,\
    \ R.mn2); }\n        else if (L.mn < R.mn) { N.mn = L.mn; N.mnc = L.mnc; N.mn2\
    \ = min(L.mn2, R.mn); }\n        else { N.mn = R.mn; N.mnc = R.mnc; N.mn2 = min(L.mn,\
    \ R.mn2); }\n        N.lazy_add = 0; N.lazy_chmin = LLONG_MAX; N.lazy_chmax =\
    \ LLONG_MIN;\n    }\n\n    void _apply_add(int v, long long val) {\n        t[v].sum\
    \ += val * (/* node size */ 1); // corrected in _push\n        t[v].mx += val;\
    \ if (t[v].mx2 != LLONG_MIN) t[v].mx2 += val;\n        t[v].mn += val; if (t[v].mn2\
    \ != LLONG_MAX) t[v].mn2 += val;\n        if (t[v].lazy_chmin != LLONG_MAX) t[v].lazy_chmin\
    \ += val;\n        if (t[v].lazy_chmax != LLONG_MIN) t[v].lazy_chmax += val;\n\
    \        t[v].lazy_add += val;\n    }\n    void _apply_chmin(int v, long long\
    \ val) {\n        if (val >= t[v].mx) return;\n        t[v].sum -= (long long)(t[v].mx\
    \ - val) * t[v].mxc;\n        if (t[v].lazy_chmin != LLONG_MAX) t[v].lazy_chmin\
    \ = min(t[v].lazy_chmin, val);\n        else t[v].lazy_chmin = val;\n        t[v].mx\
    \ = val;\n    }\n    void _apply_chmax(int v, long long val) {\n        if (val\
    \ <= t[v].mn) return;\n        t[v].sum += (long long)(val - t[v].mn) * t[v].mnc;\n\
    \        if (t[v].lazy_chmax != LLONG_MIN) t[v].lazy_chmax = max(t[v].lazy_chmax,\
    \ val);\n        else t[v].lazy_chmax = val;\n        t[v].mn = val;\n    }\n\n\
    \    void _push(int v, int sz) {\n        int lsz = sz - sz / 2, rsz = sz / 2;\
    \ // left child size, right child size\n        // correct lazy_add to account\
    \ for node sizes\n        // Actually, we maintain sum correctly in apply; just\
    \ propagate lazy\n        if (t[v].lazy_add) {\n            t[2*v].sum   += t[v].lazy_add\
    \ * lsz;\n            t[2*v+1].sum += t[v].lazy_add * rsz;\n            _apply_add(2*v,\
    \   t[v].lazy_add); t[2*v].sum   -= t[v].lazy_add * lsz;   // undo overcounting\n\
    \            _apply_add(2*v+1, t[v].lazy_add); t[2*v+1].sum -= t[v].lazy_add *\
    \ rsz;\n            // Actually rewrite with proper size-aware apply\n       \
    \ }\n        // This simple approach has issues with sum tracking. Use size-aware\
    \ nodes:\n        // See the rewritten version below.\n        (void)v; (void)sz;\n\
    \    }\n\n    // --- Proper implementation with explicit size ---\n    // Rewrite\
    \ using sz stored in node.\n\n    struct Node2 {\n        long long sum, add;\n\
    \        long long mx, mx2, chmin; int mxcnt;\n        long long mn, mn2, chmax;\
    \ int mncnt;\n        int sz;\n    };\n    vector<Node2> nd;\n\n    void _build(int\
    \ v, int l, int r, const vector<long long>& a) {\n        nd[v].sz = r - l;\n\
    \        nd[v].add = 0; nd[v].chmin = LLONG_MAX; nd[v].chmax = LLONG_MIN;\n  \
    \      if (r - l == 1) {\n            nd[v].sum = a[l];\n            nd[v].mx\
    \ = nd[v].mn = a[l];\n            nd[v].mx2 = LLONG_MIN; nd[v].mxcnt = 1;\n  \
    \          nd[v].mn2 = LLONG_MAX; nd[v].mncnt = 1;\n            return;\n    \
    \    }\n        int m = (l + r) / 2;\n        _build(2*v, l, m, a); _build(2*v+1,\
    \ m, r, a);\n        _up(v);\n    }\n\n    void _up(int v) {\n        auto &L\
    \ = nd[2*v], &R = nd[2*v+1], &N = nd[v];\n        N.sum = L.sum + R.sum;\n   \
    \     if (L.mx == R.mx) { N.mx = L.mx; N.mxcnt = L.mxcnt + R.mxcnt; N.mx2 = max(L.mx2,\
    \ R.mx2); }\n        else if (L.mx > R.mx) { N.mx = L.mx; N.mxcnt = L.mxcnt; N.mx2\
    \ = max(L.mx2, R.mx); }\n        else { N.mx = R.mx; N.mxcnt = R.mxcnt; N.mx2\
    \ = max(L.mx, R.mx2); }\n        if (L.mn == R.mn) { N.mn = L.mn; N.mncnt = L.mncnt\
    \ + R.mncnt; N.mn2 = min(L.mn2, R.mn2); }\n        else if (L.mn < R.mn) { N.mn\
    \ = L.mn; N.mncnt = L.mncnt; N.mn2 = min(L.mn2, R.mn); }\n        else { N.mn\
    \ = R.mn; N.mncnt = R.mncnt; N.mn2 = min(L.mn, R.mn2); }\n    }\n\n    void _push_add(int\
    \ v, long long val) {\n        nd[v].sum += val * nd[v].sz;\n        nd[v].mx\
    \ += val; nd[v].mn += val;\n        if (nd[v].mx2 != LLONG_MIN) nd[v].mx2 += val;\n\
    \        if (nd[v].mn2 != LLONG_MAX) nd[v].mn2 += val;\n        if (nd[v].chmin\
    \ != LLONG_MAX) nd[v].chmin += val;\n        if (nd[v].chmax != LLONG_MIN) nd[v].chmax\
    \ += val;\n        nd[v].add += val;\n    }\n    void _push_chmin(int v, long\
    \ long val) {\n        if (val >= nd[v].mx) return;\n        nd[v].sum -= (nd[v].mx\
    \ - val) * nd[v].mxcnt;\n        nd[v].chmin = (nd[v].chmin != LLONG_MAX) ? min(nd[v].chmin,\
    \ val) : val;\n        nd[v].mx = val;\n    }\n    void _push_chmax(int v, long\
    \ long val) {\n        if (val <= nd[v].mn) return;\n        nd[v].sum += (val\
    \ - nd[v].mn) * nd[v].mncnt;\n        nd[v].chmax = (nd[v].chmax != LLONG_MIN)\
    \ ? max(nd[v].chmax, val) : val;\n        nd[v].mn = val;\n    }\n    void _pushdown(int\
    \ v) {\n        if (nd[v].add != 0) {\n            _push_add(2*v, nd[v].add);\
    \ _push_add(2*v+1, nd[v].add);\n            nd[v].add = 0;\n        }\n      \
    \  if (nd[v].chmin != LLONG_MAX) {\n            _push_chmin(2*v, nd[v].chmin);\
    \ _push_chmin(2*v+1, nd[v].chmin);\n            nd[v].chmin = LLONG_MAX;\n   \
    \     }\n        if (nd[v].chmax != LLONG_MIN) {\n            _push_chmax(2*v,\
    \ nd[v].chmax); _push_chmax(2*v+1, nd[v].chmax);\n            nd[v].chmax = LLONG_MIN;\n\
    \        }\n    }\n\n    // apply range add [l,r) += val, current node [nl,nr)\n\
    \    void _add(int v, int nl, int nr, int l, int r, long long val) {\n       \
    \ if (r <= nl || nr <= l) return;\n        if (l <= nl && nr <= r) { _push_add(v,\
    \ val); return; }\n        _pushdown(v); int m = (nl + nr) / 2;\n        _add(2*v,\
    \ nl, m, l, r, val); _add(2*v+1, m, nr, l, r, val); _up(v);\n    }\n    void _chmin(int\
    \ v, int nl, int nr, int l, int r, long long val) {\n        if (r <= nl || nr\
    \ <= l || val >= nd[v].mx) return;\n        if (l <= nl && nr <= r && val > nd[v].mx2)\
    \ { _push_chmin(v, val); return; }\n        _pushdown(v); int m = (nl + nr) /\
    \ 2;\n        _chmin(2*v, nl, m, l, r, val); _chmin(2*v+1, m, nr, l, r, val);\
    \ _up(v);\n    }\n    void _chmax(int v, int nl, int nr, int l, int r, long long\
    \ val) {\n        if (r <= nl || nr <= l || val <= nd[v].mn) return;\n       \
    \ if (l <= nl && nr <= r && val < nd[v].mn2) { _push_chmax(v, val); return; }\n\
    \        _pushdown(v); int m = (nl + nr) / 2;\n        _chmax(2*v, nl, m, l, r,\
    \ val); _chmax(2*v+1, m, nr, l, r, val); _up(v);\n    }\n    long long _query_sum(int\
    \ v, int nl, int nr, int l, int r) {\n        if (r <= nl || nr <= l) return 0;\n\
    \        if (l <= nl && nr <= r) return nd[v].sum;\n        _pushdown(v); int\
    \ m = (nl + nr) / 2;\n        return _query_sum(2*v, nl, m, l, r) + _query_sum(2*v+1,\
    \ m, nr, l, r);\n    }\n    long long _query_min(int v, int nl, int nr, int l,\
    \ int r) {\n        if (r <= nl || nr <= l) return LLONG_MAX;\n        if (l <=\
    \ nl && nr <= r) return nd[v].mn;\n        _pushdown(v); int m = (nl + nr) / 2;\n\
    \        return min(_query_min(2*v, nl, m, l, r), _query_min(2*v+1, m, nr, l,\
    \ r));\n    }\n    long long _query_max(int v, int nl, int nr, int l, int r) {\n\
    \        if (r <= nl || nr <= l) return LLONG_MIN;\n        if (l <= nl && nr\
    \ <= r) return nd[v].mx;\n        _pushdown(v); int m = (nl + nr) / 2;\n     \
    \   return max(_query_max(2*v, nl, m, l, r), _query_max(2*v+1, m, nr, l, r));\n\
    \    }\n\npublic:\n    segment_beats() = default;\n    segment_beats(int n, long\
    \ long init_val = 0)\n        : n(n), nd(4 * n) {\n        vector<long long> a(n,\
    \ init_val);\n        _build(1, 0, n, a);\n    }\n    segment_beats(const vector<long\
    \ long>& a)\n        : n(a.size()), nd(4 * a.size()) {\n        _build(1, 0, n,\
    \ a);\n    }\n\n    void range_add  (int l, int r, long long v) { _add  (1, 0,\
    \ n, l, r, v); }\n    void range_chmin(int l, int r, long long v) { _chmin(1,\
    \ 0, n, l, r, v); }\n    void range_chmax(int l, int r, long long v) { _chmax(1,\
    \ 0, n, l, r, v); }\n\n    long long query_sum(int l, int r) { return _query_sum(1,\
    \ 0, n, l, r); }\n    long long query_min(int l, int r) { return _query_min(1,\
    \ 0, n, l, r); }\n    long long query_max(int l, int r) { return _query_max(1,\
    \ 0, n, l, r); }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n// Segment\
    \ Beats (Ji Driver Segmentation)\n// Supports:\n//   range chmin   : for i in\
    \ [l,r), a[i] = min(a[i], v)\n//   range chmax   : for i in [l,r), a[i] = max(a[i],\
    \ v)\n//   range add     : for i in [l,r), a[i] += v\n//   range sum     : sum\
    \ of a[l..r)\n//   range min/max : min/max of a[l..r)\n//\n// Amortized O((n +\
    \ q) log^2 n) time.\n//\n// Reference: Ji (2016), \"Chtholly Tree\" style lazy\
    \ propagation.\n\nstruct segment_beats {\n    struct Node {\n        long long\
    \ sum;\n        long long mx, mx2; int mxc;  // max, 2nd max, count of max\n \
    \       long long mn, mn2; int mnc;  // min, 2nd min, count of min\n        long\
    \ long lazy_add;\n        long long lazy_chmin, lazy_chmax; // pending clamp targets\n\
    \    };\n\n    int n;\n    vector<Node> t;\n\n    void _init(Node& nd, long long\
    \ v) {\n        nd.sum = v; nd.mx = v; nd.mx2 = LLONG_MIN; nd.mxc = 1;\n     \
    \   nd.mn = v; nd.mn2 = LLONG_MAX; nd.mnc = 1;\n        nd.lazy_add = 0; nd.lazy_chmin\
    \ = LLONG_MAX; nd.lazy_chmax = LLONG_MIN;\n    }\n\n    void _pull(int v) {\n\
    \        auto &L = t[2*v], &R = t[2*v+1], &N = t[v];\n        N.sum = L.sum +\
    \ R.sum;\n        // max\n        if (L.mx == R.mx) { N.mx = L.mx; N.mxc = L.mxc\
    \ + R.mxc; N.mx2 = max(L.mx2, R.mx2); }\n        else if (L.mx > R.mx) { N.mx\
    \ = L.mx; N.mxc = L.mxc; N.mx2 = max(L.mx2, R.mx); }\n        else { N.mx = R.mx;\
    \ N.mxc = R.mxc; N.mx2 = max(L.mx, R.mx2); }\n        // min\n        if (L.mn\
    \ == R.mn) { N.mn = L.mn; N.mnc = L.mnc + R.mnc; N.mn2 = min(L.mn2, R.mn2); }\n\
    \        else if (L.mn < R.mn) { N.mn = L.mn; N.mnc = L.mnc; N.mn2 = min(L.mn2,\
    \ R.mn); }\n        else { N.mn = R.mn; N.mnc = R.mnc; N.mn2 = min(L.mn, R.mn2);\
    \ }\n        N.lazy_add = 0; N.lazy_chmin = LLONG_MAX; N.lazy_chmax = LLONG_MIN;\n\
    \    }\n\n    void _apply_add(int v, long long val) {\n        t[v].sum += val\
    \ * (/* node size */ 1); // corrected in _push\n        t[v].mx += val; if (t[v].mx2\
    \ != LLONG_MIN) t[v].mx2 += val;\n        t[v].mn += val; if (t[v].mn2 != LLONG_MAX)\
    \ t[v].mn2 += val;\n        if (t[v].lazy_chmin != LLONG_MAX) t[v].lazy_chmin\
    \ += val;\n        if (t[v].lazy_chmax != LLONG_MIN) t[v].lazy_chmax += val;\n\
    \        t[v].lazy_add += val;\n    }\n    void _apply_chmin(int v, long long\
    \ val) {\n        if (val >= t[v].mx) return;\n        t[v].sum -= (long long)(t[v].mx\
    \ - val) * t[v].mxc;\n        if (t[v].lazy_chmin != LLONG_MAX) t[v].lazy_chmin\
    \ = min(t[v].lazy_chmin, val);\n        else t[v].lazy_chmin = val;\n        t[v].mx\
    \ = val;\n    }\n    void _apply_chmax(int v, long long val) {\n        if (val\
    \ <= t[v].mn) return;\n        t[v].sum += (long long)(val - t[v].mn) * t[v].mnc;\n\
    \        if (t[v].lazy_chmax != LLONG_MIN) t[v].lazy_chmax = max(t[v].lazy_chmax,\
    \ val);\n        else t[v].lazy_chmax = val;\n        t[v].mn = val;\n    }\n\n\
    \    void _push(int v, int sz) {\n        int lsz = sz - sz / 2, rsz = sz / 2;\
    \ // left child size, right child size\n        // correct lazy_add to account\
    \ for node sizes\n        // Actually, we maintain sum correctly in apply; just\
    \ propagate lazy\n        if (t[v].lazy_add) {\n            t[2*v].sum   += t[v].lazy_add\
    \ * lsz;\n            t[2*v+1].sum += t[v].lazy_add * rsz;\n            _apply_add(2*v,\
    \   t[v].lazy_add); t[2*v].sum   -= t[v].lazy_add * lsz;   // undo overcounting\n\
    \            _apply_add(2*v+1, t[v].lazy_add); t[2*v+1].sum -= t[v].lazy_add *\
    \ rsz;\n            // Actually rewrite with proper size-aware apply\n       \
    \ }\n        // This simple approach has issues with sum tracking. Use size-aware\
    \ nodes:\n        // See the rewritten version below.\n        (void)v; (void)sz;\n\
    \    }\n\n    // --- Proper implementation with explicit size ---\n    // Rewrite\
    \ using sz stored in node.\n\n    struct Node2 {\n        long long sum, add;\n\
    \        long long mx, mx2, chmin; int mxcnt;\n        long long mn, mn2, chmax;\
    \ int mncnt;\n        int sz;\n    };\n    vector<Node2> nd;\n\n    void _build(int\
    \ v, int l, int r, const vector<long long>& a) {\n        nd[v].sz = r - l;\n\
    \        nd[v].add = 0; nd[v].chmin = LLONG_MAX; nd[v].chmax = LLONG_MIN;\n  \
    \      if (r - l == 1) {\n            nd[v].sum = a[l];\n            nd[v].mx\
    \ = nd[v].mn = a[l];\n            nd[v].mx2 = LLONG_MIN; nd[v].mxcnt = 1;\n  \
    \          nd[v].mn2 = LLONG_MAX; nd[v].mncnt = 1;\n            return;\n    \
    \    }\n        int m = (l + r) / 2;\n        _build(2*v, l, m, a); _build(2*v+1,\
    \ m, r, a);\n        _up(v);\n    }\n\n    void _up(int v) {\n        auto &L\
    \ = nd[2*v], &R = nd[2*v+1], &N = nd[v];\n        N.sum = L.sum + R.sum;\n   \
    \     if (L.mx == R.mx) { N.mx = L.mx; N.mxcnt = L.mxcnt + R.mxcnt; N.mx2 = max(L.mx2,\
    \ R.mx2); }\n        else if (L.mx > R.mx) { N.mx = L.mx; N.mxcnt = L.mxcnt; N.mx2\
    \ = max(L.mx2, R.mx); }\n        else { N.mx = R.mx; N.mxcnt = R.mxcnt; N.mx2\
    \ = max(L.mx, R.mx2); }\n        if (L.mn == R.mn) { N.mn = L.mn; N.mncnt = L.mncnt\
    \ + R.mncnt; N.mn2 = min(L.mn2, R.mn2); }\n        else if (L.mn < R.mn) { N.mn\
    \ = L.mn; N.mncnt = L.mncnt; N.mn2 = min(L.mn2, R.mn); }\n        else { N.mn\
    \ = R.mn; N.mncnt = R.mncnt; N.mn2 = min(L.mn, R.mn2); }\n    }\n\n    void _push_add(int\
    \ v, long long val) {\n        nd[v].sum += val * nd[v].sz;\n        nd[v].mx\
    \ += val; nd[v].mn += val;\n        if (nd[v].mx2 != LLONG_MIN) nd[v].mx2 += val;\n\
    \        if (nd[v].mn2 != LLONG_MAX) nd[v].mn2 += val;\n        if (nd[v].chmin\
    \ != LLONG_MAX) nd[v].chmin += val;\n        if (nd[v].chmax != LLONG_MIN) nd[v].chmax\
    \ += val;\n        nd[v].add += val;\n    }\n    void _push_chmin(int v, long\
    \ long val) {\n        if (val >= nd[v].mx) return;\n        nd[v].sum -= (nd[v].mx\
    \ - val) * nd[v].mxcnt;\n        nd[v].chmin = (nd[v].chmin != LLONG_MAX) ? min(nd[v].chmin,\
    \ val) : val;\n        nd[v].mx = val;\n    }\n    void _push_chmax(int v, long\
    \ long val) {\n        if (val <= nd[v].mn) return;\n        nd[v].sum += (val\
    \ - nd[v].mn) * nd[v].mncnt;\n        nd[v].chmax = (nd[v].chmax != LLONG_MIN)\
    \ ? max(nd[v].chmax, val) : val;\n        nd[v].mn = val;\n    }\n    void _pushdown(int\
    \ v) {\n        if (nd[v].add != 0) {\n            _push_add(2*v, nd[v].add);\
    \ _push_add(2*v+1, nd[v].add);\n            nd[v].add = 0;\n        }\n      \
    \  if (nd[v].chmin != LLONG_MAX) {\n            _push_chmin(2*v, nd[v].chmin);\
    \ _push_chmin(2*v+1, nd[v].chmin);\n            nd[v].chmin = LLONG_MAX;\n   \
    \     }\n        if (nd[v].chmax != LLONG_MIN) {\n            _push_chmax(2*v,\
    \ nd[v].chmax); _push_chmax(2*v+1, nd[v].chmax);\n            nd[v].chmax = LLONG_MIN;\n\
    \        }\n    }\n\n    // apply range add [l,r) += val, current node [nl,nr)\n\
    \    void _add(int v, int nl, int nr, int l, int r, long long val) {\n       \
    \ if (r <= nl || nr <= l) return;\n        if (l <= nl && nr <= r) { _push_add(v,\
    \ val); return; }\n        _pushdown(v); int m = (nl + nr) / 2;\n        _add(2*v,\
    \ nl, m, l, r, val); _add(2*v+1, m, nr, l, r, val); _up(v);\n    }\n    void _chmin(int\
    \ v, int nl, int nr, int l, int r, long long val) {\n        if (r <= nl || nr\
    \ <= l || val >= nd[v].mx) return;\n        if (l <= nl && nr <= r && val > nd[v].mx2)\
    \ { _push_chmin(v, val); return; }\n        _pushdown(v); int m = (nl + nr) /\
    \ 2;\n        _chmin(2*v, nl, m, l, r, val); _chmin(2*v+1, m, nr, l, r, val);\
    \ _up(v);\n    }\n    void _chmax(int v, int nl, int nr, int l, int r, long long\
    \ val) {\n        if (r <= nl || nr <= l || val <= nd[v].mn) return;\n       \
    \ if (l <= nl && nr <= r && val < nd[v].mn2) { _push_chmax(v, val); return; }\n\
    \        _pushdown(v); int m = (nl + nr) / 2;\n        _chmax(2*v, nl, m, l, r,\
    \ val); _chmax(2*v+1, m, nr, l, r, val); _up(v);\n    }\n    long long _query_sum(int\
    \ v, int nl, int nr, int l, int r) {\n        if (r <= nl || nr <= l) return 0;\n\
    \        if (l <= nl && nr <= r) return nd[v].sum;\n        _pushdown(v); int\
    \ m = (nl + nr) / 2;\n        return _query_sum(2*v, nl, m, l, r) + _query_sum(2*v+1,\
    \ m, nr, l, r);\n    }\n    long long _query_min(int v, int nl, int nr, int l,\
    \ int r) {\n        if (r <= nl || nr <= l) return LLONG_MAX;\n        if (l <=\
    \ nl && nr <= r) return nd[v].mn;\n        _pushdown(v); int m = (nl + nr) / 2;\n\
    \        return min(_query_min(2*v, nl, m, l, r), _query_min(2*v+1, m, nr, l,\
    \ r));\n    }\n    long long _query_max(int v, int nl, int nr, int l, int r) {\n\
    \        if (r <= nl || nr <= l) return LLONG_MIN;\n        if (l <= nl && nr\
    \ <= r) return nd[v].mx;\n        _pushdown(v); int m = (nl + nr) / 2;\n     \
    \   return max(_query_max(2*v, nl, m, l, r), _query_max(2*v+1, m, nr, l, r));\n\
    \    }\n\npublic:\n    segment_beats() = default;\n    segment_beats(int n, long\
    \ long init_val = 0)\n        : n(n), nd(4 * n) {\n        vector<long long> a(n,\
    \ init_val);\n        _build(1, 0, n, a);\n    }\n    segment_beats(const vector<long\
    \ long>& a)\n        : n(a.size()), nd(4 * a.size()) {\n        _build(1, 0, n,\
    \ a);\n    }\n\n    void range_add  (int l, int r, long long v) { _add  (1, 0,\
    \ n, l, r, v); }\n    void range_chmin(int l, int r, long long v) { _chmin(1,\
    \ 0, n, l, r, v); }\n    void range_chmax(int l, int r, long long v) { _chmax(1,\
    \ 0, n, l, r, v); }\n\n    long long query_sum(int l, int r) { return _query_sum(1,\
    \ 0, n, l, r); }\n    long long query_min(int l, int r) { return _query_min(1,\
    \ 0, n, l, r); }\n    long long query_max(int l, int r) { return _query_max(1,\
    \ 0, n, l, r); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/segment_beats.hpp
  requiredBy: []
  timestamp: '2026-03-09 22:49:24+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/library_checker_range_chmin_chmax_add_range_sum.test.cpp
documentation_of: structure/segment_beats.hpp
layout: document
redirect_from:
- /library/structure/segment_beats.hpp
- /library/structure/segment_beats.hpp.html
title: structure/segment_beats.hpp
---
