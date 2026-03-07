---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker_unionfind.test.cpp
    title: verify/library_checker_unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"structure/unionfind.hpp\"\n#include<bits/stdc++.h>\nusing\
    \ namespace std;\n\nstruct unionfind {\n    vector<int> data;\n\n    unionfind(int\
    \ n) : data(n, -1) {}\n\n    int root(int k) { return data[k]<0 ? k : data[k]\
    \ = root(data[k]); }\n    int operator[](int k) { return root(k); }\n\n    bool\
    \ merge(int x, int y) {\n        if ((x = root(x)) == (y = root(y))) return false;\n\
    \        if (data[x] < data[y]) swap(x, y);\n        data[y] += data[x];\n   \
    \     data[x] = y;\n        return true;\n    }\n    template<class F>\n    bool\
    \ merge(int x, int y, const F& f) {\n        if ((x = root(x)) == (y = root(y)))\
    \ return false;\n        if (data[y] < data[x]) swap(x, y);\n        data[x] +=\
    \ data[y];\n        data[y] = x;\n        f(x, y);\n        return true;\n   \
    \ }\n\n    int size(int k) { return -data[root(k)]; }\n\n    bool same(int x,\
    \ int y) { return root(x) == root(y); }\n\n    vector<vector<int>> groups() {\n\
    \        vector<vector<int>> mem(data.size());\n        for (int i=0; i<ssize(mem);\
    \ ++i) mem[root(i)].emplace_back(i);\n        vector<vector<int>> re;\n      \
    \  for (int i=0; i<ssize(mem); ++i) if (!mem[i].empty()) re.emplace_back(mem[i]);\n\
    \        return re;\n    }\n\n    int components() const {\n        int cnt =\
    \ 0;\n        for (auto& i : data) if (i < 0) cnt++;\n        return cnt;\n  \
    \  }\n};\n\n"
  code: "#pragma once\n#include<bits/stdc++.h>\nusing namespace std;\n\nstruct unionfind\
    \ {\n    vector<int> data;\n\n    unionfind(int n) : data(n, -1) {}\n\n    int\
    \ root(int k) { return data[k]<0 ? k : data[k] = root(data[k]); }\n    int operator[](int\
    \ k) { return root(k); }\n\n    bool merge(int x, int y) {\n        if ((x = root(x))\
    \ == (y = root(y))) return false;\n        if (data[x] < data[y]) swap(x, y);\n\
    \        data[y] += data[x];\n        data[x] = y;\n        return true;\n   \
    \ }\n    template<class F>\n    bool merge(int x, int y, const F& f) {\n     \
    \   if ((x = root(x)) == (y = root(y))) return false;\n        if (data[y] < data[x])\
    \ swap(x, y);\n        data[x] += data[y];\n        data[y] = x;\n        f(x,\
    \ y);\n        return true;\n    }\n\n    int size(int k) { return -data[root(k)];\
    \ }\n\n    bool same(int x, int y) { return root(x) == root(y); }\n\n    vector<vector<int>>\
    \ groups() {\n        vector<vector<int>> mem(data.size());\n        for (int\
    \ i=0; i<ssize(mem); ++i) mem[root(i)].emplace_back(i);\n        vector<vector<int>>\
    \ re;\n        for (int i=0; i<ssize(mem); ++i) if (!mem[i].empty()) re.emplace_back(mem[i]);\n\
    \        return re;\n    }\n\n    int components() const {\n        int cnt =\
    \ 0;\n        for (auto& i : data) if (i < 0) cnt++;\n        return cnt;\n  \
    \  }\n};\n\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/unionfind.hpp
  requiredBy: []
  timestamp: '2026-03-07 14:24:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker_unionfind.test.cpp
documentation_of: structure/unionfind.hpp
layout: document
redirect_from:
- /library/structure/unionfind.hpp
- /library/structure/unionfind.hpp.html
title: structure/unionfind.hpp
---
