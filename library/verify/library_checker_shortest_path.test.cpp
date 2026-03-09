#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"
#include "template"
#include "dijkstra"

int main() {
    IO();
    int T = 1;
    while (T--) solve();
}

void solve() {
    int n, m, s, t; cin >> n >> m >> s >> t;
    graph<ll, true, true> g(n);
    g.read(m, 0);
    auto [dist, prev] = dijkstra_prev(g, s);
    const ll INF = numeric_limits<ll>::max() / 2;
    if (dist[t] >= INF) {
        cout << -1 << nl;
        return;
    }
    auto path = restore_path(prev, t);
    cout << dist[t] << sp << (int)path.size() - 1 << nl;
    rep(i, (int)path.size() - 1) {
        cout << path[i] << sp << path[i + 1] << nl;
    }
}
