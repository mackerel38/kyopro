#pragma once
#include <bits/stdc++.h>
using namespace std;

// Weighted Union Find with potential  (abelian group on T)
// Reference: Nyaan's Library
//
// Semantics:
//   potential(x)      : value of x relative to its component root (pot[root] = 0)
//   diff(x, y)        : potential(y) - potential(x)  (= w(x->y))
//   merge(x, y, w)    : declare diff(x, y) = w
//                       returns true  if merged successfully (x and y were in different components)
//                       returns false if x and y were already in the same component
//                         (in this case the constraint is checked: true iff consistent)
//   same(x, y)        : true iff x and y are in the same component

template <class T = long long>
struct weighted_unionfind {
    vector<int> par, sz;
    vector<T>   pot;  // pot[x] = d(par[x] -> x); pot[root] = 0 after find

    weighted_unionfind() = default;
    weighted_unionfind(int n) : par(n), sz(n, 1), pot(n, T{}) {
        iota(par.begin(), par.end(), 0);
    }

    // Returns {root, potential of x relative to root}.
    // Applies path compression: pot[x] becomes d(root -> x).
    pair<int, T> find(int x) {
        if (par[x] == x) return {x, T{}};
        auto [r, d] = find(par[x]);
        pot[x] += d;
        par[x] = r;
        return {par[x], pot[x]};
    }

    bool same(int x, int y) { return find(x).first == find(y).first; }

    T potential(int x) { return find(x).second; }

    // diff(x, y) = potential(y) - potential(x)
    T diff(int x, int y) { return potential(y) - potential(x); }

    // merge(x, y, w): declare diff(x, y) = w  (i.e. pot[y] - pot[x] = w)
    // Returns true  if x and y were in different components (merged).
    // Returns false if already in same component;
    //   the return value in that case also indicates consistency: true=consistent, false=contradiction.
    bool merge(int x, int y, T w) {
        // Adjust w to be root-relative: w_root = w + pot[x] - pot[y]
        w += potential(x) - potential(y);
        int rx = find(x).first;
        int ry = find(y).first;
        if (rx == ry) return w == T{};  // already connected: check consistency
        // Union by size
        if (sz[rx] < sz[ry]) { swap(rx, ry); w = -w; }
        sz[rx] += sz[ry];
        par[ry] = rx;
        pot[ry] = w;
        return true;
    }
};
