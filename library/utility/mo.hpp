#pragma once
#include <bits/stdc++.h>
using namespace std;

// Mo's algorithm  O((N + Q) sqrt(N)) offline range queries
//
// Usage:
//   mo m(n);
//   m.add(l, r);   // register query [l, r)  (half-open)
//   m.run(add_l, del_l, add_r, del_r, query_fn);
//
// Callbacks:
//   add_l(i)  : extend  left  boundary to include index i
//   del_l(i)  : shrink  left  boundary to exclude index i
//   add_r(i)  : extend  right boundary (called with index = new r-1)
//   del_r(i)  : shrink  right boundary (called with index = old r-1)
//   query(qi) : answer query qi  (qi is the order of m.add calls)
//
// Current window is always [curL, curR) during execution.
struct mo {
    int n;
    vector<pair<int,int>> qs;

    mo() = default;
    mo(int n) : n(n) {}

    void add(int l, int r) { qs.push_back({l, r}); }

    template <class AL, class DL, class AR, class DR, class Q>
    void run(AL add_l, DL del_l, AR add_r, DR del_r, Q query) {
        int q = qs.size();
        if (q == 0) return;
        int block = max(1, (int)sqrt(n));
        vector<int> ord(q);
        iota(ord.begin(), ord.end(), 0);
        sort(ord.begin(), ord.end(), [&](int a, int b) {
            int ba = qs[a].first / block, bb = qs[b].first / block;
            if (ba != bb) return ba < bb;
            return (ba & 1) ? qs[a].second > qs[b].second
                            : qs[a].second < qs[b].second;
        });
        int l = 0, r = 0;
        for (int i : ord) {
            int ql = qs[i].first, qr = qs[i].second;
            while (r < qr) add_r(r++);
            while (l > ql) add_l(--l);
            while (r > qr) del_r(--r);
            while (l < ql) del_l(l++);
            query(i);
        }
    }
};
