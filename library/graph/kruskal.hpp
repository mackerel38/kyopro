#pragma once
#include <bits/stdc++.h>
using namespace std;

// Kruskal MST
// edges: vector of {weight, u, v}
// Returns {total_weight, edges_used}
template <class T = long long>
pair<T, vector<tuple<T,int,int>>> kruskal(int n, vector<tuple<T,int,int>> edges) {
    vector<int> data(n, -1);
    function<int(int)> root = [&](int k) -> int {
        return data[k] < 0 ? k : data[k] = root(data[k]);
    };
    auto uf_merge = [&](int x, int y) -> bool {
        if ((x = root(x)) == (y = root(y))) return false;
        if (data[x] < data[y]) swap(x, y);
        data[y] += data[x];
        data[x] = y;
        return true;
    };

    sort(edges.begin(), edges.end());
    T total = T{};
    vector<tuple<T,int,int>> used;
    for (auto [w, u, v] : edges) {
        if (uf_merge(u, v)) {
            total += w;
            used.emplace_back(w, u, v);
        }
    }
    return {total, used};
}
