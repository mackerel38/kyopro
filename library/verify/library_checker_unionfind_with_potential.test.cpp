#define PROBLEM "https://judge.yosupo.jp/problem/unionfind_with_potential"
#include "template"
#include "weighted_unionfind"
#include "modint"

// Group operation: addition mod 998244353  (use mint)

int main(){
    IO();
    int T = 1;
    while (T--) solve();
}

void solve(){
    int n, q; cin >> n >> q;
    weighted_unionfind<mint> uf(n);
    rep(q){
        int t, u, v; cin >> t >> u >> v;
        if (t == 0){
            // Assert diff(u -> v) = w.  Output 1 if consistent, 0 if contradiction.
            mint w; cin >> w;
            if (!uf.same(u, v)){
                uf.merge(u, v, w);
                cout << 1 << nl;
            } else {
                cout << (uf.diff(u, v) == w ? 1 : 0) << nl;
            }
        } else {
            // Query diff(u -> v).  Output -1 if not connected.
            if (!uf.same(u, v)) cout << -1 << nl;
            else cout << uf.diff(u, v) << nl;
        }
    }
}
