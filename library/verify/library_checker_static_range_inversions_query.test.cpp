#define PROBLEM "https://judge.yosupo.jp/problem/static_range_inversions_query"
#include "template"
#include "mo"

int main(){
    IO();
    int T = 1;
    while (T--) solve();
}

void solve(){
    int n, q; cin >> n >> q;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    // Coordinate compress
    vector<int> b = a;
    sort(b.begin(), b.end()); b.erase(unique(b.begin(), b.end()), b.end());
    int m = (int)b.size();
    rep(i, n) a[i] = (int)(lower_bound(b.begin(), b.end(), a[i]) - b.begin());

    // Fenwick tree (rename to fw to avoid conflict with 'bit' macro)
    vector<ll> fw(m + 2, 0);
    auto fw_add = [&](int i, ll v){ for (i += 1; i <= m; i += i & -i) fw[i] += v; };
    auto fw_sum = [&](int i) -> ll { ll s = 0; for (; i > 0; i -= i & -i) s += fw[i]; return s; };

    mo mo_q(n);
    rep(i, q){ int l, r; cin >> l >> r; mo_q.add(l, r); }

    vector<ll> ans(q);
    ll cur = 0;
    int wsize = 0;

    auto add_r = [&](int i){
        cur += wsize - fw_sum(a[i] + 1);
        fw_add(a[i], 1); wsize++;
    };
    auto del_r = [&](int i){
        cur -= wsize - fw_sum(a[i] + 1);
        fw_add(a[i], -1); wsize--;
    };
    auto add_l = [&](int i){
        cur += fw_sum(a[i]);
        fw_add(a[i], 1); wsize++;
    };
    auto del_l = [&](int i){
        fw_add(a[i], -1); wsize--;
        cur -= fw_sum(a[i]);
    };

    mo_q.run(add_l, del_l, add_r, del_r, [&](int qi){ ans[qi] = cur; });
    rep(i, q) cout << ans[i] << nl;
}
