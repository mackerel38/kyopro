#define PROBLEM "https://judge.yosupo.jp/problem/static_range_inversions_query"
#include "template"
#include "mo"
#include "BIT"

int main() {
    IO();
    int T = 1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, q; cin >> n >> q;
    vi a(n); cin >> a;
    vi b = a;
    uniq(b);
    int m = len(b);
    range(i, a) i = lower_bound(all(b), i) - b.begin();
    vll ans(q);
    mo Mo(q);
    vpi queries(q);
    rep(i, q) {
        int l, r; cin >> l >> r;
        queries[i] = {l, r};
        Mo.add(l, r);
    }
    BIT<int> seg(m);
    ll cnt = 0;
    auto al = [&](int x) {
        cnt += seg.sum(0, a[x]);
        seg.add(a[x], 1);
    };
    auto ar = [&](int x) {
        cnt += seg.sum(a[x]+1, m);
        seg.add(a[x], 1);
    };
    auto el = [&](int x) {
        seg.add(a[x], -1);
        cnt -= seg.sum(0, a[x]);
    };
    auto er = [&](int x) {
        seg.add(a[x], -1);
        cnt -= seg.sum(a[x]+1, m);
    };
    auto out = [&](int x) { ans[x] = cnt; };
    Mo.run(al, ar, el, er, out);
    cout << ans;
}
