---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graphtemplate.hpp
    title: graph/graphtemplate.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
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
    \     return re;\n    }\n};\n#line 3 \"graph/toposort.hpp\"\n\n// Topological\
    \ sort (Kahn's algorithm)\n// Use: graph<T, true, *> (directed)\n// Returns sorted\
    \ order, or empty vector if a cycle exists\ntemplate <class T, bool weighted>\n\
    vector<int> toposort(graph<T, true, weighted>& g) {\n    int n = g.size();\n \
    \   vector<int> indeg(n, 0);\n    for (int v = 0; v < n; v++)\n        for (auto&\
    \ e : g[v]) indeg[e.to]++;\n    queue<int> q;\n    for (int v = 0; v < n; v++)\n\
    \        if (indeg[v] == 0) q.push(v);\n    vector<int> order;\n    while (!q.empty())\
    \ {\n        int v = q.front(); q.pop();\n        order.push_back(v);\n      \
    \  for (auto& e : g[v])\n            if (--indeg[e.to] == 0) q.push(e.to);\n \
    \   }\n    if ((int)order.size() != n) return {}; // cycle detected\n    return\
    \ order;\n}\n\n// DFS-based topological sort; also detects cycles\n// Returns\
    \ {order, has_cycle}\ntemplate <class T, bool weighted>\npair<vector<int>, bool>\
    \ toposort_dfs(graph<T, true, weighted>& g) {\n    int n = g.size();\n    vector<int>\
    \ color(n, 0); // 0: white, 1: gray, 2: black\n    vector<int> order;\n    bool\
    \ has_cycle = false;\n    function<void(int)> dfs = [&](int v) {\n        if (has_cycle)\
    \ return;\n        color[v] = 1;\n        for (auto& e : g[v]) {\n           \
    \ if (color[e.to] == 1) { has_cycle = true; return; }\n            if (color[e.to]\
    \ == 0) dfs(e.to);\n        }\n        color[v] = 2;\n        order.push_back(v);\n\
    \    };\n    for (int v = 0; v < n; v++)\n        if (color[v] == 0) dfs(v);\n\
    \    if (has_cycle) return {{}, true};\n    reverse(order.begin(), order.end());\n\
    \    return {order, false};\n}\n"
  code: "#pragma once\n#include \"graphtemplate.hpp\"\n\n// Topological sort (Kahn's\
    \ algorithm)\n// Use: graph<T, true, *> (directed)\n// Returns sorted order, or\
    \ empty vector if a cycle exists\ntemplate <class T, bool weighted>\nvector<int>\
    \ toposort(graph<T, true, weighted>& g) {\n    int n = g.size();\n    vector<int>\
    \ indeg(n, 0);\n    for (int v = 0; v < n; v++)\n        for (auto& e : g[v])\
    \ indeg[e.to]++;\n    queue<int> q;\n    for (int v = 0; v < n; v++)\n       \
    \ if (indeg[v] == 0) q.push(v);\n    vector<int> order;\n    while (!q.empty())\
    \ {\n        int v = q.front(); q.pop();\n        order.push_back(v);\n      \
    \  for (auto& e : g[v])\n            if (--indeg[e.to] == 0) q.push(e.to);\n \
    \   }\n    if ((int)order.size() != n) return {}; // cycle detected\n    return\
    \ order;\n}\n\n// DFS-based topological sort; also detects cycles\n// Returns\
    \ {order, has_cycle}\ntemplate <class T, bool weighted>\npair<vector<int>, bool>\
    \ toposort_dfs(graph<T, true, weighted>& g) {\n    int n = g.size();\n    vector<int>\
    \ color(n, 0); // 0: white, 1: gray, 2: black\n    vector<int> order;\n    bool\
    \ has_cycle = false;\n    function<void(int)> dfs = [&](int v) {\n        if (has_cycle)\
    \ return;\n        color[v] = 1;\n        for (auto& e : g[v]) {\n           \
    \ if (color[e.to] == 1) { has_cycle = true; return; }\n            if (color[e.to]\
    \ == 0) dfs(e.to);\n        }\n        color[v] = 2;\n        order.push_back(v);\n\
    \    };\n    for (int v = 0; v < n; v++)\n        if (color[v] == 0) dfs(v);\n\
    \    if (has_cycle) return {{}, true};\n    reverse(order.begin(), order.end());\n\
    \    return {order, false};\n}\n"
  dependsOn:
  - graph/graphtemplate.hpp
  isVerificationFile: false
  path: graph/toposort.hpp
  requiredBy: []
  timestamp: '2026-03-09 22:49:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/toposort.hpp
layout: document
redirect_from:
- /library/graph/toposort.hpp
- /library/graph/toposort.hpp.html
title: graph/toposort.hpp
---
