#include "template"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, m; cin >> n >> m;
    vi a(m+1, 1);
    rep(i, n) {
        int l; cin >> l;
        vi b(l); cin >> b;
        range(x, b) {
            if (a[x]) {
                a[x]--;
                cout << x << nl;
                goto no;
            }
        }
        cout << 0 << nl; no:
    }
}
