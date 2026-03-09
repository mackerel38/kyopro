#define PROBLEM "https://judge.yosupo.jp/problem/unionfind_with_potential"
#include "template"
#include "weighted_unionfind"
#include "modint"

// Constraint: a[u] ≡ a[v] + x (mod p)  ↔  a[u] - a[v] = x
// Our library: diff(x, y) = pot[y] - pot[x]
//   a[u] - a[v] = diff(v, u)
//   So merge(v, u, x) sets pot[u] - pot[v] = x  ✓
//   Query: diff(v, u) = a[u] - a[v]  ✓

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
            mint x; cin >> x;
            if (!uf.same(u, v)){
                // a[u] = a[v] + x  =>  a[u] - a[v] = x  =>  diff(v, u) = x
                uf.merge(v, u, x);
                cout << 1 << nl;
            } else {
                // check consistency: a[u] - a[v] = diff(v, u)
                cout << (uf.diff(v, u) == x ? 1 : 0) << nl;
            }
        } else {
            if (!uf.same(u, v)) cout << -1 << nl;
            else cout << uf.diff(v, u) << nl;
        }
    }
}
