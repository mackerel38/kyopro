#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"
#include "template"
#include "z_algorithm"

int main() {
    IO();
    int T = 1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    str s; cin >> s;
    auto v = z_algorithm(s);
    cout << v;
}
