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
    links:
    - https://tjkendev.github.io/procon-library/cpp/range_query/segment_tree_beats_2.html
  bundledCode: "#line 2 \"structure/segment_beats.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n// Segment Beats (Ji Driver Segmentation)\n// Supports\
    \ (all queries half-open [l, r)):\n//   range_chmin(l, r, x) : a[i] = min(a[i],\
    \ x)\n//   range_chmax(l, r, x) : a[i] = max(a[i], x)\n//   range_add  (l, r,\
    \ x) : a[i] += x\n//   range_set  (l, r, x) : a[i] = x\n//   query_max  (l, r)\
    \    : max of a[l..r)\n//   query_min  (l, r)    : min of a[l..r)\n//   query_sum\
    \  (l, r)    : sum of a[l..r)\n//\n// Amortized O((n + q) log^2 n).\n// Reference:\
    \ https://tjkendev.github.io/procon-library/cpp/range_query/segment_tree_beats_2.html\n\
    \nstruct segment_beats {\n    using ll = long long;\n    static constexpr ll LINF\
    \ = 2e18;\n\n    int n, n0;\n    // max_v, smax_v: max value, strict 2nd-max value\
    \ (-LINF if none)\n    // min_v, smin_v: min value, strict 2nd-min value (+LINF\
    \ if none)\n    vector<ll> max_v, smax_v, min_v, smin_v, sm, sz, ladd, lval;\n\
    \    vector<int> max_c, min_c;\n\n    // ---- leaf/node modifiers ----\n    //\
    \ addall: add x to every element of node k\n    void addall(int k, ll x) {\n \
    \       max_v[k] += x;\n        if (smax_v[k] != -LINF) smax_v[k] += x;\n    \
    \    min_v[k] += x;\n        if (smin_v[k] !=  LINF) smin_v[k] += x;\n       \
    \ sm[k] += sz[k] * x;\n        if (lval[k] != LINF) lval[k] += x;\n        else\
    \                 ladd[k] += x;\n    }\n    // setall: set every element of node\
    \ k to x\n    void setall(int k, ll x) {\n        max_v[k] = smax_v[k] = min_v[k]\
    \ = smin_v[k] = x;\n        max_c[k] = min_c[k] = (int)sz[k];\n        sm[k] =\
    \ sz[k] * x;\n        lval[k] = x; ladd[k] = 0;\n    }\n    // push_chmin: apply\
    \ chmin(x) to node k, reducing its current max to x\n    //   precondition: smax_v[k]\
    \ < x < max_v[k]\n    void push_chmin(int k, ll x) {\n        sm[k] -= (max_v[k]\
    \ - x) * max_c[k];\n        if (max_v[k] == min_v[k]) min_v[k] = x;\n        if\
    \ (max_v[k] == smin_v[k]) smin_v[k] = x;\n        max_v[k] = x;\n        if (lval[k]\
    \ != LINF && lval[k] > x) lval[k] = x;\n    }\n    // push_chmax: apply chmax(x)\
    \ to node k, raising its current min to x\n    //   precondition: smin_v[k] >\
    \ x > min_v[k]\n    void push_chmax(int k, ll x) {\n        sm[k] += (x - min_v[k])\
    \ * min_c[k];\n        if (max_v[k] == min_v[k]) max_v[k] = x;\n        if (smax_v[k]\
    \ == min_v[k]) smax_v[k] = x;\n        min_v[k] = x;\n        if (lval[k] != LINF\
    \ && lval[k] < x) lval[k] = x;\n    }\n\n    // pull: recompute node k from its\
    \ children\n    void pull(int k) {\n        int l = 2*k, r = 2*k+1;\n        sm[k]\
    \ = sm[l] + sm[r];\n        // max info\n        if      (max_v[l] < max_v[r])\
    \ { max_v[k]=max_v[r]; max_c[k]=max_c[r]; smax_v[k]=max(max_v[l], smax_v[r]);\
    \ }\n        else if (max_v[l] > max_v[r]) { max_v[k]=max_v[l]; max_c[k]=max_c[l];\
    \ smax_v[k]=max(smax_v[l], max_v[r]); }\n        else                        \
    \  { max_v[k]=max_v[l]; max_c[k]=max_c[l]+max_c[r]; smax_v[k]=max(smax_v[l], smax_v[r]);\
    \ }\n        // min info\n        if      (min_v[l] < min_v[r]) { min_v[k]=min_v[l];\
    \ min_c[k]=min_c[l]; smin_v[k]=min(smin_v[l], min_v[r]); }\n        else if (min_v[l]\
    \ > min_v[r]) { min_v[k]=min_v[r]; min_c[k]=min_c[r]; smin_v[k]=min(min_v[l],\
    \ smin_v[r]); }\n        else                          { min_v[k]=min_v[l]; min_c[k]=min_c[l]+min_c[r];\
    \ smin_v[k]=min(smin_v[l], smin_v[r]); }\n    }\n\n    // push: propagate lazy\
    \ values to children\n    void push(int k) {\n        if (k >= n0) return;  //\
    \ leaf: nothing to push\n        if (lval[k] != LINF) {\n            setall(2*k,\
    \ lval[k]); setall(2*k+1, lval[k]);\n            lval[k] = LINF; ladd[k] = 0;\n\
    \            return;\n        }\n        if (ladd[k] != 0) {\n            addall(2*k,\
    \ ladd[k]); addall(2*k+1, ladd[k]);\n            ladd[k] = 0;\n        }\n   \
    \     // propagate chmin / chmax bounds\n        if (max_v[k] < max_v[2*k])  \
    \ push_chmin(2*k,   max_v[k]);\n        if (min_v[2*k] < min_v[k])   push_chmax(2*k,\
    \   min_v[k]);\n        if (max_v[k] < max_v[2*k+1]) push_chmin(2*k+1, max_v[k]);\n\
    \        if (min_v[2*k+1] < min_v[k]) push_chmax(2*k+1, min_v[k]);\n    }\n\n\
    \    // ---- range operations ----\n    void _chmin(ll x, int a, int b, int k,\
    \ int l, int r) {\n        if (b <= l || r <= a || max_v[k] <= x) return;\n  \
    \      if (a <= l && r <= b && smax_v[k] < x) { push_chmin(k, x); return; }\n\
    \        push(k); int m = (l+r)/2;\n        _chmin(x,a,b,2*k,l,m); _chmin(x,a,b,2*k+1,m,r);\
    \ pull(k);\n    }\n    void _chmax(ll x, int a, int b, int k, int l, int r) {\n\
    \        if (b <= l || r <= a || x <= min_v[k]) return;\n        if (a <= l &&\
    \ r <= b && x < smin_v[k]) { push_chmax(k, x); return; }\n        push(k); int\
    \ m = (l+r)/2;\n        _chmax(x,a,b,2*k,l,m); _chmax(x,a,b,2*k+1,m,r); pull(k);\n\
    \    }\n    void _add(ll x, int a, int b, int k, int l, int r) {\n        if (b\
    \ <= l || r <= a) return;\n        if (a <= l && r <= b) { addall(k, x); return;\
    \ }\n        push(k); int m = (l+r)/2;\n        _add(x,a,b,2*k,l,m); _add(x,a,b,2*k+1,m,r);\
    \ pull(k);\n    }\n    void _set(ll x, int a, int b, int k, int l, int r) {\n\
    \        if (b <= l || r <= a) return;\n        if (a <= l && r <= b) { setall(k,\
    \ x); return; }\n        push(k); int m = (l+r)/2;\n        _set(x,a,b,2*k,l,m);\
    \ _set(x,a,b,2*k+1,m,r); pull(k);\n    }\n    ll _qmax(int a, int b, int k, int\
    \ l, int r) {\n        if (b <= l || r <= a) return -LINF;\n        if (a <= l\
    \ && r <= b) return max_v[k];\n        push(k); int m = (l+r)/2;\n        return\
    \ max(_qmax(a,b,2*k,l,m), _qmax(a,b,2*k+1,m,r));\n    }\n    ll _qmin(int a, int\
    \ b, int k, int l, int r) {\n        if (b <= l || r <= a) return LINF;\n    \
    \    if (a <= l && r <= b) return min_v[k];\n        push(k); int m = (l+r)/2;\n\
    \        return min(_qmin(a,b,2*k,l,m), _qmin(a,b,2*k+1,m,r));\n    }\n    ll\
    \ _qsum(int a, int b, int k, int l, int r) {\n        if (b <= l || r <= a) return\
    \ 0;\n        if (a <= l && r <= b) return sm[k];\n        push(k); int m = (l+r)/2;\n\
    \        return _qsum(a,b,2*k,l,m) + _qsum(a,b,2*k+1,m,r);\n    }\n\n    // ----\
    \ construction ----\n    void _init(int n_, const ll* a) {\n        n = n_; n0\
    \ = 1; while (n0 < n) n0 <<= 1;\n        int sz2 = 2 * n0 + 2;\n        max_v.assign(sz2,\
    \ -LINF); smax_v.assign(sz2, -LINF); max_c.assign(sz2, 0);\n        min_v.assign(sz2,\
    \  LINF); smin_v.assign(sz2,  LINF); min_c.assign(sz2, 0);\n        sm.assign(sz2,\
    \ 0); sz.assign(sz2, 0);\n        ladd.assign(sz2, 0); lval.assign(sz2, LINF);\n\
    \        // set sizes (sz[k] = number of REAL elements covered)\n        // We\
    \ need sz for addall/setall. Use len = 1 for each leaf.\n        // sz at leaves:\
    \ real leaves have sz=1, padding leaves have sz=0.\n        // Propagate up.\n\
    \        for (int i = n0; i < n0 + n; i++) sz[i] = 1;\n        for (int i = n0\
    \ - 1; i >= 1; i--) sz[i] = sz[2*i] + sz[2*i+1];\n        // Note: we also need\
    \ sz for addall/setall at non-leaf nodes.\n        // Actually, for addall we\
    \ use sm[k] += sz[k] * x,\n        // so sz[k] must count only real elements.\n\
    \        // Initialize leaves\n        for (int i = 0; i < n; i++) {\n       \
    \     int k = n0 + i;\n            ll v = (a ? a[i] : 0LL);\n            max_v[k]\
    \ = smax_v[k] = min_v[k] = smin_v[k] = v;\n            max_c[k] = min_c[k] = 1;\n\
    \            sm[k] = v;\n        }\n        // padding leaves: already -LINF /\
    \ LINF / count=0\n        for (int i = n0 - 1; i >= 1; i--) pull(i);\n    }\n\n\
    public:\n    segment_beats() = default;\n    segment_beats(int n, ll init_val\
    \ = 0) {\n        vector<ll> a(n, init_val);\n        _init(n, a.data());\n  \
    \  }\n    segment_beats(const vector<ll>& a) { _init((int)a.size(), a.data());\
    \ }\n\n    // half-open intervals [l, r)\n    void range_chmin(int l, int r, ll\
    \ x) { _chmin(x, l, r, 1, 0, n0); }\n    void range_chmax(int l, int r, ll x)\
    \ { _chmax(x, l, r, 1, 0, n0); }\n    void range_add  (int l, int r, ll x) { _add\
    \  (x, l, r, 1, 0, n0); }\n    void range_set  (int l, int r, ll x) { _set  (x,\
    \ l, r, 1, 0, n0); }\n    ll query_max(int l, int r) { return _qmax(l, r, 1, 0,\
    \ n0); }\n    ll query_min(int l, int r) { return _qmin(l, r, 1, 0, n0); }\n \
    \   ll query_sum(int l, int r) { return _qsum(l, r, 1, 0, n0); }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n// Segment\
    \ Beats (Ji Driver Segmentation)\n// Supports (all queries half-open [l, r)):\n\
    //   range_chmin(l, r, x) : a[i] = min(a[i], x)\n//   range_chmax(l, r, x) : a[i]\
    \ = max(a[i], x)\n//   range_add  (l, r, x) : a[i] += x\n//   range_set  (l, r,\
    \ x) : a[i] = x\n//   query_max  (l, r)    : max of a[l..r)\n//   query_min  (l,\
    \ r)    : min of a[l..r)\n//   query_sum  (l, r)    : sum of a[l..r)\n//\n// Amortized\
    \ O((n + q) log^2 n).\n// Reference: https://tjkendev.github.io/procon-library/cpp/range_query/segment_tree_beats_2.html\n\
    \nstruct segment_beats {\n    using ll = long long;\n    static constexpr ll LINF\
    \ = 2e18;\n\n    int n, n0;\n    // max_v, smax_v: max value, strict 2nd-max value\
    \ (-LINF if none)\n    // min_v, smin_v: min value, strict 2nd-min value (+LINF\
    \ if none)\n    vector<ll> max_v, smax_v, min_v, smin_v, sm, sz, ladd, lval;\n\
    \    vector<int> max_c, min_c;\n\n    // ---- leaf/node modifiers ----\n    //\
    \ addall: add x to every element of node k\n    void addall(int k, ll x) {\n \
    \       max_v[k] += x;\n        if (smax_v[k] != -LINF) smax_v[k] += x;\n    \
    \    min_v[k] += x;\n        if (smin_v[k] !=  LINF) smin_v[k] += x;\n       \
    \ sm[k] += sz[k] * x;\n        if (lval[k] != LINF) lval[k] += x;\n        else\
    \                 ladd[k] += x;\n    }\n    // setall: set every element of node\
    \ k to x\n    void setall(int k, ll x) {\n        max_v[k] = smax_v[k] = min_v[k]\
    \ = smin_v[k] = x;\n        max_c[k] = min_c[k] = (int)sz[k];\n        sm[k] =\
    \ sz[k] * x;\n        lval[k] = x; ladd[k] = 0;\n    }\n    // push_chmin: apply\
    \ chmin(x) to node k, reducing its current max to x\n    //   precondition: smax_v[k]\
    \ < x < max_v[k]\n    void push_chmin(int k, ll x) {\n        sm[k] -= (max_v[k]\
    \ - x) * max_c[k];\n        if (max_v[k] == min_v[k]) min_v[k] = x;\n        if\
    \ (max_v[k] == smin_v[k]) smin_v[k] = x;\n        max_v[k] = x;\n        if (lval[k]\
    \ != LINF && lval[k] > x) lval[k] = x;\n    }\n    // push_chmax: apply chmax(x)\
    \ to node k, raising its current min to x\n    //   precondition: smin_v[k] >\
    \ x > min_v[k]\n    void push_chmax(int k, ll x) {\n        sm[k] += (x - min_v[k])\
    \ * min_c[k];\n        if (max_v[k] == min_v[k]) max_v[k] = x;\n        if (smax_v[k]\
    \ == min_v[k]) smax_v[k] = x;\n        min_v[k] = x;\n        if (lval[k] != LINF\
    \ && lval[k] < x) lval[k] = x;\n    }\n\n    // pull: recompute node k from its\
    \ children\n    void pull(int k) {\n        int l = 2*k, r = 2*k+1;\n        sm[k]\
    \ = sm[l] + sm[r];\n        // max info\n        if      (max_v[l] < max_v[r])\
    \ { max_v[k]=max_v[r]; max_c[k]=max_c[r]; smax_v[k]=max(max_v[l], smax_v[r]);\
    \ }\n        else if (max_v[l] > max_v[r]) { max_v[k]=max_v[l]; max_c[k]=max_c[l];\
    \ smax_v[k]=max(smax_v[l], max_v[r]); }\n        else                        \
    \  { max_v[k]=max_v[l]; max_c[k]=max_c[l]+max_c[r]; smax_v[k]=max(smax_v[l], smax_v[r]);\
    \ }\n        // min info\n        if      (min_v[l] < min_v[r]) { min_v[k]=min_v[l];\
    \ min_c[k]=min_c[l]; smin_v[k]=min(smin_v[l], min_v[r]); }\n        else if (min_v[l]\
    \ > min_v[r]) { min_v[k]=min_v[r]; min_c[k]=min_c[r]; smin_v[k]=min(min_v[l],\
    \ smin_v[r]); }\n        else                          { min_v[k]=min_v[l]; min_c[k]=min_c[l]+min_c[r];\
    \ smin_v[k]=min(smin_v[l], smin_v[r]); }\n    }\n\n    // push: propagate lazy\
    \ values to children\n    void push(int k) {\n        if (k >= n0) return;  //\
    \ leaf: nothing to push\n        if (lval[k] != LINF) {\n            setall(2*k,\
    \ lval[k]); setall(2*k+1, lval[k]);\n            lval[k] = LINF; ladd[k] = 0;\n\
    \            return;\n        }\n        if (ladd[k] != 0) {\n            addall(2*k,\
    \ ladd[k]); addall(2*k+1, ladd[k]);\n            ladd[k] = 0;\n        }\n   \
    \     // propagate chmin / chmax bounds\n        if (max_v[k] < max_v[2*k])  \
    \ push_chmin(2*k,   max_v[k]);\n        if (min_v[2*k] < min_v[k])   push_chmax(2*k,\
    \   min_v[k]);\n        if (max_v[k] < max_v[2*k+1]) push_chmin(2*k+1, max_v[k]);\n\
    \        if (min_v[2*k+1] < min_v[k]) push_chmax(2*k+1, min_v[k]);\n    }\n\n\
    \    // ---- range operations ----\n    void _chmin(ll x, int a, int b, int k,\
    \ int l, int r) {\n        if (b <= l || r <= a || max_v[k] <= x) return;\n  \
    \      if (a <= l && r <= b && smax_v[k] < x) { push_chmin(k, x); return; }\n\
    \        push(k); int m = (l+r)/2;\n        _chmin(x,a,b,2*k,l,m); _chmin(x,a,b,2*k+1,m,r);\
    \ pull(k);\n    }\n    void _chmax(ll x, int a, int b, int k, int l, int r) {\n\
    \        if (b <= l || r <= a || x <= min_v[k]) return;\n        if (a <= l &&\
    \ r <= b && x < smin_v[k]) { push_chmax(k, x); return; }\n        push(k); int\
    \ m = (l+r)/2;\n        _chmax(x,a,b,2*k,l,m); _chmax(x,a,b,2*k+1,m,r); pull(k);\n\
    \    }\n    void _add(ll x, int a, int b, int k, int l, int r) {\n        if (b\
    \ <= l || r <= a) return;\n        if (a <= l && r <= b) { addall(k, x); return;\
    \ }\n        push(k); int m = (l+r)/2;\n        _add(x,a,b,2*k,l,m); _add(x,a,b,2*k+1,m,r);\
    \ pull(k);\n    }\n    void _set(ll x, int a, int b, int k, int l, int r) {\n\
    \        if (b <= l || r <= a) return;\n        if (a <= l && r <= b) { setall(k,\
    \ x); return; }\n        push(k); int m = (l+r)/2;\n        _set(x,a,b,2*k,l,m);\
    \ _set(x,a,b,2*k+1,m,r); pull(k);\n    }\n    ll _qmax(int a, int b, int k, int\
    \ l, int r) {\n        if (b <= l || r <= a) return -LINF;\n        if (a <= l\
    \ && r <= b) return max_v[k];\n        push(k); int m = (l+r)/2;\n        return\
    \ max(_qmax(a,b,2*k,l,m), _qmax(a,b,2*k+1,m,r));\n    }\n    ll _qmin(int a, int\
    \ b, int k, int l, int r) {\n        if (b <= l || r <= a) return LINF;\n    \
    \    if (a <= l && r <= b) return min_v[k];\n        push(k); int m = (l+r)/2;\n\
    \        return min(_qmin(a,b,2*k,l,m), _qmin(a,b,2*k+1,m,r));\n    }\n    ll\
    \ _qsum(int a, int b, int k, int l, int r) {\n        if (b <= l || r <= a) return\
    \ 0;\n        if (a <= l && r <= b) return sm[k];\n        push(k); int m = (l+r)/2;\n\
    \        return _qsum(a,b,2*k,l,m) + _qsum(a,b,2*k+1,m,r);\n    }\n\n    // ----\
    \ construction ----\n    void _init(int n_, const ll* a) {\n        n = n_; n0\
    \ = 1; while (n0 < n) n0 <<= 1;\n        int sz2 = 2 * n0 + 2;\n        max_v.assign(sz2,\
    \ -LINF); smax_v.assign(sz2, -LINF); max_c.assign(sz2, 0);\n        min_v.assign(sz2,\
    \  LINF); smin_v.assign(sz2,  LINF); min_c.assign(sz2, 0);\n        sm.assign(sz2,\
    \ 0); sz.assign(sz2, 0);\n        ladd.assign(sz2, 0); lval.assign(sz2, LINF);\n\
    \        // set sizes (sz[k] = number of REAL elements covered)\n        // We\
    \ need sz for addall/setall. Use len = 1 for each leaf.\n        // sz at leaves:\
    \ real leaves have sz=1, padding leaves have sz=0.\n        // Propagate up.\n\
    \        for (int i = n0; i < n0 + n; i++) sz[i] = 1;\n        for (int i = n0\
    \ - 1; i >= 1; i--) sz[i] = sz[2*i] + sz[2*i+1];\n        // Note: we also need\
    \ sz for addall/setall at non-leaf nodes.\n        // Actually, for addall we\
    \ use sm[k] += sz[k] * x,\n        // so sz[k] must count only real elements.\n\
    \        // Initialize leaves\n        for (int i = 0; i < n; i++) {\n       \
    \     int k = n0 + i;\n            ll v = (a ? a[i] : 0LL);\n            max_v[k]\
    \ = smax_v[k] = min_v[k] = smin_v[k] = v;\n            max_c[k] = min_c[k] = 1;\n\
    \            sm[k] = v;\n        }\n        // padding leaves: already -LINF /\
    \ LINF / count=0\n        for (int i = n0 - 1; i >= 1; i--) pull(i);\n    }\n\n\
    public:\n    segment_beats() = default;\n    segment_beats(int n, ll init_val\
    \ = 0) {\n        vector<ll> a(n, init_val);\n        _init(n, a.data());\n  \
    \  }\n    segment_beats(const vector<ll>& a) { _init((int)a.size(), a.data());\
    \ }\n\n    // half-open intervals [l, r)\n    void range_chmin(int l, int r, ll\
    \ x) { _chmin(x, l, r, 1, 0, n0); }\n    void range_chmax(int l, int r, ll x)\
    \ { _chmax(x, l, r, 1, 0, n0); }\n    void range_add  (int l, int r, ll x) { _add\
    \  (x, l, r, 1, 0, n0); }\n    void range_set  (int l, int r, ll x) { _set  (x,\
    \ l, r, 1, 0, n0); }\n    ll query_max(int l, int r) { return _qmax(l, r, 1, 0,\
    \ n0); }\n    ll query_min(int l, int r) { return _qmin(l, r, 1, 0, n0); }\n \
    \   ll query_sum(int l, int r) { return _qsum(l, r, 1, 0, n0); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/segment_beats.hpp
  requiredBy: []
  timestamp: '2026-03-10 02:22:16+09:00'
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
