---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/library_checker_unionfind_with_potential.test.cpp
    title: verify/library_checker_unionfind_with_potential.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"structure/weighted_unionfind.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n// Weighted Union Find with potential  (abelian group\
    \ on T)\n// Reference: Nyaan's Library\n//\n// Semantics:\n//   potential(x) \
    \     : value of x relative to its component root (pot[root] = 0)\n//   diff(x,\
    \ y)        : potential(y) - potential(x)  (= w(x->y))\n//   merge(x, y, w)  \
    \  : declare diff(x, y) = w\n//                       returns true  if merged\
    \ successfully (x and y were in different components)\n//                    \
    \   returns false if x and y were already in the same component\n//          \
    \               (in this case the constraint is checked: true iff consistent)\n\
    //   same(x, y)        : true iff x and y are in the same component\n\ntemplate\
    \ <class T = long long>\nstruct weighted_unionfind {\n    vector<int> par, sz;\n\
    \    vector<T>   pot;  // pot[x] = d(par[x] -> x); pot[root] = 0 after find\n\n\
    \    weighted_unionfind() = default;\n    weighted_unionfind(int n) : par(n),\
    \ sz(n, 1), pot(n, T{}) {\n        iota(par.begin(), par.end(), 0);\n    }\n\n\
    \    // Returns {root, potential of x relative to root}.\n    // Applies path\
    \ compression: pot[x] becomes d(root -> x).\n    pair<int, T> find(int x) {\n\
    \        if (par[x] == x) return {x, T{}};\n        auto [r, d] = find(par[x]);\n\
    \        pot[x] += d;\n        par[x] = r;\n        return {par[x], pot[x]};\n\
    \    }\n\n    bool same(int x, int y) { return find(x).first == find(y).first;\
    \ }\n\n    T potential(int x) { return find(x).second; }\n\n    // diff(x, y)\
    \ = potential(y) - potential(x)\n    T diff(int x, int y) { return potential(y)\
    \ - potential(x); }\n\n    // merge(x, y, w): declare diff(x, y) = w  (i.e. pot[y]\
    \ - pot[x] = w)\n    // Returns true  if x and y were in different components\
    \ (merged).\n    // Returns false if already in same component;\n    //   the\
    \ return value in that case also indicates consistency: true=consistent, false=contradiction.\n\
    \    bool merge(int x, int y, T w) {\n        // Adjust w to be root-relative:\
    \ w_root = w + pot[x] - pot[y]\n        w += potential(x) - potential(y);\n  \
    \      int rx = find(x).first;\n        int ry = find(y).first;\n        if (rx\
    \ == ry) return w == T{};  // already connected: check consistency\n        //\
    \ Union by size\n        if (sz[rx] < sz[ry]) { swap(rx, ry); w = -w; }\n    \
    \    sz[rx] += sz[ry];\n        par[ry] = rx;\n        pot[ry] = w;\n        return\
    \ true;\n    }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n// Weighted\
    \ Union Find with potential  (abelian group on T)\n// Reference: Nyaan's Library\n\
    //\n// Semantics:\n//   potential(x)      : value of x relative to its component\
    \ root (pot[root] = 0)\n//   diff(x, y)        : potential(y) - potential(x) \
    \ (= w(x->y))\n//   merge(x, y, w)    : declare diff(x, y) = w\n//           \
    \            returns true  if merged successfully (x and y were in different components)\n\
    //                       returns false if x and y were already in the same component\n\
    //                         (in this case the constraint is checked: true iff consistent)\n\
    //   same(x, y)        : true iff x and y are in the same component\n\ntemplate\
    \ <class T = long long>\nstruct weighted_unionfind {\n    vector<int> par, sz;\n\
    \    vector<T>   pot;  // pot[x] = d(par[x] -> x); pot[root] = 0 after find\n\n\
    \    weighted_unionfind() = default;\n    weighted_unionfind(int n) : par(n),\
    \ sz(n, 1), pot(n, T{}) {\n        iota(par.begin(), par.end(), 0);\n    }\n\n\
    \    // Returns {root, potential of x relative to root}.\n    // Applies path\
    \ compression: pot[x] becomes d(root -> x).\n    pair<int, T> find(int x) {\n\
    \        if (par[x] == x) return {x, T{}};\n        auto [r, d] = find(par[x]);\n\
    \        pot[x] += d;\n        par[x] = r;\n        return {par[x], pot[x]};\n\
    \    }\n\n    bool same(int x, int y) { return find(x).first == find(y).first;\
    \ }\n\n    T potential(int x) { return find(x).second; }\n\n    // diff(x, y)\
    \ = potential(y) - potential(x)\n    T diff(int x, int y) { return potential(y)\
    \ - potential(x); }\n\n    // merge(x, y, w): declare diff(x, y) = w  (i.e. pot[y]\
    \ - pot[x] = w)\n    // Returns true  if x and y were in different components\
    \ (merged).\n    // Returns false if already in same component;\n    //   the\
    \ return value in that case also indicates consistency: true=consistent, false=contradiction.\n\
    \    bool merge(int x, int y, T w) {\n        // Adjust w to be root-relative:\
    \ w_root = w + pot[x] - pot[y]\n        w += potential(x) - potential(y);\n  \
    \      int rx = find(x).first;\n        int ry = find(y).first;\n        if (rx\
    \ == ry) return w == T{};  // already connected: check consistency\n        //\
    \ Union by size\n        if (sz[rx] < sz[ry]) { swap(rx, ry); w = -w; }\n    \
    \    sz[rx] += sz[ry];\n        par[ry] = rx;\n        pot[ry] = w;\n        return\
    \ true;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/weighted_unionfind.hpp
  requiredBy: []
  timestamp: '2026-03-10 03:22:29+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/library_checker_unionfind_with_potential.test.cpp
documentation_of: structure/weighted_unionfind.hpp
layout: document
redirect_from:
- /library/structure/weighted_unionfind.hpp
- /library/structure/weighted_unionfind.hpp.html
title: structure/weighted_unionfind.hpp
---
