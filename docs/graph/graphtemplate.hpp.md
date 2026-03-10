---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: graph/bfs.hpp
    title: graph/bfs.hpp
  - icon: ':x:'
    path: graph/dijkstra.hpp
    title: graph/dijkstra.hpp
  - icon: ':heavy_check_mark:'
    path: graph/kruskal.hpp
    title: graph/kruskal.hpp
  - icon: ':warning:'
    path: graph/toposort.hpp
    title: graph/toposort.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker_minimum_spanning_tree.test.cpp
    title: verify/library_checker_minimum_spanning_tree.test.cpp
  - icon: ':x:'
    path: verify/library_checker_shortest_path.test.cpp
    title: verify/library_checker_shortest_path.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/graphtemplate.hpp\"\n#include<bits/stdc++.h>\nusing\
    \ namespace std;\n// \u8FBA\u306E\u69CB\u9020\u4F53 edge(from, to, cost, id)\n\
    template<class T = int>\nstruct edge {\n    int from, to;\n    T cost;\n    int\
    \ id;\n};\n// \u9802\u70B9\u306E\u69CB\u9020\u4F53 vector<edge<T>>\ntemplate<class\
    \ T = int>\nusing edges = vector<edge<T>>;\n// \u30B0\u30E9\u30D5\u306E\u69CB\u9020\
    \u4F53 graph<T, directed, weighted>\ntemplate <class T = int, bool directed =\
    \ false, bool weighted = false>\nstruct graph {\n    bool isdirected, isweighted;\n\
    \    edges<T> _edges;\n    vector<edges<T>> data;\n    T sumcost;\n    graph()\
    \ = default;\n    // \u9802\u70B9\u6570 n \u306E\u30B0\u30E9\u30D5\u3092\u4F5C\
    \u6210\u3059\u308B\n    graph(int n) : isdirected(directed), isweighted(weighted),\
    \ data(n), sumcost(T{}) {}\n    // from \u304B\u3089 to \u3078\u8FBA\u3092\u8FFD\
    \u52A0\u3059\u308B\n    void add_edge(int from, int to, T cost = 1, int id = -1)\
    \ {\n        if (id == -1) id = _edges.size();\n        data[from].push_back(edge<T>{from,\
    \ to, cost, id});\n        _edges.push_back(edge<T>{from, to, cost, id});\n  \
    \      if (!isdirected) {\n            data[to].push_back(edge<T>{to, from, cost,\
    \ id});\n        }\n        sumcost += cost;\n    }\n    // \u8FBA\u3092\u8FFD\
    \u52A0\u3059\u308B\n    void add_edge(edge<T> _e) {\n        add_edge(_e.from,\
    \ _e.to, _e.cost, _e.id);\n    }\n    // \u6A19\u6E96\u5165\u529B\u304B\u3089\u8FBA\
    \u3092\u8AAD\u307F\u8FBC\u3080\n    void read(int m, int indexed = 1) {\n    \
    \    for (int i=0; i<m; i++) {\n            int from, to;\n            T cost\
    \ = 1;\n            cin >> from >> to;\n            if (isweighted) cin >> cost;\n\
    \            add_edge(from - indexed, to - indexed, cost);\n        }\n    }\n\
    \    // \u9802\u70B9\u6570\u3092\u8FD4\u3059\n    int size() {\n        return\
    \ data.size();\n    }\n    // \u9802\u70B9\u3092\u8FD4\u3059\n    edges<T> operator[](int\
    \ k) {\n        return data[k];\n    }\n    // \u30D1\u30B9\u3092\u9802\u70B9\u306B\
    \u5909\u63DB\u3059\u308B\n    vector<int> path_to_vertex(edges<T>& _e) {\n   \
    \     vector<int> re;\n        if (_e.size() == 0) {\n            return re;\n\
    \        }\n        if (_e.size() == 1) {\n            re.push_back(_e[0].from);\n\
    \            re.push_back(_e[0].to);\n            return re;\n        }\n    \
    \    int x=_e[0].from,y=_e[0].to;\n        if (x==_e[1].to || x == _e[1].from)\
    \ swap(x, y);\n        re.push_back(x);\n        for (int i=1; i<(int)_e.size();\
    \ i++) {\n            re.push_back(y);\n            x = _e[i].to;\n          \
    \  if (x == y) x = _e[i].from;\n            swap(x, y);\n        }\n        return\
    \ re;\n    }\n    // \u9802\u70B9\u3092\u30D1\u30B9\u306B\u5909\u63DB\u3059\u308B\
    \n    edges<T> vertex_to_path(vector<int>& v) {\n        edges<T> re;\n      \
    \  for (int i=0; i+1<(int)v.size(); i++) {\n            for (auto& _e : data[v[i]])\
    \ {\n                if (_e.to == v[i+1]) {\n                    re.push_back(_e);\n\
    \                    break;\n                }\n            }\n        }\n   \
    \     return re;\n    }\n};\n"
  code: "#pragma once\n#include<bits/stdc++.h>\nusing namespace std;\n// \u8FBA\u306E\
    \u69CB\u9020\u4F53 edge(from, to, cost, id)\ntemplate<class T = int>\nstruct edge\
    \ {\n    int from, to;\n    T cost;\n    int id;\n};\n// \u9802\u70B9\u306E\u69CB\
    \u9020\u4F53 vector<edge<T>>\ntemplate<class T = int>\nusing edges = vector<edge<T>>;\n\
    // \u30B0\u30E9\u30D5\u306E\u69CB\u9020\u4F53 graph<T, directed, weighted>\ntemplate\
    \ <class T = int, bool directed = false, bool weighted = false>\nstruct graph\
    \ {\n    bool isdirected, isweighted;\n    edges<T> _edges;\n    vector<edges<T>>\
    \ data;\n    T sumcost;\n    graph() = default;\n    // \u9802\u70B9\u6570 n \u306E\
    \u30B0\u30E9\u30D5\u3092\u4F5C\u6210\u3059\u308B\n    graph(int n) : isdirected(directed),\
    \ isweighted(weighted), data(n), sumcost(T{}) {}\n    // from \u304B\u3089 to\
    \ \u3078\u8FBA\u3092\u8FFD\u52A0\u3059\u308B\n    void add_edge(int from, int\
    \ to, T cost = 1, int id = -1) {\n        if (id == -1) id = _edges.size();\n\
    \        data[from].push_back(edge<T>{from, to, cost, id});\n        _edges.push_back(edge<T>{from,\
    \ to, cost, id});\n        if (!isdirected) {\n            data[to].push_back(edge<T>{to,\
    \ from, cost, id});\n        }\n        sumcost += cost;\n    }\n    // \u8FBA\
    \u3092\u8FFD\u52A0\u3059\u308B\n    void add_edge(edge<T> _e) {\n        add_edge(_e.from,\
    \ _e.to, _e.cost, _e.id);\n    }\n    // \u6A19\u6E96\u5165\u529B\u304B\u3089\u8FBA\
    \u3092\u8AAD\u307F\u8FBC\u3080\n    void read(int m, int indexed = 1) {\n    \
    \    for (int i=0; i<m; i++) {\n            int from, to;\n            T cost\
    \ = 1;\n            cin >> from >> to;\n            if (isweighted) cin >> cost;\n\
    \            add_edge(from - indexed, to - indexed, cost);\n        }\n    }\n\
    \    // \u9802\u70B9\u6570\u3092\u8FD4\u3059\n    int size() {\n        return\
    \ data.size();\n    }\n    // \u9802\u70B9\u3092\u8FD4\u3059\n    edges<T> operator[](int\
    \ k) {\n        return data[k];\n    }\n    // \u30D1\u30B9\u3092\u9802\u70B9\u306B\
    \u5909\u63DB\u3059\u308B\n    vector<int> path_to_vertex(edges<T>& _e) {\n   \
    \     vector<int> re;\n        if (_e.size() == 0) {\n            return re;\n\
    \        }\n        if (_e.size() == 1) {\n            re.push_back(_e[0].from);\n\
    \            re.push_back(_e[0].to);\n            return re;\n        }\n    \
    \    int x=_e[0].from,y=_e[0].to;\n        if (x==_e[1].to || x == _e[1].from)\
    \ swap(x, y);\n        re.push_back(x);\n        for (int i=1; i<(int)_e.size();\
    \ i++) {\n            re.push_back(y);\n            x = _e[i].to;\n          \
    \  if (x == y) x = _e[i].from;\n            swap(x, y);\n        }\n        return\
    \ re;\n    }\n    // \u9802\u70B9\u3092\u30D1\u30B9\u306B\u5909\u63DB\u3059\u308B\
    \n    edges<T> vertex_to_path(vector<int>& v) {\n        edges<T> re;\n      \
    \  for (int i=0; i+1<(int)v.size(); i++) {\n            for (auto& _e : data[v[i]])\
    \ {\n                if (_e.to == v[i+1]) {\n                    re.push_back(_e);\n\
    \                    break;\n                }\n            }\n        }\n   \
    \     return re;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/graphtemplate.hpp
  requiredBy:
  - graph/bfs.hpp
  - graph/dijkstra.hpp
  - graph/toposort.hpp
  - graph/kruskal.hpp
  timestamp: '2026-03-09 22:49:24+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/library_checker_shortest_path.test.cpp
  - verify/library_checker_minimum_spanning_tree.test.cpp
documentation_of: graph/graphtemplate.hpp
layout: document
redirect_from:
- /library/graph/graphtemplate.hpp
- /library/graph/graphtemplate.hpp.html
title: graph/graphtemplate.hpp
---
