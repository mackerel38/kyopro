#pragma once
#include <bits/stdc++.h>
using namespace std;

// Sparse Table  O(n log n) build, O(1) query
// op must be IDEMPOTENT: op(x, x) == x  (e.g. min, max, gcd)
template <class S, auto op>
struct sparse_table {
    vector<vector<S>> d;
    vector<int> lg;

    sparse_table() = default;
    sparse_table(const vector<S>& v) { build(v); }

    void build(const vector<S>& v) {
        int n = v.size();
        lg.assign(n + 1, 0);
        for (int i = 2; i <= n; i++) lg[i] = lg[i >> 1] + 1;
        int k = lg[n] + 1;
        d.assign(k, vector<S>(n));
        d[0] = v;
        for (int j = 1; j < k; j++)
            for (int i = 0; i + (1 << j) <= n; i++)
                d[j][i] = op(d[j-1][i], d[j-1][i + (1 << (j-1))]);
    }

    // query [l, r)  (0-indexed, half-open)
    S query(int l, int r) const {
        int k = lg[r - l];
        return op(d[k][l], d[k][r - (1 << k)]);
    }
};
