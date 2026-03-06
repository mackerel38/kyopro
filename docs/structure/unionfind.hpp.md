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
  bundledCode: "#line 2 \"structure/unionfind.hpp\"\n#include<bits/stdc++.h>\nusing\
    \ namespace std;\n\nstruct unionfind {\n    vector<int> data;\n\n    unionfind(int\
    \ n) : data(n, -1) {}\n\n    int root(int k) { return data[k]<0 ? k : data[k]\
    \ = root(data[k]); }\n    int operator[](int k) { return root(k); }\n\n    int\
    \ merge(int x, int y) {\n        if ((x = root(x)) == (y = root(y))) return false;\n\
    \        if (data[x] < data[y]) swap(x, y);\n        data[y] += data[x];\n   \
    \     data[x] = y;\n        return true;\n    }\n    template<class F>\n    int\
    \ merge(int x, int y, const F& f) {\n        if ((x = root(x)) == (y = root(y)))\
    \ return false;\n        if (data[y] < data[x]) swap(x, y);\n        data[x] +=\
    \ data[y];\n        data[y] = x;\n        f(x, y);\n        return true;\n   \
    \ }\n\n    int size(int k) { return -data[root(k)]; }\n\n    bool same(int x,\
    \ int y) { return root(x) == root(y); }\n\n    vector<vector<int>> groups() {\n\
    \        vector<vector<int>> mem(data.size());\n        for (int i=0; i<ssize(mem);\
    \ ++i) mem[root(i)].emplace_back(i);\n        vector<vector<int>> re;\n      \
    \  for (int i=0; i<ssize(mem); ++i) if (!mem[i].empty()) re.emplace_back(mem[i]);\n\
    \        return re;\n    }\n};\n\n"
  code: "#pragma once\n#include<bits/stdc++.h>\nusing namespace std;\n\nstruct unionfind\
    \ {\n    vector<int> data;\n\n    unionfind(int n) : data(n, -1) {}\n\n    int\
    \ root(int k) { return data[k]<0 ? k : data[k] = root(data[k]); }\n    int operator[](int\
    \ k) { return root(k); }\n\n    int merge(int x, int y) {\n        if ((x = root(x))\
    \ == (y = root(y))) return false;\n        if (data[x] < data[y]) swap(x, y);\n\
    \        data[y] += data[x];\n        data[x] = y;\n        return true;\n   \
    \ }\n    template<class F>\n    int merge(int x, int y, const F& f) {\n      \
    \  if ((x = root(x)) == (y = root(y))) return false;\n        if (data[y] < data[x])\
    \ swap(x, y);\n        data[x] += data[y];\n        data[y] = x;\n        f(x,\
    \ y);\n        return true;\n    }\n\n    int size(int k) { return -data[root(k)];\
    \ }\n\n    bool same(int x, int y) { return root(x) == root(y); }\n\n    vector<vector<int>>\
    \ groups() {\n        vector<vector<int>> mem(data.size());\n        for (int\
    \ i=0; i<ssize(mem); ++i) mem[root(i)].emplace_back(i);\n        vector<vector<int>>\
    \ re;\n        for (int i=0; i<ssize(mem); ++i) if (!mem[i].empty()) re.emplace_back(mem[i]);\n\
    \        return re;\n    }\n};\n\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/unionfind.hpp
  requiredBy: []
  timestamp: '2026-03-04 02:45:48+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/unionfind.hpp
layout: document
redirect_from:
- /library/structure/unionfind.hpp
- /library/structure/unionfind.hpp.html
title: structure/unionfind.hpp
---
