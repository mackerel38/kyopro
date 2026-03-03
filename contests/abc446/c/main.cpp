#include "template"

int main() {
    IO();
    int T=1;
    cin >> T;
    while (T--) solve();
}

void solve() {
    int n, d; cin >> n >> d;
    vi a(n), b(n); cin >> a >> b;
    queue<pi> q;
    rep(i, n) {
        q.push({i, a[i]});
        while (b[i]) {
            int x = min(b[i], q.front().se);
            b[i] -= x;
            q.front().se -= x;
            if (q.front().se == 0) q.pop();
        }
        if (!q.empty() && d <= i - q.front().fi) q.pop();
    }
    ll ans = 0;
    while (!q.empty()) {
        ans += q.front().se; q.pop();
    }
    cout << ans << nl;
}
