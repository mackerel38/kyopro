#define PROBLEM "https://judge.yosupo.jp/problem/primality_test"
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
        ull n; cin >> n;
        cout << (is_prime(n) ? "Yes" : "No") << nl;
    }
}
