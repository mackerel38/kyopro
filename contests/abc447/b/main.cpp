#include "template"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    str s; cin >> s;
    vi a(26); range(i, s) a[i-'a']++;
    int M = Max(a);
    range(i, s) if (a[i-'a'] != M) cout << i; cout << nl;
}
