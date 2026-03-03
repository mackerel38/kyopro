#include "template"
#include "structure/unionfind.hpp"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, m; cin >> n >> m;
    unionfind uf(n);
    vpi e(m);
    rep(i, m) {
        int x, y; cin >> x >> y; x--; y--;
        uf.merge(x, y);
        e[i] = {x, y};
    }
    vi cntv(n), cnte(n);
    rep(i, n) cntv[uf.find(i)]++;
    range(i, j, e) cnte[uf.find(i)]++;
    rep(i, n) if (cntv[i] != cnte[i]) { No; return; }
    Yes;
}
