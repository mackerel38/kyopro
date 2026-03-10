#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_primes"
#include "template"
#include "prime"

int main() {
    IO();
    int T = 1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, a, b; cin >> n >> a >> b;
    vi p = enumprimes(n);
    vi q;
    rep(i, b, p.size(), a) q.pb(p[i]);
    cout << len(p) << sp << len(q) << nl << q;
}
