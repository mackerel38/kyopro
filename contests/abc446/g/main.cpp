#include "template"
#include "modint"
using mint = modint<998244353>;

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n; cin >> n;
    vi a(n); cin >> a;
    vec<vec<mint>> dp(n+1, vec<mint>(n+1));
    rep1(i, n) rep(j, n) {
        ;
    }
}
