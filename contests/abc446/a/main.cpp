#include "template"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    str s; cin >> s;
    cout << "Of" << (char)(s[0]^32) << s.substr(1, s.size()-1) << nl;
}
