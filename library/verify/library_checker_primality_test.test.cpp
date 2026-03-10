#define PROBLEM "https://judge.yosupo.jp/problem/primality_test"
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
        ull x; cin >> x;
        YN(is_prime(x));
    }
}
