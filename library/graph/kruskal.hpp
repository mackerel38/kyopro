#pragma once
#include "graphtemplate.hpp"

// Kruskal MST
// Use: graph<T, false, true> (undirected, weighted)
// Returns {total_weight, edges_used}
template <class T>
pair<T, edges<T>> kruskal(graph<T, false, true>& g) {
    int n = g.size();
    // Union-Find (inline)
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

    // Sort edges by cost
    edges<T> sorted_edges = g._edges;
    sort(sorted_edges.begin(), sorted_edges.end(),
         [](const edge<T>& a, const edge<T>& b){ return a.cost < b.cost; });

    T total = T{};
    edges<T> used;
    for (auto& e : sorted_edges) {
        if (uf_merge(e.from, e.to)) {
            total += e.cost;
            used.push_back(e);
        }
    }
    return {total, used};
}
