#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include "template"
#include "BIT"

int main() {
    IO();
    int T = 1;
    while (T--) solve();
}

void solve() {
    int n, q; cin >> n >> q;
    vll a(n); cin >> a;
    BIT<ll> seg(a);
    rep(q) {
        int t; cin >> t;
        if (t == 0) {
            int p; ll x; cin >> p >> x;
            seg.add(p, x);
        } else {
            int l, r; cin >> l >> r;
            cout << seg.sum(l, r) << nl;
        }
    }
}
