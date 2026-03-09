#pragma once
#include <bits/stdc++.h>
using namespace std;

// Topological sort (Kahn's algorithm)
// Returns sorted order, or empty vector if a cycle exists
vector<int> toposort(const vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> indeg(n, 0);
    for (int v = 0; v < n; v++)
        for (int u : graph[v]) indeg[u]++;
    queue<int> q;
    for (int v = 0; v < n; v++)
        if (indeg[v] == 0) q.push(v);
    vector<int> order;
    while (!q.empty()) {
        int v = q.front(); q.pop();
        order.push_back(v);
        for (int u : graph[v])
            if (--indeg[u] == 0) q.push(u);
    }
    if ((int)order.size() != n) return {}; // cycle detected
    return order;
}

// DFS-based topological sort; also detects cycles
// Returns {order, has_cycle}
pair<vector<int>, bool> toposort_dfs(const vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> color(n, 0); // 0: white, 1: gray, 2: black
    vector<int> order;
    bool has_cycle = false;
    function<void(int)> dfs = [&](int v) {
        if (has_cycle) return;
        color[v] = 1;
        for (int u : graph[v]) {
            if (color[u] == 1) { has_cycle = true; return; }
            if (color[u] == 0) dfs(u);
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
