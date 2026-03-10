#define PROBLEM "https://judge.yosupo.jp/problem/associative_array"
#include "template"
#include "hashmap"

int main() {
    IO();
    int T = 1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    hashmap<ll, ll> hm;
    int q; cin >> q;
    rep(q) {
        int t; cin >> t;
        if (t == 0) {
            ll k, v; cin >> k >> v;
            hm[k] = v;
        } else {
            ll k; cin >> k;
            cout << hm[k] << nl;
        }
    }
}
