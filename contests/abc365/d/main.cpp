#include "template"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n; str t; cin >> n >> t;
    vi dpr(n+1), dps(n+1), dpp(n+1);
    rep(i, n) {
        if (t[i] == 'R') {
            dpr[i+1] = max(dps[i], dpp[i]);
            dps[i+1] = 0;
            dpp[i+1] = max(dpr[i], dps[i]) + 1;
        } elif (t[i] == 'S') {
            dpr[i+1] = max(dps[i], dpp[i]) + 1;
            dps[i+1] = max(dpp[i], dpr[i]);
            dpp[i+1] = 0;
        } else {
            dpr[i+1] = 0;
            dps[i+1] = max(dpp[i], dpr[i]) + 1;
            dpp[i+1] = max(dpr[i], dps[i]);
        }
    }
    cout << Max(dpr.back(), dps.back(), dpp.back()) << nl;
}
