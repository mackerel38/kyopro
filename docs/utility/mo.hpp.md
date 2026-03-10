---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/library_checker_static_range_inversions_query.test.cpp
    title: verify/library_checker_static_range_inversions_query.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"utility/mo.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n// Mo's algorithm  O((N + Q) sqrt(N)) offline range queries\n//\n//\
    \ Usage:\n//   mo m(n);\n//   m.add(l, r);   // register query [l, r)  (half-open)\n\
    //   m.run(add_l, del_l, add_r, del_r, query_fn);\n//\n// Callbacks:\n//   add_l(i)\
    \  : extend  left  boundary to include index i\n//   del_l(i)  : shrink  left\
    \  boundary to exclude index i\n//   add_r(i)  : extend  right boundary (called\
    \ with index = new r-1)\n//   del_r(i)  : shrink  right boundary (called with\
    \ index = old r-1)\n//   query(qi) : answer query qi  (qi is the order of m.add\
    \ calls)\n//\n// Current window is always [curL, curR) during execution.\nstruct\
    \ mo {\n    int n;\n    vector<pair<int,int>> qs;\n\n    mo() = default;\n   \
    \ mo(int n) : n(n) {}\n\n    void add(int l, int r) { qs.push_back({l, r}); }\n\
    \n    template <class AL, class DL, class AR, class DR, class Q>\n    void run(AL\
    \ add_l, DL del_l, AR add_r, DR del_r, Q query) {\n        int q = qs.size();\n\
    \        if (q == 0) return;\n        int block = max(1, (int)sqrt(n));\n    \
    \    vector<int> ord(q);\n        iota(ord.begin(), ord.end(), 0);\n        sort(ord.begin(),\
    \ ord.end(), [&](int a, int b) {\n            int ba = qs[a].first / block, bb\
    \ = qs[b].first / block;\n            if (ba != bb) return ba < bb;\n        \
    \    return (ba & 1) ? qs[a].second > qs[b].second\n                         \
    \   : qs[a].second < qs[b].second;\n        });\n        int l = 0, r = 0;\n \
    \       for (int i : ord) {\n            int ql = qs[i].first, qr = qs[i].second;\n\
    \            while (r < qr) add_r(r++);\n            while (l > ql) add_l(--l);\n\
    \            while (r > qr) del_r(--r);\n            while (l < ql) del_l(l++);\n\
    \            query(i);\n        }\n    }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n// Mo's algorithm\
    \  O((N + Q) sqrt(N)) offline range queries\n//\n// Usage:\n//   mo m(n);\n//\
    \   m.add(l, r);   // register query [l, r)  (half-open)\n//   m.run(add_l, del_l,\
    \ add_r, del_r, query_fn);\n//\n// Callbacks:\n//   add_l(i)  : extend  left \
    \ boundary to include index i\n//   del_l(i)  : shrink  left  boundary to exclude\
    \ index i\n//   add_r(i)  : extend  right boundary (called with index = new r-1)\n\
    //   del_r(i)  : shrink  right boundary (called with index = old r-1)\n//   query(qi)\
    \ : answer query qi  (qi is the order of m.add calls)\n//\n// Current window is\
    \ always [curL, curR) during execution.\nstruct mo {\n    int n;\n    vector<pair<int,int>>\
    \ qs;\n\n    mo() = default;\n    mo(int n) : n(n) {}\n\n    void add(int l, int\
    \ r) { qs.push_back({l, r}); }\n\n    template <class AL, class DL, class AR,\
    \ class DR, class Q>\n    void run(AL add_l, DL del_l, AR add_r, DR del_r, Q query)\
    \ {\n        int q = qs.size();\n        if (q == 0) return;\n        int block\
    \ = max(1, (int)sqrt(n));\n        vector<int> ord(q);\n        iota(ord.begin(),\
    \ ord.end(), 0);\n        sort(ord.begin(), ord.end(), [&](int a, int b) {\n \
    \           int ba = qs[a].first / block, bb = qs[b].first / block;\n        \
    \    if (ba != bb) return ba < bb;\n            return (ba & 1) ? qs[a].second\
    \ > qs[b].second\n                            : qs[a].second < qs[b].second;\n\
    \        });\n        int l = 0, r = 0;\n        for (int i : ord) {\n       \
    \     int ql = qs[i].first, qr = qs[i].second;\n            while (r < qr) add_r(r++);\n\
    \            while (l > ql) add_l(--l);\n            while (r > qr) del_r(--r);\n\
    \            while (l < ql) del_l(l++);\n            query(i);\n        }\n  \
    \  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: utility/mo.hpp
  requiredBy: []
  timestamp: '2026-03-09 22:49:24+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/library_checker_static_range_inversions_query.test.cpp
documentation_of: utility/mo.hpp
layout: document
redirect_from:
- /library/utility/mo.hpp
- /library/utility/mo.hpp.html
title: utility/mo.hpp
---
