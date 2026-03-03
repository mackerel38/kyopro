#include "template"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int m, a, b; cin >> m >> a >> b;
    vvvpi g(m, vvpi(m));
    vvi f(m, vi(m));
    queue<pi> q;
    int ans = m * m;
    rep(i, m) rep(j, m) {
        int J = (j*a+i*b)%m; int I = j;
        g[I][J].pb({i, j});
        if (J == 0) {
            f[i][j] = 1;
            q.push({i, j});
        }
        if (min(i, j) == 0) if (chmax(f[i][j], 1)) ans--;
    }
    while (!q.empty()) {
        ans--;
        auto [x, y] = q.front(); q.pop();
        range2(i, j, g[x][y]) if (chmax(f[i][j], 1)) q.push({i, j});
    }
    cout << ans << nl;
}
