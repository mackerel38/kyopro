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
    int m = b.size();
    rep(i, n) a[i] = (int)(lower_bound(b.begin(), b.end(), a[i]) - b.begin());

    // Inline BIT (1-indexed, size m)
    // bit_add(i, v): add v at position i+1  (i is 0-indexed compressed value)
    // bit_sum(i)   : sum of positions 1..i  = count with compressed value in [0, i)
    vector<ll> bit(m + 2, 0);
    auto bit_add = [&](int i, ll v){ for (i += 1; i <= m; i += i & -i) bit[i] += v; };
    auto bit_sum = [&](int i) -> ll { ll s = 0; for (; i > 0; i -= i & -i) s += bit[i]; return s; };

    mo mo_q(n);
    rep(i, q){ int l, r; cin >> l >> r; mo_q.add(l, r); }

    vector<ll> ans(q);
    ll cur = 0;
    int wsize = 0;

    // add_right(i): extend right to include a[i]
    //   new inversions = #{elements in window with value > a[i]}
    //                  = wsize - bit_sum(a[i] + 1)
    auto add_r = [&](int i){
        cur += wsize - bit_sum(a[i] + 1);
        bit_add(a[i], 1); wsize++;
    };
    // del_right(i): shrink right to exclude a[i]
    //   removed inversions = #{elements in window excl a[i] with value > a[i]}
    //                      = wsize - bit_sum(a[i] + 1)  (bit still includes a[i])
    auto del_r = [&](int i){
        cur -= wsize - bit_sum(a[i] + 1);
        bit_add(a[i], -1); wsize--;
    };
    // add_left(i): extend left to include a[i]
    //   a[i] becomes new leftmost; new inversions = #{in window with value < a[i]}
    //                                             = bit_sum(a[i])
    auto add_l = [&](int i){
        cur += bit_sum(a[i]);
        bit_add(a[i], 1); wsize++;
    };
    // del_left(i): shrink left to exclude a[i]
    //   removed inversions = #{in window excl a[i] with value < a[i]}
    //                      = bit_sum(a[i])  (a[i] itself not counted)
    auto del_l = [&](int i){
        bit_add(a[i], -1); wsize--;
        cur -= bit_sum(a[i]);
    };

    mo_q.run(add_l, del_l, add_r, del_r, [&](int qi){ ans[qi] = cur; });
    rep(i, q) cout << ans[i] << nl;
}
