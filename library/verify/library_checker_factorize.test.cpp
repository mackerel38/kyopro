#define PROBLEM "https://judge.yosupo.jp/problem/factorize"
#include "template"
#include "prime"

int main() {
    IO();
    int T = 1;
    while (T--) solve();
}

void solve() {
    int q; cin >> q;
    rep(q) {
        ll a; cin >> a;
        auto f = factorize(a);
        cout << (int)f.size();
        for (auto x : f) cout << sp << x;
        cout << nl;
    }
}
