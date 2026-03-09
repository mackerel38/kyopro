#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"
#include "template"
#include "lazysegtree"
#include "modint"

// S = (sum, count),  F = (b, c) meaning x -> b*x + c
using S = pair<mint, mint>;
using F = pair<mint, mint>;

const auto seg_op   = [](S a, S b) -> S { return {a.first + b.first, a.second + b.second}; };
const auto seg_e    = []()         -> S { return {mint(0), mint(0)}; };
const auto seg_map  = [](F f, S s) -> S { return {f.first * s.first + f.second * s.second, s.second}; };
const auto seg_comp = [](F f, F g) -> F { return {f.first * g.first, f.first * g.second + f.second}; };
const auto seg_id   = []()         -> F { return {mint(1), mint(0)}; };

int main() {
    IO();
    int T = 1;
    while (T--) solve();
}

void solve() {
    int n, q; cin >> n >> q;
    vector<S> a(n);
    rep(i, n) { mint v; cin >> v; a[i] = {v, mint(1)}; }
    lazysegtree<S, seg_op, seg_e, F, seg_map, seg_comp, seg_id> seg(a);
    rep(q) {
        int t; cin >> t;
        if (t == 0) {
            int l, r; mint b, c; cin >> l >> r >> b >> c;
            seg.apply(l, r, {b, c});
        } else {
            int l, r; cin >> l >> r;
            cout << seg.query(l, r).first << nl;
        }
    }
}
