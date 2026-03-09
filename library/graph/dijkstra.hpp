#pragma once
#include "graphtemplate.hpp"

// Dijkstra: returns shortest distances from src
// Use: graph<T, directed, true> (weighted=true)
template <class T, bool directed>
vector<T> dijkstra(graph<T, directed, true>& g, int src) {
    int n = g.size();
    const T INF = numeric_limits<T>::max() / 2;
    vector<T> dist(n, INF);
    priority_queue<pair<T,int>, vector<pair<T,int>>, greater<pair<T,int>>> pq;
    dist[src] = T{};
    pq.push({T{}, src});
    while (!pq.empty()) {
        auto [d, v] = pq.top(); pq.pop();
        if (dist[v] < d) continue;
        for (auto& e : g[v]) {
            if (dist[v] + e.cost < dist[e.to]) {
                dist[e.to] = dist[v] + e.cost;
                pq.push({dist[e.to], e.to});
            }
        }
    }
    return dist;
}

// Dijkstra with prev edge for path reconstruction
template <class T, bool directed>
pair<vector<T>, vector<int>> dijkstra_prev(graph<T, directed, true>& g, int src) {
    int n = g.size();
    const T INF = numeric_limits<T>::max() / 2;
    vector<T> dist(n, INF);
    vector<int> prev(n, -1);
    priority_queue<pair<T,int>, vector<pair<T,int>>, greater<pair<T,int>>> pq;
    dist[src] = T{};
    pq.push({T{}, src});
    while (!pq.empty()) {
        auto [d, v] = pq.top(); pq.pop();
        if (dist[v] < d) continue;
        for (auto& e : g[v]) {
            if (dist[v] + e.cost < dist[e.to]) {
                dist[e.to] = dist[v] + e.cost;
                prev[e.to] = v;
                pq.push({dist[e.to], e.to});
            }
        }
    }
    return {dist, prev};
}

// Restore path from src to dst using prev array
vector<int> restore_path(const vector<int>& prev, int dst) {
    vector<int> path;
    for (int v = dst; v != -1; v = prev[v]) path.push_back(v);
    reverse(path.begin(), path.end());
    return path;
}
