---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker_staticrmq.test.cpp
    title: verify/library_checker_staticrmq.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"structure/sparse_table.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n// Sparse Table  O(n log n) build, O(1) query\n// op must\
    \ be IDEMPOTENT: op(x, x) == x  (e.g. min, max, gcd)\ntemplate <class S, auto\
    \ op>\nstruct sparse_table {\n    vector<vector<S>> d;\n    vector<int> lg;\n\n\
    \    sparse_table() = default;\n    sparse_table(const vector<S>& v) { build(v);\
    \ }\n\n    void build(const vector<S>& v) {\n        int n = v.size();\n     \
    \   lg.assign(n + 1, 0);\n        for (int i = 2; i <= n; i++) lg[i] = lg[i >>\
    \ 1] + 1;\n        int k = lg[n] + 1;\n        d.assign(k, vector<S>(n));\n  \
    \      d[0] = v;\n        for (int j = 1; j < k; j++)\n            for (int i\
    \ = 0; i + (1 << j) <= n; i++)\n                d[j][i] = op(d[j-1][i], d[j-1][i\
    \ + (1 << (j-1))]);\n    }\n\n    // query [l, r)  (0-indexed, half-open)\n  \
    \  S query(int l, int r) const {\n        int k = lg[r - l];\n        return op(d[k][l],\
    \ d[k][r - (1 << k)]);\n    }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n// Sparse\
    \ Table  O(n log n) build, O(1) query\n// op must be IDEMPOTENT: op(x, x) == x\
    \  (e.g. min, max, gcd)\ntemplate <class S, auto op>\nstruct sparse_table {\n\
    \    vector<vector<S>> d;\n    vector<int> lg;\n\n    sparse_table() = default;\n\
    \    sparse_table(const vector<S>& v) { build(v); }\n\n    void build(const vector<S>&\
    \ v) {\n        int n = v.size();\n        lg.assign(n + 1, 0);\n        for (int\
    \ i = 2; i <= n; i++) lg[i] = lg[i >> 1] + 1;\n        int k = lg[n] + 1;\n  \
    \      d.assign(k, vector<S>(n));\n        d[0] = v;\n        for (int j = 1;\
    \ j < k; j++)\n            for (int i = 0; i + (1 << j) <= n; i++)\n         \
    \       d[j][i] = op(d[j-1][i], d[j-1][i + (1 << (j-1))]);\n    }\n\n    // query\
    \ [l, r)  (0-indexed, half-open)\n    S query(int l, int r) const {\n        int\
    \ k = lg[r - l];\n        return op(d[k][l], d[k][r - (1 << k)]);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/sparse_table.hpp
  requiredBy: []
  timestamp: '2026-03-09 22:49:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker_staticrmq.test.cpp
documentation_of: structure/sparse_table.hpp
layout: document
redirect_from:
- /library/structure/sparse_table.hpp
- /library/structure/sparse_table.hpp.html
title: structure/sparse_table.hpp
---
