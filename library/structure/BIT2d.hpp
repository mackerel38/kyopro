#pragma once
#include <bits/stdc++.h>
using namespace std;

// 2D Fenwick (BIT) tree
// (1) Dense 2D: O(H*W) space, O(log H * log W) per query
// (2) Compressed 2D (offline): for point_add_rectangle_sum etc.

// --- Dense 2D BIT ---
template <class T = long long>
struct BIT2d {
    int h, w;
    vector<vector<T>> fw;  // fw = Fenwick

    BIT2d() = default;
    BIT2d(int h, int w) : h(h), w(w), fw(h + 1, vector<T>(w + 1, 0)) {}

    // add v to point (x, y)  1-indexed
    void add(int x, int y, T v) {
        for (int i = x; i <= h; i += i & -i)
            for (int j = y; j <= w; j += j & -j)
                fw[i][j] += v;
    }

    // prefix sum [1,x] x [1,y]  1-indexed
    T sum(int x, int y) const {
        T s = 0;
        for (int i = x; i > 0; i -= i & -i)
            for (int j = y; j > 0; j -= j & -j)
                s += fw[i][j];
        return s;
    }

    // sum [lx,rx] x [ly,ry]  1-indexed inclusive
    T sum(int lx, int rx, int ly, int ry) const {
        return sum(rx, ry) - sum(lx - 1, ry) - sum(rx, ly - 1) + sum(lx - 1, ly - 1);
    }
};

// --- Compressed 2D BIT (offline) ---
// For each x-coordinate, maintain a 1D Fenwick over y-coordinates actually used.
// O(Q log Q) time + space.
template <class T = long long>
struct BIT2d_compressed {
    int n;  // x-axis size
    vector<vector<int>> ys;   // sorted y-coords per x BIT node
    vector<vector<T>>   fw;   // Fenwick values
    bool built = false;

    BIT2d_compressed() = default;
    BIT2d_compressed(int n) : n(n), ys(n + 1), fw(n + 1) {}

    // register point (x, y) before build  (1-indexed x)
    void reserve(int x, int y) {
        for (int i = x; i <= n; i += i & -i) ys[i].push_back(y);
    }

    void build() {
        for (int i = 1; i <= n; i++) {
            sort(ys[i].begin(), ys[i].end());
            ys[i].erase(unique(ys[i].begin(), ys[i].end()), ys[i].end());
            fw[i].assign(ys[i].size() + 1, 0);
        }
        built = true;
    }

    void _fw_add(int x, int y, T v) {
        int j = (int)(lower_bound(ys[x].begin(), ys[x].end(), y) - ys[x].begin()) + 1;
        for (; j <= (int)ys[x].size(); j += j & -j) fw[x][j] += v;
    }
    T _fw_sum(int x, int y) const {
        int j = (int)(upper_bound(ys[x].begin(), ys[x].end(), y) - ys[x].begin());
        T s = 0;
        for (; j > 0; j -= j & -j) s += fw[x][j];
        return s;
    }

    void add(int x, int y, T v) {
        for (int i = x; i <= n; i += i & -i) _fw_add(i, y, v);
    }

    T sum(int x, int y) const {
        T s = 0;
        for (int i = x; i > 0; i -= i & -i) s += _fw_sum(i, y);
        return s;
    }

    T sum(int lx, int rx, int ly, int ry) const {
        return sum(rx, ry) - sum(lx - 1, ry) - sum(rx, ly - 1) + sum(lx - 1, ly - 1);
    }
};
