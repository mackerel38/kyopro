#define PROBLEM "https://judge.yosupo.jp/problem/queue_operate_all_composite"
#include "template"
#include "swag"
#include "modint"

int main() {
    IO();
    int T = 1;
    // cin >> T;
    while (T--) solve();
}

using S = pairs<mint>;
auto op = [](S x, S y) -> S{ return S{x.fi*y.fi, y.fi*x.se+y.se}; };
auto e = []() -> S{ return S{1, 0}; };

void solve() {
    int q; cin >> q;
    swag<S, op, e> sw;
    rep(q) {
        int t; cin >> t;
        if (t == 0) {
            mint a, b; cin >> a >> b;
            sw.push_back({a, b});
        } elif (t == 1) sw.pop_front();
        else {
            mint x; cin >> x;
            auto [a, b] = sw.fold();
            cout << a * x + b << nl;
        }
    }
}
