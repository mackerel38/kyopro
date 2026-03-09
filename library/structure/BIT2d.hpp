#pragma once
#include <bits/stdc++.h>
using namespace std;

// 2D BIT (Fenwick tree)
// (1) Dense 2D BIT  O(H*W) space, O(log H * log W) per query
// (2) Compressed 2D BIT (offline)  for point_add_rectangle_sum

// --- Dense 2D BIT ---
template <class T = long long>
struct BIT2d {
    int h, w;
    vector<vector<T>> bit;

    BIT2d() = default;
    BIT2d(int h, int w) : h(h), w(w), bit(h + 1, vector<T>(w + 1, 0)) {}

    // add v to point (x, y)  (1-indexed)
    void add(int x, int y, T v) {
        for (int i = x; i <= h; i += i & -i)
            for (int j = y; j <= w; j += j & -j)
                bit[i][j] += v;
    }

    // sum of [1, x] x [1, y]  (1-indexed)
    T sum(int x, int y) const {
        T s = 0;
        for (int i = x; i > 0; i -= i & -i)
            for (int j = y; j > 0; j -= j & -j)
                s += bit[i][j];
        return s;
    }

    // sum of [lx, rx] x [ly, ry]  (1-indexed, inclusive)
    T sum(int lx, int rx, int ly, int ry) const {
        return sum(rx, ry) - sum(lx - 1, ry) - sum(rx, ly - 1) + sum(lx - 1, ly - 1);
    }
};

// --- Compressed 2D BIT (offline) ---
// For each x-coordinate, maintain a 1D BIT over y-coordinates
// that are actually used.  O(Q log Q) time, O(Q log Q) space.
template <class T = long long>
struct BIT2d_compressed {
    int n; // x size
    vector<vector<int>> ys;   // sorted y-coords for each x
    vector<vector<T>>   bit;
    bool built = false;

    BIT2d_compressed() = default;
    BIT2d_compressed(int n) : n(n), ys(n + 1), bit(n + 1) {}

    // register point (x, y) before build  (1-indexed x)
    void reserve(int x, int y) {
        for (int i = x; i <= n; i += i & -i) ys[i].push_back(y);
    }

    void build() {
        for (int i = 1; i <= n; i++) {
            sort(ys[i].begin(), ys[i].end());
            ys[i].erase(unique(ys[i].begin(), ys[i].end()), ys[i].end());
            bit[i].assign(ys[i].size() + 1, 0);
        }
        built = true;
    }

    void _add(int x, int y, T v) {
        int j = lower_bound(ys[x].begin(), ys[x].end(), y) - ys[x].begin() + 1;
        for (; j <= (int)ys[x].size(); j += j & -j) bit[x][j] += v;
    }
    T _sum(int x, int y) const {
        int j = upper_bound(ys[x].begin(), ys[x].end(), y) - ys[x].begin();
        T s = 0;
        for (; j > 0; j -= j & -j) s += bit[x][j];
        return s;
    }

    // add v to point (x, y)  (1-indexed)
    void add(int x, int y, T v) {
        for (int i = x; i <= n; i += i & -i) _add(i, y, v);
    }

    // prefix sum [1,x] x [-inf, y]
    T sum(int x, int y) const {
        T s = 0;
        for (int i = x; i > 0; i -= i & -i) s += _sum(i, y);
        return s;
    }

    // sum of [lx, rx] x [ly, ry]  (1-indexed x, arbitrary y)
    T sum(int lx, int rx, int ly, int ry) const {
        return sum(rx, ry) - sum(lx - 1, ry) - sum(rx, ly - 1) + sum(lx - 1, ly - 1);
    }
};
