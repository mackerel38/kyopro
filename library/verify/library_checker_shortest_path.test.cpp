#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"
#include "template"
#include "dijkstra"

int main() {
    IO();
    int T = 1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, m, s, t; cin >> n >> m >> s >> t;
    graph<ll, true, true> g(n);
    g.read(m, 0);
    auto [d, pre] = dijkstra_prev(g, s);
    if (inf < d[t]) {
        cout << -1 << nl;
        return;
    }
    auto path = restore_path(pre, t);
    cout << d[t] << sp << len(path)-1 << nl;
    rep(i, len(path)-1) cout << path[i] << sp << path[i+1] << nl;
}
