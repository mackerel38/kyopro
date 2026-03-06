#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"
#include "template"
#include "unionfind"

int main() {
    IO();
    int T = 1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, q; cin >> n >> q;
    unionfind uf(n);
    rep(q) {
        int t, u, v; cin >> t >> u >> v;
        if (t == 0) uf.merge(u, v);
        else cout << uf.same(u, v) << nl;
    }
}
