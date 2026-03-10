#define PROBLEM "https://judge.yosupo.jp/problem/minimum_spanning_tree"
#include "template"
#include "kruskal"

int main() {
    IO();
    int T = 1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, m; cin >> n >> m;
    graph<ll, false,  true> g(n); g.read(m, 0);
    auto [s, e] = kruskal(g);
    cout << s << nl;
    range(i, e) cout << i.id << sp;
    cout << nl;
}
