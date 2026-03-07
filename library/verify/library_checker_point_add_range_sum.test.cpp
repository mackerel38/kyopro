#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include "template"
#include "segtree"

int main() {
    IO();
    int T = 1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, q; cin >> n >> q;
    vll a(n); cin >> a;
    segtree<ll, [](ll x,ll y){return x+y;}, [](){return 0LL;}> seg(a);
    rep(q) {
        int t; cin >> t;
        if (t == 0) {
            int p, x; cin >> p >> x;
            seg.add(p, x);
        } else {
            int l, r; cin >> l >> r;
            cout << seg.prod(l, r) << nl;
        }
    }
}
