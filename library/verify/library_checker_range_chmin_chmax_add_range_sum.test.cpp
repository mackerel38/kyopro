#define PROBLEM "https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum"
#include "template"
#include "segment_beats"

int main(){
    IO();
    int T = 1;
    while (T--) solve();
}

void solve(){
    int n, q; cin >> n >> q;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    segment_beats sb(a);
    rep(q){
        int t; cin >> t;
        if (t == 0){
            // range chmin: a[i] = min(a[i], b) for i in [l, r)
            int l, r; ll b; cin >> l >> r >> b;
            sb.range_chmin(l, r, b);
        } else if (t == 1){
            // range chmax: a[i] = max(a[i], b) for i in [l, r)
            int l, r; ll b; cin >> l >> r >> b;
            sb.range_chmax(l, r, b);
        } else if (t == 2){
            // range add: a[i] += b for i in [l, r)
            int l, r; ll b; cin >> l >> r >> b;
            sb.range_add(l, r, b);
        } else {
            // range sum query
            int l, r; cin >> l >> r;
            cout << sb.query_sum(l, r) << nl;
        }
    }
}
