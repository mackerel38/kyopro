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
  bundledCode: "#line 2 \"structure/ordered_set.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n// Ordered set (multiset) using Fenwick tree for rank\
    \ queries\n// Values must be in [0, MAXV) after coordinate compression.\n// O(log\
    \ N) per operation.  N = MAXV (number of distinct buckets).\nstruct ordered_set\
    \ {\n    int n;\n    vector<int> fw;   // fw = Fenwick (not 'bit' to avoid macro\
    \ conflict)\n    int total = 0;\n\n    ordered_set() = default;\n    ordered_set(int\
    \ n) : n(n), fw(n + 1, 0) {}\n\n    void _add(int i, int v) { for (i++; i <= n;\
    \ i += i & -i) fw[i] += v; }\n    int  _sum(int i) const  { int s = 0; for (;\
    \ i > 0; i -= i & -i) s += fw[i]; return s; }\n    int  _sum(int l, int r) const\
    \ { return l >= r ? 0 : _sum(r) - _sum(l); } // [l, r)\n\n    void insert(int\
    \ x) { _add(x,  1); ++total; }\n    void erase (int x) { _add(x, -1); --total;\
    \ }\n    int  count (int x) const { return _sum(x, x + 1); }\n    int  size  ()\
    \       const { return total; }\n    bool empty ()       const { return total\
    \ == 0; }\n\n    // rank of x: number of elements < x\n    int rank(int x) const\
    \ { return _sum(x); }\n\n    // k-th (0-indexed) smallest element\n    int kth(int\
    \ k) const {\n        assert(0 <= k && k < total);\n        int pos = 0;\n   \
    \     for (int pw = 1 << __lg(n); pw; pw >>= 1)\n            if (pos + pw <= n\
    \ && fw[pos + pw] <= k)\n                k -= fw[pos += pw];\n        return pos;\n\
    \    }\n\n    int lower_bound(int x) const { return kth(rank(x)); }\n    int upper_bound(int\
    \ x) const {\n        int r = rank(x + 1);\n        assert(r < total);\n     \
    \   return kth(r);\n    }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n// Ordered\
    \ set (multiset) using Fenwick tree for rank queries\n// Values must be in [0,\
    \ MAXV) after coordinate compression.\n// O(log N) per operation.  N = MAXV (number\
    \ of distinct buckets).\nstruct ordered_set {\n    int n;\n    vector<int> fw;\
    \   // fw = Fenwick (not 'bit' to avoid macro conflict)\n    int total = 0;\n\n\
    \    ordered_set() = default;\n    ordered_set(int n) : n(n), fw(n + 1, 0) {}\n\
    \n    void _add(int i, int v) { for (i++; i <= n; i += i & -i) fw[i] += v; }\n\
    \    int  _sum(int i) const  { int s = 0; for (; i > 0; i -= i & -i) s += fw[i];\
    \ return s; }\n    int  _sum(int l, int r) const { return l >= r ? 0 : _sum(r)\
    \ - _sum(l); } // [l, r)\n\n    void insert(int x) { _add(x,  1); ++total; }\n\
    \    void erase (int x) { _add(x, -1); --total; }\n    int  count (int x) const\
    \ { return _sum(x, x + 1); }\n    int  size  ()       const { return total; }\n\
    \    bool empty ()       const { return total == 0; }\n\n    // rank of x: number\
    \ of elements < x\n    int rank(int x) const { return _sum(x); }\n\n    // k-th\
    \ (0-indexed) smallest element\n    int kth(int k) const {\n        assert(0 <=\
    \ k && k < total);\n        int pos = 0;\n        for (int pw = 1 << __lg(n);\
    \ pw; pw >>= 1)\n            if (pos + pw <= n && fw[pos + pw] <= k)\n       \
    \         k -= fw[pos += pw];\n        return pos;\n    }\n\n    int lower_bound(int\
    \ x) const { return kth(rank(x)); }\n    int upper_bound(int x) const {\n    \
    \    int r = rank(x + 1);\n        assert(r < total);\n        return kth(r);\n\
    \    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/ordered_set.hpp
  requiredBy: []
  timestamp: '2026-03-10 02:22:16+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/ordered_set.hpp
layout: document
redirect_from:
- /library/structure/ordered_set.hpp
- /library/structure/ordered_set.hpp.html
title: structure/ordered_set.hpp
---
