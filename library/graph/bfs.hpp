#pragma once
#include <bits/stdc++.h>
using namespace std;

// BFS: returns distance from src (-1 if unreachable)
template <class Graph = vector<vector<int>>>
vector<long long> bfs(const Graph& graph, int src) {
    int n = graph.size();
    vector<long long> dist(n, -1);
    queue<int> q;
    dist[src] = 0;
    q.push(src);
    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (int u : graph[v]) {
            if (dist[u] == -1) {
                dist[u] = dist[v] + 1;
                q.push(u);
            }
        }
    }
    return dist;
}

// BFS on grid (4-directional)
// passable[r][c] == true means the cell can be entered
vector<vector<long long>> bfs_grid(const vector<vector<bool>>& passable, int sr, int sc) {
    int H = passable.size(), W = passable[0].size();
    const int DR[] = {0, 1, 0, -1};
    const int DC[] = {1, 0, -1, 0};
    vector<vector<long long>> dist(H, vector<long long>(W, -1));
    queue<pair<int,int>> q;
    dist[sr][sc] = 0;
    q.push({sr, sc});
    while (!q.empty()) {
        auto [r, c] = q.front(); q.pop();
        for (int d = 0; d < 4; d++) {
            int nr = r + DR[d], nc = c + DC[d];
            if (0<=nr && nr<H && 0<=nc && nc<W
             && passable[nr][nc] && dist[nr][nc] == -1) {
                dist[nr][nc] = dist[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }
    return dist;
}
