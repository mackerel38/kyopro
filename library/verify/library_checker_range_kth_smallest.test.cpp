#define PROBLEM "https://judge.yosupo.jp/problem/range_kth_smallest"
#include "template"
#include "wavelet_matrix"

int main() {
    IO();
    int T = 1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n); cin >> a;
    auto b = a;
    uniq(b);
    range(i, a) i = lower_bound(all(b), i) - b.begin();
    wavelet_matrix<20> wm; wm.build(a);
    rep(q) {
        int l, r, k; cin >> l >> r >> k;
        cout << b[wm.kth(l, r, k)] << nl;
    }
}
