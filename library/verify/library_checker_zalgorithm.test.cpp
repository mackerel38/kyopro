#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"
#include "template"
#include "z_algorithm"

int main() {
    IO();
    int T = 1;
    while (T--) solve();
}

void solve() {
    string s; cin >> s;
    auto z = z_algorithm(s);
    rep(i, (int)z.size()) {
        cout << z[i] << (i + 1 == (int)z.size() ? '\n' : ' ');
    }
}
