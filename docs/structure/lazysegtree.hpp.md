---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker_range_affine_range_sum.test.cpp
    title: verify/library_checker_range_affine_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"structure/lazysegtree.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n// Lazy Segment Tree\n// S: value monoid type, op: S*S->S,\
    \ e: identity of S\n// F: lazy type, mapping: F*S->S, composition: F*F->F, id:\
    \ identity of F\ntemplate <class S, auto op, auto e, class F, auto mapping, auto\
    \ composition, auto id>\nstruct lazysegtree {\n    int n, size;\n    vector<S>\
    \ data;\n    vector<F> lazy;\n\n    lazysegtree(int n) : n(n) {\n        size\
    \ = 1;\n        while (size < n) size <<= 1;\n        data.assign(2*size, e());\n\
    \        lazy.assign(2*size, id());\n    }\n    lazysegtree(const vector<S>& v)\
    \ : lazysegtree(v.size()) {\n        for (int i = 0; i < (int)v.size(); i++) data[size+i]\
    \ = v[i];\n        for (int i = size-1; i >= 1; i--) data[i] = op(data[2*i], data[2*i+1]);\n\
    \    }\n\n    void apply_node(int k, const F& f) {\n        data[k] = mapping(f,\
    \ data[k]);\n        lazy[k] = composition(f, lazy[k]);\n    }\n    void push_down(int\
    \ k) {\n        if (lazy[k] == id()) return;\n        apply_node(2*k, lazy[k]);\n\
    \        apply_node(2*k+1, lazy[k]);\n        lazy[k] = id();\n    }\n\n    //\
    \ Range apply f to [l, r)\n    void apply(int l, int r, const F& f, int k, int\
    \ lo, int hi) {\n        if (r <= lo || hi <= l) return;\n        if (l <= lo\
    \ && hi <= r) { apply_node(k, f); return; }\n        push_down(k);\n        int\
    \ mid = (lo + hi) / 2;\n        apply(l, r, f, 2*k, lo, mid);\n        apply(l,\
    \ r, f, 2*k+1, mid, hi);\n        data[k] = op(data[2*k], data[2*k+1]);\n    }\n\
    \    void apply(int l, int r, const F& f) { apply(l, r, f, 1, 0, size); }\n  \
    \  void apply(int i, const F& f) { apply(i, i+1, f); }\n\n    // Range query on\
    \ [l, r)\n    S prod(int l, int r, int k, int lo, int hi) {\n        if (r <=\
    \ lo || hi <= l) return e();\n        if (l <= lo && hi <= r) return data[k];\n\
    \        push_down(k);\n        int mid = (lo + hi) / 2;\n        return op(prod(l,\
    \ r, 2*k, lo, mid), prod(l, r, 2*k+1, mid, hi));\n    }\n    S prod(int l, int\
    \ r) { return prod(l, r, 1, 0, size); }\n    S prod(int i) { return prod(i, i+1);\
    \ }\n\n    void set(int i, const S& v) {\n        i += size;\n        for (int\
    \ k = __lg(size); k >= 1; k--) push_down(i >> k);\n        data[i] = v;\n    \
    \    for (int k = 1; k <= __lg(size); k++) {\n            int p = i >> k;\n  \
    \          data[p] = op(data[2*p], data[2*p+1]);\n        }\n    }\n};\n\n// Example\
    \ instantiation (range add, range min query):\n// auto op = [](long long a, long\
    \ long b){ return min(a, b); };\n// auto e  = []{ return numeric_limits<long long>::max()/2;\
    \ };\n// auto mapping = [](long long f, long long s){ return f + s; };\n// auto\
    \ composition = [](long long f, long long g){ return f + g; };\n// auto id = []{\
    \ return 0LL; };\n// lazysegtree<long long, op, e, long long, mapping, composition,\
    \ id> seg(n);\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n// Lazy Segment\
    \ Tree\n// S: value monoid type, op: S*S->S, e: identity of S\n// F: lazy type,\
    \ mapping: F*S->S, composition: F*F->F, id: identity of F\ntemplate <class S,\
    \ auto op, auto e, class F, auto mapping, auto composition, auto id>\nstruct lazysegtree\
    \ {\n    int n, size;\n    vector<S> data;\n    vector<F> lazy;\n\n    lazysegtree(int\
    \ n) : n(n) {\n        size = 1;\n        while (size < n) size <<= 1;\n     \
    \   data.assign(2*size, e());\n        lazy.assign(2*size, id());\n    }\n   \
    \ lazysegtree(const vector<S>& v) : lazysegtree(v.size()) {\n        for (int\
    \ i = 0; i < (int)v.size(); i++) data[size+i] = v[i];\n        for (int i = size-1;\
    \ i >= 1; i--) data[i] = op(data[2*i], data[2*i+1]);\n    }\n\n    void apply_node(int\
    \ k, const F& f) {\n        data[k] = mapping(f, data[k]);\n        lazy[k] =\
    \ composition(f, lazy[k]);\n    }\n    void push_down(int k) {\n        if (lazy[k]\
    \ == id()) return;\n        apply_node(2*k, lazy[k]);\n        apply_node(2*k+1,\
    \ lazy[k]);\n        lazy[k] = id();\n    }\n\n    // Range apply f to [l, r)\n\
    \    void apply(int l, int r, const F& f, int k, int lo, int hi) {\n        if\
    \ (r <= lo || hi <= l) return;\n        if (l <= lo && hi <= r) { apply_node(k,\
    \ f); return; }\n        push_down(k);\n        int mid = (lo + hi) / 2;\n   \
    \     apply(l, r, f, 2*k, lo, mid);\n        apply(l, r, f, 2*k+1, mid, hi);\n\
    \        data[k] = op(data[2*k], data[2*k+1]);\n    }\n    void apply(int l, int\
    \ r, const F& f) { apply(l, r, f, 1, 0, size); }\n    void apply(int i, const\
    \ F& f) { apply(i, i+1, f); }\n\n    // Range query on [l, r)\n    S prod(int\
    \ l, int r, int k, int lo, int hi) {\n        if (r <= lo || hi <= l) return e();\n\
    \        if (l <= lo && hi <= r) return data[k];\n        push_down(k);\n    \
    \    int mid = (lo + hi) / 2;\n        return op(prod(l, r, 2*k, lo, mid), prod(l,\
    \ r, 2*k+1, mid, hi));\n    }\n    S prod(int l, int r) { return prod(l, r, 1,\
    \ 0, size); }\n    S prod(int i) { return prod(i, i+1); }\n\n    void set(int\
    \ i, const S& v) {\n        i += size;\n        for (int k = __lg(size); k >=\
    \ 1; k--) push_down(i >> k);\n        data[i] = v;\n        for (int k = 1; k\
    \ <= __lg(size); k++) {\n            int p = i >> k;\n            data[p] = op(data[2*p],\
    \ data[2*p+1]);\n        }\n    }\n};\n\n// Example instantiation (range add,\
    \ range min query):\n// auto op = [](long long a, long long b){ return min(a,\
    \ b); };\n// auto e  = []{ return numeric_limits<long long>::max()/2; };\n// auto\
    \ mapping = [](long long f, long long s){ return f + s; };\n// auto composition\
    \ = [](long long f, long long g){ return f + g; };\n// auto id = []{ return 0LL;\
    \ };\n// lazysegtree<long long, op, e, long long, mapping, composition, id> seg(n);\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/lazysegtree.hpp
  requiredBy: []
  timestamp: '2026-03-10 19:16:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker_range_affine_range_sum.test.cpp
documentation_of: structure/lazysegtree.hpp
layout: document
redirect_from:
- /library/structure/lazysegtree.hpp
- /library/structure/lazysegtree.hpp.html
title: structure/lazysegtree.hpp
---
