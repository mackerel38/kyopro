#define PROBLEM "https://judge.yosupo.jp/problem/factorize"
#include "template"
#include "prime"

int main() {
    IO();
    int T = 1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int q; cin >> q;
    rep(q) {
        ll n; cin >> n;
        vll p = factorize(n);
        cout << ssize(p) << sp << p;
    }
}
