#pragma once
#include <bits/stdc++.h>
using namespace std;

// Weighted Union Find  (potentials on an abelian group)
//
// weight(x) is defined relative to root:  pot[root] = 0, pot[x] = d(root -> x)
// weight(x, y) := pot[y] - pot[x]  = d(x -> y)
//
// merge(x, y, w):  set  weight(x, y) = w  (= pot[y] - pot[x])
//   returns true if successful (no contradiction), false if already connected
// same(x, y):  returns true if x and y are in the same component
// diff(x, y):  returns pot[y] - pot[x]  (UB if !same(x,y))
//
// T: value type with operator+ and operator-  (e.g. long long)

template <class T = long long>
struct weighted_unionfind {
    vector<int> par;
    vector<T>   pot;  // pot[x] = d(par[x] -> x)   (pot[root] = 0)
    vector<int> rank_;

    weighted_unionfind() = default;
    weighted_unionfind(int n) : par(n), pot(n, T{}), rank_(n, 0) {
        iota(par.begin(), par.end(), 0);
    }

    // returns {root, potential of x relative to root}
    pair<int, T> find(int x) {
        if (par[x] == x) return {x, T{}};
        auto [r, p] = find(par[x]);
        par[x] = r;
        pot[x] += p;
        return {r, pot[x]};
    }

    bool same(int x, int y) { return find(x).first == find(y).first; }

    // potential of x relative to component root
    T potential(int x) { return find(x).second; }

    // d(x -> y) = pot[y] - pot[x]
    T diff(int x, int y) { return potential(y) - potential(x); }

    // set weight(x->y) = w  (pot[y] - pot[x] = w)
    // returns false if already in same component (constraint check only)
    bool merge(int x, int y, T w) {
        // w = pot[y] - pot[x]
        // transform to root-relative
        auto [rx, px] = find(x);
        auto [ry, py] = find(y);
        if (rx == ry) return false; // already connected
        // want: pot[y_new_root_side] - pot[x_new_root_side] = w
        // pot[y] = py (relative to ry), pot[x] = px (relative to rx)
        // w = py + pot[ry] - (px + pot[rx])  after merge
        // => merge ry under rx:  pot[ry] = w + px - py
        w = w + px - py;
        if (rank_[rx] < rank_[ry]) { swap(rx, ry); w = -w; }
        par[ry] = rx;
        pot[ry] = w;
        if (rank_[rx] == rank_[ry]) ++rank_[rx];
        return true;
    }
};
