#pragma once
#include "graphtemplate.hpp"

// BFS: returns distance from src (-1 if unreachable)
// graph<T, directed, weighted> (T=int, unweighted)
template <class T, bool directed, bool weighted>
vector<long long> bfs(graph<T, directed, weighted>& g, int src) {
    int n = g.size();
    vector<long long> dist(n, -1);
    queue<int> q;
    dist[src] = 0;
    q.push(src);
    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (auto& e : g[v]) {
            if (dist[e.to] == -1) {
                dist[e.to] = dist[v] + 1;
                q.push(e.to);
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
