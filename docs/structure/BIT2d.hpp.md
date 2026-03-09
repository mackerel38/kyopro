---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/library_checker_point_add_rectangle_sum.test.cpp
    title: verify/library_checker_point_add_rectangle_sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"structure/BIT2d.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n// 2D BIT (Fenwick tree)\n// (1) Dense 2D BIT  O(H*W) space, O(log H\
    \ * log W) per query\n// (2) Compressed 2D BIT (offline)  for point_add_rectangle_sum\n\
    \n// --- Dense 2D BIT ---\ntemplate <class T = long long>\nstruct BIT2d {\n  \
    \  int h, w;\n    vector<vector<T>> bit;\n\n    BIT2d() = default;\n    BIT2d(int\
    \ h, int w) : h(h), w(w), bit(h + 1, vector<T>(w + 1, 0)) {}\n\n    // add v to\
    \ point (x, y)  (1-indexed)\n    void add(int x, int y, T v) {\n        for (int\
    \ i = x; i <= h; i += i & -i)\n            for (int j = y; j <= w; j += j & -j)\n\
    \                bit[i][j] += v;\n    }\n\n    // sum of [1, x] x [1, y]  (1-indexed)\n\
    \    T sum(int x, int y) const {\n        T s = 0;\n        for (int i = x; i\
    \ > 0; i -= i & -i)\n            for (int j = y; j > 0; j -= j & -j)\n       \
    \         s += bit[i][j];\n        return s;\n    }\n\n    // sum of [lx, rx]\
    \ x [ly, ry]  (1-indexed, inclusive)\n    T sum(int lx, int rx, int ly, int ry)\
    \ const {\n        return sum(rx, ry) - sum(lx - 1, ry) - sum(rx, ly - 1) + sum(lx\
    \ - 1, ly - 1);\n    }\n};\n\n// --- Compressed 2D BIT (offline) ---\n// For each\
    \ x-coordinate, maintain a 1D BIT over y-coordinates\n// that are actually used.\
    \  O(Q log Q) time, O(Q log Q) space.\ntemplate <class T = long long>\nstruct\
    \ BIT2d_compressed {\n    int n; // x size\n    vector<vector<int>> ys;   // sorted\
    \ y-coords for each x\n    vector<vector<T>>   bit;\n    bool built = false;\n\
    \n    BIT2d_compressed() = default;\n    BIT2d_compressed(int n) : n(n), ys(n\
    \ + 1), bit(n + 1) {}\n\n    // register point (x, y) before build  (1-indexed\
    \ x)\n    void reserve(int x, int y) {\n        for (int i = x; i <= n; i += i\
    \ & -i) ys[i].push_back(y);\n    }\n\n    void build() {\n        for (int i =\
    \ 1; i <= n; i++) {\n            sort(ys[i].begin(), ys[i].end());\n         \
    \   ys[i].erase(unique(ys[i].begin(), ys[i].end()), ys[i].end());\n          \
    \  bit[i].assign(ys[i].size() + 1, 0);\n        }\n        built = true;\n   \
    \ }\n\n    void _add(int x, int y, T v) {\n        int j = lower_bound(ys[x].begin(),\
    \ ys[x].end(), y) - ys[x].begin() + 1;\n        for (; j <= (int)ys[x].size();\
    \ j += j & -j) bit[x][j] += v;\n    }\n    T _sum(int x, int y) const {\n    \
    \    int j = upper_bound(ys[x].begin(), ys[x].end(), y) - ys[x].begin();\n   \
    \     T s = 0;\n        for (; j > 0; j -= j & -j) s += bit[x][j];\n        return\
    \ s;\n    }\n\n    // add v to point (x, y)  (1-indexed)\n    void add(int x,\
    \ int y, T v) {\n        for (int i = x; i <= n; i += i & -i) _add(i, y, v);\n\
    \    }\n\n    // prefix sum [1,x] x [-inf, y]\n    T sum(int x, int y) const {\n\
    \        T s = 0;\n        for (int i = x; i > 0; i -= i & -i) s += _sum(i, y);\n\
    \        return s;\n    }\n\n    // sum of [lx, rx] x [ly, ry]  (1-indexed x,\
    \ arbitrary y)\n    T sum(int lx, int rx, int ly, int ry) const {\n        return\
    \ sum(rx, ry) - sum(lx - 1, ry) - sum(rx, ly - 1) + sum(lx - 1, ly - 1);\n   \
    \ }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n// 2D BIT\
    \ (Fenwick tree)\n// (1) Dense 2D BIT  O(H*W) space, O(log H * log W) per query\n\
    // (2) Compressed 2D BIT (offline)  for point_add_rectangle_sum\n\n// --- Dense\
    \ 2D BIT ---\ntemplate <class T = long long>\nstruct BIT2d {\n    int h, w;\n\
    \    vector<vector<T>> bit;\n\n    BIT2d() = default;\n    BIT2d(int h, int w)\
    \ : h(h), w(w), bit(h + 1, vector<T>(w + 1, 0)) {}\n\n    // add v to point (x,\
    \ y)  (1-indexed)\n    void add(int x, int y, T v) {\n        for (int i = x;\
    \ i <= h; i += i & -i)\n            for (int j = y; j <= w; j += j & -j)\n   \
    \             bit[i][j] += v;\n    }\n\n    // sum of [1, x] x [1, y]  (1-indexed)\n\
    \    T sum(int x, int y) const {\n        T s = 0;\n        for (int i = x; i\
    \ > 0; i -= i & -i)\n            for (int j = y; j > 0; j -= j & -j)\n       \
    \         s += bit[i][j];\n        return s;\n    }\n\n    // sum of [lx, rx]\
    \ x [ly, ry]  (1-indexed, inclusive)\n    T sum(int lx, int rx, int ly, int ry)\
    \ const {\n        return sum(rx, ry) - sum(lx - 1, ry) - sum(rx, ly - 1) + sum(lx\
    \ - 1, ly - 1);\n    }\n};\n\n// --- Compressed 2D BIT (offline) ---\n// For each\
    \ x-coordinate, maintain a 1D BIT over y-coordinates\n// that are actually used.\
    \  O(Q log Q) time, O(Q log Q) space.\ntemplate <class T = long long>\nstruct\
    \ BIT2d_compressed {\n    int n; // x size\n    vector<vector<int>> ys;   // sorted\
    \ y-coords for each x\n    vector<vector<T>>   bit;\n    bool built = false;\n\
    \n    BIT2d_compressed() = default;\n    BIT2d_compressed(int n) : n(n), ys(n\
    \ + 1), bit(n + 1) {}\n\n    // register point (x, y) before build  (1-indexed\
    \ x)\n    void reserve(int x, int y) {\n        for (int i = x; i <= n; i += i\
    \ & -i) ys[i].push_back(y);\n    }\n\n    void build() {\n        for (int i =\
    \ 1; i <= n; i++) {\n            sort(ys[i].begin(), ys[i].end());\n         \
    \   ys[i].erase(unique(ys[i].begin(), ys[i].end()), ys[i].end());\n          \
    \  bit[i].assign(ys[i].size() + 1, 0);\n        }\n        built = true;\n   \
    \ }\n\n    void _add(int x, int y, T v) {\n        int j = lower_bound(ys[x].begin(),\
    \ ys[x].end(), y) - ys[x].begin() + 1;\n        for (; j <= (int)ys[x].size();\
    \ j += j & -j) bit[x][j] += v;\n    }\n    T _sum(int x, int y) const {\n    \
    \    int j = upper_bound(ys[x].begin(), ys[x].end(), y) - ys[x].begin();\n   \
    \     T s = 0;\n        for (; j > 0; j -= j & -j) s += bit[x][j];\n        return\
    \ s;\n    }\n\n    // add v to point (x, y)  (1-indexed)\n    void add(int x,\
    \ int y, T v) {\n        for (int i = x; i <= n; i += i & -i) _add(i, y, v);\n\
    \    }\n\n    // prefix sum [1,x] x [-inf, y]\n    T sum(int x, int y) const {\n\
    \        T s = 0;\n        for (int i = x; i > 0; i -= i & -i) s += _sum(i, y);\n\
    \        return s;\n    }\n\n    // sum of [lx, rx] x [ly, ry]  (1-indexed x,\
    \ arbitrary y)\n    T sum(int lx, int rx, int ly, int ry) const {\n        return\
    \ sum(rx, ry) - sum(lx - 1, ry) - sum(rx, ly - 1) + sum(lx - 1, ly - 1);\n   \
    \ }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/BIT2d.hpp
  requiredBy: []
  timestamp: '2026-03-09 22:49:24+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/library_checker_point_add_rectangle_sum.test.cpp
documentation_of: structure/BIT2d.hpp
layout: document
redirect_from:
- /library/structure/BIT2d.hpp
- /library/structure/BIT2d.hpp.html
title: structure/BIT2d.hpp
---
