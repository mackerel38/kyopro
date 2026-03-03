#include "template"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, m; cin >> n >> m;
    vll a(n); cin >> a;
    vvpll g(n);
    rep(i, m) {
        int x, y; ll c; cin >> x >> y >> c; x--; y--;
        g[x].pb(y, c);
        g[y].pb(x, c);
    }
    vll d(n, infty<ll>); d[0] = a[0];
    pqg<pair<ll, int>> q; q.push({a[0], 0});
    while (!q.empty()) {
        auto [c, x] = q.top(); q.pop();
        if (d[x] < c) continue;
        range(y, C, g[x]) {
            if (chmin(d[y], a[y]+C+d[x])) q.push({d[y], y});
        }
    }
    rep(i, 1, n) cout << d[i] << sp;
    cout << nl;
}
