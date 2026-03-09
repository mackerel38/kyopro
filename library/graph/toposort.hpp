#pragma once
#include "graphtemplate.hpp"

// Topological sort (Kahn's algorithm)
// Use: graph<T, true, *> (directed)
// Returns sorted order, or empty vector if a cycle exists
template <class T, bool weighted>
vector<int> toposort(graph<T, true, weighted>& g) {
    int n = g.size();
    vector<int> indeg(n, 0);
    for (int v = 0; v < n; v++)
        for (auto& e : g[v]) indeg[e.to]++;
    queue<int> q;
    for (int v = 0; v < n; v++)
        if (indeg[v] == 0) q.push(v);
    vector<int> order;
    while (!q.empty()) {
        int v = q.front(); q.pop();
        order.push_back(v);
        for (auto& e : g[v])
            if (--indeg[e.to] == 0) q.push(e.to);
    }
    if ((int)order.size() != n) return {}; // cycle detected
    return order;
}

// DFS-based topological sort; also detects cycles
// Returns {order, has_cycle}
template <class T, bool weighted>
pair<vector<int>, bool> toposort_dfs(graph<T, true, weighted>& g) {
    int n = g.size();
    vector<int> color(n, 0); // 0: white, 1: gray, 2: black
    vector<int> order;
    bool has_cycle = false;
    function<void(int)> dfs = [&](int v) {
        if (has_cycle) return;
        color[v] = 1;
        for (auto& e : g[v]) {
            if (color[e.to] == 1) { has_cycle = true; return; }
            if (color[e.to] == 0) dfs(e.to);
        }
        color[v] = 2;
        order.push_back(v);
    };
    for (int v = 0; v < n; v++)
        if (color[v] == 0) dfs(v);
    if (has_cycle) return {{}, true};
    reverse(order.begin(), order.end());
    return {order, false};
}
