#include "template"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n; cin >> n;
    vi a(n); cin >> a;
    map<int, int> m;
    int ans = 0;
    rep(i, n) {
        chmax(m[a[i]], m[a[i]-1]+1);
        chmax(ans, m[a[i]]);
    }
    cout << ans << nl;
}
