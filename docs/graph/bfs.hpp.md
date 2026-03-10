---
data:
  _extendedDependsOn:
  - icon: ':question:'
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
    \     return re;\n    }\n};\n#line 3 \"graph/bfs.hpp\"\n\n// BFS: returns distance\
    \ from src (-1 if unreachable)\n// graph<T, directed, weighted> (T=int, unweighted)\n\
    template <class T, bool directed, bool weighted>\nvector<long long> bfs(graph<T,\
    \ directed, weighted>& g, int src) {\n    int n = g.size();\n    vector<long long>\
    \ dist(n, -1);\n    queue<int> q;\n    dist[src] = 0;\n    q.push(src);\n    while\
    \ (!q.empty()) {\n        int v = q.front(); q.pop();\n        for (auto& e :\
    \ g[v]) {\n            if (dist[e.to] == -1) {\n                dist[e.to] = dist[v]\
    \ + 1;\n                q.push(e.to);\n            }\n        }\n    }\n    return\
    \ dist;\n}\n\n// BFS on grid (4-directional)\n// passable[r][c] == true means\
    \ the cell can be entered\nvector<vector<long long>> bfs_grid(const vector<vector<bool>>&\
    \ passable, int sr, int sc) {\n    int H = passable.size(), W = passable[0].size();\n\
    \    const int DR[] = {0, 1, 0, -1};\n    const int DC[] = {1, 0, -1, 0};\n  \
    \  vector<vector<long long>> dist(H, vector<long long>(W, -1));\n    queue<pair<int,int>>\
    \ q;\n    dist[sr][sc] = 0;\n    q.push({sr, sc});\n    while (!q.empty()) {\n\
    \        auto [r, c] = q.front(); q.pop();\n        for (int d = 0; d < 4; d++)\
    \ {\n            int nr = r + DR[d], nc = c + DC[d];\n            if (0<=nr &&\
    \ nr<H && 0<=nc && nc<W\n             && passable[nr][nc] && dist[nr][nc] == -1)\
    \ {\n                dist[nr][nc] = dist[r][c] + 1;\n                q.push({nr,\
    \ nc});\n            }\n        }\n    }\n    return dist;\n}\n"
  code: "#pragma once\n#include \"graphtemplate.hpp\"\n\n// BFS: returns distance\
    \ from src (-1 if unreachable)\n// graph<T, directed, weighted> (T=int, unweighted)\n\
    template <class T, bool directed, bool weighted>\nvector<long long> bfs(graph<T,\
    \ directed, weighted>& g, int src) {\n    int n = g.size();\n    vector<long long>\
    \ dist(n, -1);\n    queue<int> q;\n    dist[src] = 0;\n    q.push(src);\n    while\
    \ (!q.empty()) {\n        int v = q.front(); q.pop();\n        for (auto& e :\
    \ g[v]) {\n            if (dist[e.to] == -1) {\n                dist[e.to] = dist[v]\
    \ + 1;\n                q.push(e.to);\n            }\n        }\n    }\n    return\
    \ dist;\n}\n\n// BFS on grid (4-directional)\n// passable[r][c] == true means\
    \ the cell can be entered\nvector<vector<long long>> bfs_grid(const vector<vector<bool>>&\
    \ passable, int sr, int sc) {\n    int H = passable.size(), W = passable[0].size();\n\
    \    const int DR[] = {0, 1, 0, -1};\n    const int DC[] = {1, 0, -1, 0};\n  \
    \  vector<vector<long long>> dist(H, vector<long long>(W, -1));\n    queue<pair<int,int>>\
    \ q;\n    dist[sr][sc] = 0;\n    q.push({sr, sc});\n    while (!q.empty()) {\n\
    \        auto [r, c] = q.front(); q.pop();\n        for (int d = 0; d < 4; d++)\
    \ {\n            int nr = r + DR[d], nc = c + DC[d];\n            if (0<=nr &&\
    \ nr<H && 0<=nc && nc<W\n             && passable[nr][nc] && dist[nr][nc] == -1)\
    \ {\n                dist[nr][nc] = dist[r][c] + 1;\n                q.push({nr,\
    \ nc});\n            }\n        }\n    }\n    return dist;\n}\n"
  dependsOn:
  - graph/graphtemplate.hpp
  isVerificationFile: false
  path: graph/bfs.hpp
  requiredBy: []
  timestamp: '2026-03-09 22:49:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/bfs.hpp
layout: document
redirect_from:
- /library/graph/bfs.hpp
- /library/graph/bfs.hpp.html
title: graph/bfs.hpp
---
