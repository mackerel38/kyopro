#define PROBLEM "https://judge.yosupo.jp/problem/minimum_spanning_tree"
#include "template"
#include "kruskal"

int main() {
    IO();
    int T = 1;
    while (T--) solve();
}

void solve() {
    int n, m; cin >> n >> m;
    graph<ll, false, true> g(n);
    g.read(m, 0);
    auto [total, used] = kruskal(g);
    cout << total << nl;
    rep(i, (int)used.size()) {
        cout << used[i].id << (i + 1 == (int)used.size() ? '\n' : ' ');
    }
}
