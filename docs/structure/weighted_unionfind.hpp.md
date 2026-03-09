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
    using namespace std;\n\n// Weighted Union Find  (potentials on an abelian group)\n\
    //\n// weight(x) is defined relative to root:  pot[root] = 0, pot[x] = d(root\
    \ -> x)\n// weight(x, y) := pot[y] - pot[x]  = d(x -> y)\n//\n// merge(x, y, w):\
    \  set  weight(x, y) = w  (= pot[y] - pot[x])\n//   returns true if successful\
    \ (no contradiction), false if already connected\n// same(x, y):  returns true\
    \ if x and y are in the same component\n// diff(x, y):  returns pot[y] - pot[x]\
    \  (UB if !same(x,y))\n//\n// T: value type with operator+ and operator-  (e.g.\
    \ long long)\n\ntemplate <class T = long long>\nstruct weighted_unionfind {\n\
    \    vector<int> par;\n    vector<T>   pot;  // pot[x] = d(par[x] -> x)   (pot[root]\
    \ = 0)\n    vector<int> rank_;\n\n    weighted_unionfind() = default;\n    weighted_unionfind(int\
    \ n) : par(n), pot(n, T{}), rank_(n, 0) {\n        iota(par.begin(), par.end(),\
    \ 0);\n    }\n\n    // returns {root, potential of x relative to root}\n    pair<int,\
    \ T> find(int x) {\n        if (par[x] == x) return {x, T{}};\n        auto [r,\
    \ p] = find(par[x]);\n        par[x] = r;\n        pot[x] += p;\n        return\
    \ {r, pot[x]};\n    }\n\n    bool same(int x, int y) { return find(x).first ==\
    \ find(y).first; }\n\n    // potential of x relative to component root\n    T\
    \ potential(int x) { return find(x).second; }\n\n    // d(x -> y) = pot[y] - pot[x]\n\
    \    T diff(int x, int y) { return potential(y) - potential(x); }\n\n    // set\
    \ weight(x->y) = w  (pot[y] - pot[x] = w)\n    // returns false if already in\
    \ same component (constraint check only)\n    bool merge(int x, int y, T w) {\n\
    \        // w = pot[y] - pot[x]\n        // transform to root-relative\n     \
    \   auto [rx, px] = find(x);\n        auto [ry, py] = find(y);\n        if (rx\
    \ == ry) return false; // already connected\n        // want: pot[y_new_root_side]\
    \ - pot[x_new_root_side] = w\n        // pot[y] = py (relative to ry), pot[x]\
    \ = px (relative to rx)\n        // w = py + pot[ry] - (px + pot[rx])  after merge\n\
    \        // => merge ry under rx:  pot[ry] = w + px - py\n        w = w + px -\
    \ py;\n        if (rank_[rx] < rank_[ry]) { swap(rx, ry); w = -w; }\n        par[ry]\
    \ = rx;\n        pot[ry] = w;\n        if (rank_[rx] == rank_[ry]) ++rank_[rx];\n\
    \        return true;\n    }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n// Weighted\
    \ Union Find  (potentials on an abelian group)\n//\n// weight(x) is defined relative\
    \ to root:  pot[root] = 0, pot[x] = d(root -> x)\n// weight(x, y) := pot[y] -\
    \ pot[x]  = d(x -> y)\n//\n// merge(x, y, w):  set  weight(x, y) = w  (= pot[y]\
    \ - pot[x])\n//   returns true if successful (no contradiction), false if already\
    \ connected\n// same(x, y):  returns true if x and y are in the same component\n\
    // diff(x, y):  returns pot[y] - pot[x]  (UB if !same(x,y))\n//\n// T: value type\
    \ with operator+ and operator-  (e.g. long long)\n\ntemplate <class T = long long>\n\
    struct weighted_unionfind {\n    vector<int> par;\n    vector<T>   pot;  // pot[x]\
    \ = d(par[x] -> x)   (pot[root] = 0)\n    vector<int> rank_;\n\n    weighted_unionfind()\
    \ = default;\n    weighted_unionfind(int n) : par(n), pot(n, T{}), rank_(n, 0)\
    \ {\n        iota(par.begin(), par.end(), 0);\n    }\n\n    // returns {root,\
    \ potential of x relative to root}\n    pair<int, T> find(int x) {\n        if\
    \ (par[x] == x) return {x, T{}};\n        auto [r, p] = find(par[x]);\n      \
    \  par[x] = r;\n        pot[x] += p;\n        return {r, pot[x]};\n    }\n\n \
    \   bool same(int x, int y) { return find(x).first == find(y).first; }\n\n   \
    \ // potential of x relative to component root\n    T potential(int x) { return\
    \ find(x).second; }\n\n    // d(x -> y) = pot[y] - pot[x]\n    T diff(int x, int\
    \ y) { return potential(y) - potential(x); }\n\n    // set weight(x->y) = w  (pot[y]\
    \ - pot[x] = w)\n    // returns false if already in same component (constraint\
    \ check only)\n    bool merge(int x, int y, T w) {\n        // w = pot[y] - pot[x]\n\
    \        // transform to root-relative\n        auto [rx, px] = find(x);\n   \
    \     auto [ry, py] = find(y);\n        if (rx == ry) return false; // already\
    \ connected\n        // want: pot[y_new_root_side] - pot[x_new_root_side] = w\n\
    \        // pot[y] = py (relative to ry), pot[x] = px (relative to rx)\n     \
    \   // w = py + pot[ry] - (px + pot[rx])  after merge\n        // => merge ry\
    \ under rx:  pot[ry] = w + px - py\n        w = w + px - py;\n        if (rank_[rx]\
    \ < rank_[ry]) { swap(rx, ry); w = -w; }\n        par[ry] = rx;\n        pot[ry]\
    \ = w;\n        if (rank_[rx] == rank_[ry]) ++rank_[rx];\n        return true;\n\
    \    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/weighted_unionfind.hpp
  requiredBy: []
  timestamp: '2026-03-09 22:49:24+09:00'
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
