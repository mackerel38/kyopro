---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"structure/segtree_beats.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n// Segment Tree Beats (Ji Driver Segmentation)\n// Supports\
    \ (all queries half-open [l, r)):\n//   range_chmin(l, r, x) : a[i] = min(a[i],\
    \ x)\n//   range_chmax(l, r, x) : a[i] = max(a[i], x)\n//   range_add  (l, r,\
    \ x) : a[i] += x\n//   range_set  (l, r, x) : a[i] = x\n//   query_max  (l, r)\
    \    : max of a[l..r)\n//   query_min  (l, r)    : min of a[l..r)\n//   query_sum\
    \  (l, r)    : sum of a[l..r)\n//\n// Amortized O((n + q) log^2 n).\n\nstruct\
    \ segtree_beats {\n    using ll = long long;\n    static constexpr ll LINF = 2e18;\n\
    \n    int n, n0;\n    // max_v[k]: max value in node k\n    // smax_v[k]: strict\
    \ 2nd-max (-LINF if all equal)\n    // min_v[k]: min value in node k\n    // smin_v[k]:\
    \ strict 2nd-min (+LINF if all equal)\n    vector<ll> max_v, smax_v, min_v, smin_v,\
    \ sm, sz, ladd, lval;\n    vector<int> max_c, min_c;\n\n    // addall: add x to\
    \ every element of node k\n    void addall(int k, ll x) {\n        max_v[k] +=\
    \ x;\n        if (smax_v[k] != -LINF) smax_v[k] += x;\n        min_v[k] += x;\n\
    \        if (smin_v[k] !=  LINF) smin_v[k] += x;\n        sm[k] += sz[k] * x;\n\
    \        if (lval[k] != LINF) lval[k] += x;\n        else                 ladd[k]\
    \ += x;\n    }\n    // setall: set every element of node k to x\n    void setall(int\
    \ k, ll x) {\n        max_v[k] = smax_v[k] = min_v[k] = smin_v[k] = x;\n     \
    \   max_c[k] = min_c[k] = (int)sz[k];\n        sm[k] = sz[k] * x;\n        lval[k]\
    \ = x; ladd[k] = 0;\n    }\n\n    // push_chmin: clamp current max down to x\n\
    \    //   precondition (from _chmin): smax_v[k] < x < max_v[k]\n    void push_chmin(int\
    \ k, ll x) {\n        sm[k] -= (max_v[k] - x) * max_c[k];\n        if (max_v[k]\
    \ == min_v[k]) {\n            // all values equal: both max and min become x\n\
    \            max_v[k] = min_v[k] = x;\n        } else {\n            // smax_v[k]\
    \ < x (precondition), so smax_v is unchanged.\n            // min_v needs updating\
    \ only when it equals old max_v.\n            if (smax_v[k] == min_v[k]) min_v[k]\
    \ = x;\n            max_v[k] = x;\n        }\n        if (lval[k] != LINF && lval[k]\
    \ > x) lval[k] = x;\n    }\n    // push_chmax: clamp current min up to x\n   \
    \ //   precondition (from _chmax): smin_v[k] > x > min_v[k]\n    void push_chmax(int\
    \ k, ll x) {\n        sm[k] += (x - min_v[k]) * min_c[k];\n        if (max_v[k]\
    \ == min_v[k]) {\n            // all values equal: both max and min become x\n\
    \            max_v[k] = min_v[k] = x;\n        } else {\n            // smin_v[k]\
    \ > x (precondition), so smin_v is unchanged.\n            // max_v needs updating\
    \ only when it equals old min_v.\n            if (smin_v[k] == max_v[k]) max_v[k]\
    \ = x;\n            min_v[k] = x;\n        }\n        if (lval[k] != LINF && lval[k]\
    \ < x) lval[k] = x;\n    }\n\n    // pull: recompute node k from its children\n\
    \    void pull(int k) {\n        int l = 2*k, r = 2*k+1;\n        sm[k] = sm[l]\
    \ + sm[r];\n        // max info\n        if      (max_v[l] < max_v[r]) { max_v[k]=max_v[r];\
    \ max_c[k]=max_c[r]; smax_v[k]=max(max_v[l], smax_v[r]); }\n        else if (max_v[l]\
    \ > max_v[r]) { max_v[k]=max_v[l]; max_c[k]=max_c[l]; smax_v[k]=max(smax_v[l],\
    \ max_v[r]); }\n        else                          { max_v[k]=max_v[l]; max_c[k]=max_c[l]+max_c[r];\
    \ smax_v[k]=max(smax_v[l], smax_v[r]); }\n        // min info\n        if    \
    \  (min_v[l] < min_v[r]) { min_v[k]=min_v[l]; min_c[k]=min_c[l]; smin_v[k]=min(smin_v[l],\
    \ min_v[r]); }\n        else if (min_v[l] > min_v[r]) { min_v[k]=min_v[r]; min_c[k]=min_c[r];\
    \ smin_v[k]=min(min_v[l], smin_v[r]); }\n        else                        \
    \  { min_v[k]=min_v[l]; min_c[k]=min_c[l]+min_c[r]; smin_v[k]=min(smin_v[l], smin_v[r]);\
    \ }\n    }\n\n    // push: propagate lazy values to children\n    void push(int\
    \ k) {\n        if (k >= n0) return;\n        if (lval[k] != LINF) {\n       \
    \     setall(2*k, lval[k]); setall(2*k+1, lval[k]);\n            lval[k] = LINF;\
    \ ladd[k] = 0;\n            return;\n        }\n        if (ladd[k] != 0) {\n\
    \            addall(2*k, ladd[k]); addall(2*k+1, ladd[k]);\n            ladd[k]\
    \ = 0;\n        }\n        if (max_v[k] < max_v[2*k])   push_chmin(2*k,   max_v[k]);\n\
    \        if (min_v[2*k] < min_v[k])   push_chmax(2*k,   min_v[k]);\n        if\
    \ (max_v[k] < max_v[2*k+1]) push_chmin(2*k+1, max_v[k]);\n        if (min_v[2*k+1]\
    \ < min_v[k]) push_chmax(2*k+1, min_v[k]);\n    }\n\n    void _chmin(ll x, int\
    \ a, int b, int k, int l, int r) {\n        if (b <= l || r <= a || max_v[k] <=\
    \ x) return;\n        if (a <= l && r <= b && smax_v[k] < x) { push_chmin(k, x);\
    \ return; }\n        push(k); int m = (l+r)/2;\n        _chmin(x,a,b,2*k,l,m);\
    \ _chmin(x,a,b,2*k+1,m,r); pull(k);\n    }\n    void _chmax(ll x, int a, int b,\
    \ int k, int l, int r) {\n        if (b <= l || r <= a || x <= min_v[k]) return;\n\
    \        if (a <= l && r <= b && x < smin_v[k]) { push_chmax(k, x); return; }\n\
    \        push(k); int m = (l+r)/2;\n        _chmax(x,a,b,2*k,l,m); _chmax(x,a,b,2*k+1,m,r);\
    \ pull(k);\n    }\n    void _add(ll x, int a, int b, int k, int l, int r) {\n\
    \        if (b <= l || r <= a) return;\n        if (a <= l && r <= b) { addall(k,\
    \ x); return; }\n        push(k); int m = (l+r)/2;\n        _add(x,a,b,2*k,l,m);\
    \ _add(x,a,b,2*k+1,m,r); pull(k);\n    }\n    void _set(ll x, int a, int b, int\
    \ k, int l, int r) {\n        if (b <= l || r <= a) return;\n        if (a <=\
    \ l && r <= b) { setall(k, x); return; }\n        push(k); int m = (l+r)/2;\n\
    \        _set(x,a,b,2*k,l,m); _set(x,a,b,2*k+1,m,r); pull(k);\n    }\n    ll _qmax(int\
    \ a, int b, int k, int l, int r) {\n        if (b <= l || r <= a) return -LINF;\n\
    \        if (a <= l && r <= b) return max_v[k];\n        push(k); int m = (l+r)/2;\n\
    \        return max(_qmax(a,b,2*k,l,m), _qmax(a,b,2*k+1,m,r));\n    }\n    ll\
    \ _qmin(int a, int b, int k, int l, int r) {\n        if (b <= l || r <= a) return\
    \ LINF;\n        if (a <= l && r <= b) return min_v[k];\n        push(k); int\
    \ m = (l+r)/2;\n        return min(_qmin(a,b,2*k,l,m), _qmin(a,b,2*k+1,m,r));\n\
    \    }\n    ll _qsum(int a, int b, int k, int l, int r) {\n        if (b <= l\
    \ || r <= a) return 0;\n        if (a <= l && r <= b) return sm[k];\n        push(k);\
    \ int m = (l+r)/2;\n        return _qsum(a,b,2*k,l,m) + _qsum(a,b,2*k+1,m,r);\n\
    \    }\n\n    void _init(int n_, const ll* a) {\n        n = n_; n0 = 1; while\
    \ (n0 < n) n0 <<= 1;\n        int sz2 = 2 * n0 + 2;\n        max_v.assign(sz2,\
    \ -LINF); smax_v.assign(sz2, -LINF); max_c.assign(sz2, 0);\n        min_v.assign(sz2,\
    \  LINF); smin_v.assign(sz2,  LINF); min_c.assign(sz2, 0);\n        sm.assign(sz2,\
    \ 0); sz.assign(sz2, 0);\n        ladd.assign(sz2, 0); lval.assign(sz2, LINF);\n\
    \        for (int i = n0; i < n0 + n; i++) sz[i] = 1;\n        for (int i = n0\
    \ - 1; i >= 1; i--) sz[i] = sz[2*i] + sz[2*i+1];\n        for (int i = 0; i <\
    \ n; i++) {\n            int k = n0 + i;\n            ll v = (a ? a[i] : 0LL);\n\
    \            max_v[k] = smax_v[k] = min_v[k] = smin_v[k] = v;\n            max_c[k]\
    \ = min_c[k] = 1;\n            sm[k] = v;\n        }\n        for (int i = n0\
    \ - 1; i >= 1; i--) pull(i);\n    }\n\npublic:\n    segtree_beats() = default;\n\
    \    segtree_beats(int n, ll init_val = 0) {\n        vector<ll> a(n, init_val);\n\
    \        _init(n, a.data());\n    }\n    segtree_beats(const vector<ll>& a) {\
    \ _init((int)a.size(), a.data()); }\n\n    void range_chmin(int l, int r, ll x)\
    \ { _chmin(x, l, r, 1, 0, n0); }\n    void range_chmax(int l, int r, ll x) { _chmax(x,\
    \ l, r, 1, 0, n0); }\n    void range_add  (int l, int r, ll x) { _add  (x, l,\
    \ r, 1, 0, n0); }\n    void range_set  (int l, int r, ll x) { _set  (x, l, r,\
    \ 1, 0, n0); }\n    ll query_max(int l, int r) { return _qmax(l, r, 1, 0, n0);\
    \ }\n    ll query_min(int l, int r) { return _qmin(l, r, 1, 0, n0); }\n    ll\
    \ query_sum(int l, int r) { return _qsum(l, r, 1, 0, n0); }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n// Segment\
    \ Tree Beats (Ji Driver Segmentation)\n// Supports (all queries half-open [l,\
    \ r)):\n//   range_chmin(l, r, x) : a[i] = min(a[i], x)\n//   range_chmax(l, r,\
    \ x) : a[i] = max(a[i], x)\n//   range_add  (l, r, x) : a[i] += x\n//   range_set\
    \  (l, r, x) : a[i] = x\n//   query_max  (l, r)    : max of a[l..r)\n//   query_min\
    \  (l, r)    : min of a[l..r)\n//   query_sum  (l, r)    : sum of a[l..r)\n//\n\
    // Amortized O((n + q) log^2 n).\n\nstruct segtree_beats {\n    using ll = long\
    \ long;\n    static constexpr ll LINF = 2e18;\n\n    int n, n0;\n    // max_v[k]:\
    \ max value in node k\n    // smax_v[k]: strict 2nd-max (-LINF if all equal)\n\
    \    // min_v[k]: min value in node k\n    // smin_v[k]: strict 2nd-min (+LINF\
    \ if all equal)\n    vector<ll> max_v, smax_v, min_v, smin_v, sm, sz, ladd, lval;\n\
    \    vector<int> max_c, min_c;\n\n    // addall: add x to every element of node\
    \ k\n    void addall(int k, ll x) {\n        max_v[k] += x;\n        if (smax_v[k]\
    \ != -LINF) smax_v[k] += x;\n        min_v[k] += x;\n        if (smin_v[k] !=\
    \  LINF) smin_v[k] += x;\n        sm[k] += sz[k] * x;\n        if (lval[k] !=\
    \ LINF) lval[k] += x;\n        else                 ladd[k] += x;\n    }\n   \
    \ // setall: set every element of node k to x\n    void setall(int k, ll x) {\n\
    \        max_v[k] = smax_v[k] = min_v[k] = smin_v[k] = x;\n        max_c[k] =\
    \ min_c[k] = (int)sz[k];\n        sm[k] = sz[k] * x;\n        lval[k] = x; ladd[k]\
    \ = 0;\n    }\n\n    // push_chmin: clamp current max down to x\n    //   precondition\
    \ (from _chmin): smax_v[k] < x < max_v[k]\n    void push_chmin(int k, ll x) {\n\
    \        sm[k] -= (max_v[k] - x) * max_c[k];\n        if (max_v[k] == min_v[k])\
    \ {\n            // all values equal: both max and min become x\n            max_v[k]\
    \ = min_v[k] = x;\n        } else {\n            // smax_v[k] < x (precondition),\
    \ so smax_v is unchanged.\n            // min_v needs updating only when it equals\
    \ old max_v.\n            if (smax_v[k] == min_v[k]) min_v[k] = x;\n         \
    \   max_v[k] = x;\n        }\n        if (lval[k] != LINF && lval[k] > x) lval[k]\
    \ = x;\n    }\n    // push_chmax: clamp current min up to x\n    //   precondition\
    \ (from _chmax): smin_v[k] > x > min_v[k]\n    void push_chmax(int k, ll x) {\n\
    \        sm[k] += (x - min_v[k]) * min_c[k];\n        if (max_v[k] == min_v[k])\
    \ {\n            // all values equal: both max and min become x\n            max_v[k]\
    \ = min_v[k] = x;\n        } else {\n            // smin_v[k] > x (precondition),\
    \ so smin_v is unchanged.\n            // max_v needs updating only when it equals\
    \ old min_v.\n            if (smin_v[k] == max_v[k]) max_v[k] = x;\n         \
    \   min_v[k] = x;\n        }\n        if (lval[k] != LINF && lval[k] < x) lval[k]\
    \ = x;\n    }\n\n    // pull: recompute node k from its children\n    void pull(int\
    \ k) {\n        int l = 2*k, r = 2*k+1;\n        sm[k] = sm[l] + sm[r];\n    \
    \    // max info\n        if      (max_v[l] < max_v[r]) { max_v[k]=max_v[r]; max_c[k]=max_c[r];\
    \ smax_v[k]=max(max_v[l], smax_v[r]); }\n        else if (max_v[l] > max_v[r])\
    \ { max_v[k]=max_v[l]; max_c[k]=max_c[l]; smax_v[k]=max(smax_v[l], max_v[r]);\
    \ }\n        else                          { max_v[k]=max_v[l]; max_c[k]=max_c[l]+max_c[r];\
    \ smax_v[k]=max(smax_v[l], smax_v[r]); }\n        // min info\n        if    \
    \  (min_v[l] < min_v[r]) { min_v[k]=min_v[l]; min_c[k]=min_c[l]; smin_v[k]=min(smin_v[l],\
    \ min_v[r]); }\n        else if (min_v[l] > min_v[r]) { min_v[k]=min_v[r]; min_c[k]=min_c[r];\
    \ smin_v[k]=min(min_v[l], smin_v[r]); }\n        else                        \
    \  { min_v[k]=min_v[l]; min_c[k]=min_c[l]+min_c[r]; smin_v[k]=min(smin_v[l], smin_v[r]);\
    \ }\n    }\n\n    // push: propagate lazy values to children\n    void push(int\
    \ k) {\n        if (k >= n0) return;\n        if (lval[k] != LINF) {\n       \
    \     setall(2*k, lval[k]); setall(2*k+1, lval[k]);\n            lval[k] = LINF;\
    \ ladd[k] = 0;\n            return;\n        }\n        if (ladd[k] != 0) {\n\
    \            addall(2*k, ladd[k]); addall(2*k+1, ladd[k]);\n            ladd[k]\
    \ = 0;\n        }\n        if (max_v[k] < max_v[2*k])   push_chmin(2*k,   max_v[k]);\n\
    \        if (min_v[2*k] < min_v[k])   push_chmax(2*k,   min_v[k]);\n        if\
    \ (max_v[k] < max_v[2*k+1]) push_chmin(2*k+1, max_v[k]);\n        if (min_v[2*k+1]\
    \ < min_v[k]) push_chmax(2*k+1, min_v[k]);\n    }\n\n    void _chmin(ll x, int\
    \ a, int b, int k, int l, int r) {\n        if (b <= l || r <= a || max_v[k] <=\
    \ x) return;\n        if (a <= l && r <= b && smax_v[k] < x) { push_chmin(k, x);\
    \ return; }\n        push(k); int m = (l+r)/2;\n        _chmin(x,a,b,2*k,l,m);\
    \ _chmin(x,a,b,2*k+1,m,r); pull(k);\n    }\n    void _chmax(ll x, int a, int b,\
    \ int k, int l, int r) {\n        if (b <= l || r <= a || x <= min_v[k]) return;\n\
    \        if (a <= l && r <= b && x < smin_v[k]) { push_chmax(k, x); return; }\n\
    \        push(k); int m = (l+r)/2;\n        _chmax(x,a,b,2*k,l,m); _chmax(x,a,b,2*k+1,m,r);\
    \ pull(k);\n    }\n    void _add(ll x, int a, int b, int k, int l, int r) {\n\
    \        if (b <= l || r <= a) return;\n        if (a <= l && r <= b) { addall(k,\
    \ x); return; }\n        push(k); int m = (l+r)/2;\n        _add(x,a,b,2*k,l,m);\
    \ _add(x,a,b,2*k+1,m,r); pull(k);\n    }\n    void _set(ll x, int a, int b, int\
    \ k, int l, int r) {\n        if (b <= l || r <= a) return;\n        if (a <=\
    \ l && r <= b) { setall(k, x); return; }\n        push(k); int m = (l+r)/2;\n\
    \        _set(x,a,b,2*k,l,m); _set(x,a,b,2*k+1,m,r); pull(k);\n    }\n    ll _qmax(int\
    \ a, int b, int k, int l, int r) {\n        if (b <= l || r <= a) return -LINF;\n\
    \        if (a <= l && r <= b) return max_v[k];\n        push(k); int m = (l+r)/2;\n\
    \        return max(_qmax(a,b,2*k,l,m), _qmax(a,b,2*k+1,m,r));\n    }\n    ll\
    \ _qmin(int a, int b, int k, int l, int r) {\n        if (b <= l || r <= a) return\
    \ LINF;\n        if (a <= l && r <= b) return min_v[k];\n        push(k); int\
    \ m = (l+r)/2;\n        return min(_qmin(a,b,2*k,l,m), _qmin(a,b,2*k+1,m,r));\n\
    \    }\n    ll _qsum(int a, int b, int k, int l, int r) {\n        if (b <= l\
    \ || r <= a) return 0;\n        if (a <= l && r <= b) return sm[k];\n        push(k);\
    \ int m = (l+r)/2;\n        return _qsum(a,b,2*k,l,m) + _qsum(a,b,2*k+1,m,r);\n\
    \    }\n\n    void _init(int n_, const ll* a) {\n        n = n_; n0 = 1; while\
    \ (n0 < n) n0 <<= 1;\n        int sz2 = 2 * n0 + 2;\n        max_v.assign(sz2,\
    \ -LINF); smax_v.assign(sz2, -LINF); max_c.assign(sz2, 0);\n        min_v.assign(sz2,\
    \  LINF); smin_v.assign(sz2,  LINF); min_c.assign(sz2, 0);\n        sm.assign(sz2,\
    \ 0); sz.assign(sz2, 0);\n        ladd.assign(sz2, 0); lval.assign(sz2, LINF);\n\
    \        for (int i = n0; i < n0 + n; i++) sz[i] = 1;\n        for (int i = n0\
    \ - 1; i >= 1; i--) sz[i] = sz[2*i] + sz[2*i+1];\n        for (int i = 0; i <\
    \ n; i++) {\n            int k = n0 + i;\n            ll v = (a ? a[i] : 0LL);\n\
    \            max_v[k] = smax_v[k] = min_v[k] = smin_v[k] = v;\n            max_c[k]\
    \ = min_c[k] = 1;\n            sm[k] = v;\n        }\n        for (int i = n0\
    \ - 1; i >= 1; i--) pull(i);\n    }\n\npublic:\n    segtree_beats() = default;\n\
    \    segtree_beats(int n, ll init_val = 0) {\n        vector<ll> a(n, init_val);\n\
    \        _init(n, a.data());\n    }\n    segtree_beats(const vector<ll>& a) {\
    \ _init((int)a.size(), a.data()); }\n\n    void range_chmin(int l, int r, ll x)\
    \ { _chmin(x, l, r, 1, 0, n0); }\n    void range_chmax(int l, int r, ll x) { _chmax(x,\
    \ l, r, 1, 0, n0); }\n    void range_add  (int l, int r, ll x) { _add  (x, l,\
    \ r, 1, 0, n0); }\n    void range_set  (int l, int r, ll x) { _set  (x, l, r,\
    \ 1, 0, n0); }\n    ll query_max(int l, int r) { return _qmax(l, r, 1, 0, n0);\
    \ }\n    ll query_min(int l, int r) { return _qmin(l, r, 1, 0, n0); }\n    ll\
    \ query_sum(int l, int r) { return _qsum(l, r, 1, 0, n0); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/segtree_beats.hpp
  requiredBy: []
  timestamp: '2026-03-10 03:22:29+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/segtree_beats.hpp
layout: document
redirect_from:
- /library/structure/segtree_beats.hpp
- /library/structure/segtree_beats.hpp.html
title: structure/segtree_beats.hpp
---
