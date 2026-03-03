#include "template"
#include "graphtemplate"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, m; cin >> n >> m;
    graph<int, true, false> g(n); g.read(m);
    pqg<int> q; q.push(0);
    vi visited(n, 0); visited[0] = 1;
    vi ans(n, -1);
    rep(i, n) {
        auto x = q.top(); q.pop();
        range(e, g[x]) {
            if (!visited[e.to]) {
                visited[e.to] = 1;
                q.push(e.to);
            }
        }
        if (x <= i) ans[i]= 0;
    }
    range(i, ans) cout << i << nl;
}
