#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"
#include "template"
#include "lazysegtree"
#include "modint"

int main() {
    IO();
    int T = 1;
    // cin >> T;
    while (T--) solve();
}

using S = pairs<mint>;
auto op = [](S x, S y) -> S{ return S{x.fi+y.fi, x.se+y.se}; };
auto e = []() -> S{ return S{0, 0}; };
using F = pairs<mint>;
auto mapping = [](F f, S s) -> S{ return S{f.fi*s.fi+f.se*s.se, s.se}; };
auto composition = [](F f, F g) -> F{ return F{f.fi*g.fi, f.fi*g.se+f.se}; };
auto id = []() -> F{ return F{1, 0}; };

void solve() {
    int n, q; cin >> n >> q;
    vector<S> a(n, S{0, 1}); range(i, a) cin >> i.fi;
    lazysegtree<S, op, e, F, mapping, composition, id> seg(a);
    rep(q) {
        int t; cin >> t;
        if (t == 0) {
            int l, r; mint b, c; cin >> l >> r >> b >> c;
            seg.apply(l, r, F{b, c});
        } else {
            int l, r; cin >> l >> r;
            cout << seg.prod(l, r).fi << nl;
        }
    }
}
