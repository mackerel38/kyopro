#pragma once
#include <bits/stdc++.h>
using namespace std;

// Dijkstra: returns shortest distances from src
// graph: adjacency list of (to, weight)
template <class T = long long>
vector<T> dijkstra(const vector<vector<pair<int,T>>>& graph, int src) {
    int n = graph.size();
    const T INF = numeric_limits<T>::max() / 2;
    vector<T> dist(n, INF);
    priority_queue<pair<T,int>, vector<pair<T,int>>, greater<pair<T,int>>> pq;
    dist[src] = T{};
    pq.push({T{}, src});
    while (!pq.empty()) {
        auto [d, v] = pq.top(); pq.pop();
        if (dist[v] < d) continue;
        for (auto [u, w] : graph[v]) {
            if (dist[v] + w < dist[u]) {
                dist[u] = dist[v] + w;
                pq.push({dist[u], u});
            }
        }
    }
    return dist;
}

// Dijkstra with prev array for path reconstruction
template <class T = long long>
pair<vector<T>, vector<int>> dijkstra_prev(const vector<vector<pair<int,T>>>& graph, int src) {
    int n = graph.size();
    const T INF = numeric_limits<T>::max() / 2;
    vector<T> dist(n, INF);
    vector<int> prev(n, -1);
    priority_queue<pair<T,int>, vector<pair<T,int>>, greater<pair<T,int>>> pq;
    dist[src] = T{};
    pq.push({T{}, src});
    while (!pq.empty()) {
        auto [d, v] = pq.top(); pq.pop();
        if (dist[v] < d) continue;
        for (auto [u, w] : graph[v]) {
            if (dist[v] + w < dist[u]) {
                dist[u] = dist[v] + w;
                prev[u] = v;
                pq.push({dist[u], u});
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
