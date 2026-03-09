#define PROBLEM "https://judge.yosupo.jp/problem/majority_voting"
#include "template"
#include "segtree"

// Boyer-Moore voting merge as segtree monoid  S = {candidate, excess}
using S = pair<int, int>;
const auto bm_op = [](S a, S b) -> S {
    if (a.second == 0) return b;
    if (b.second == 0) return a;
    if (a.first == b.first) return {a.first, a.second + b.second};
    if (a.second > b.second) return {a.first, a.second - b.second};
    if (a.second < b.second) return {b.first, b.second - a.second};
    return {b.first, 0};
};
const auto bm_e = []() -> S { return {0, 0}; };

int main(){
    IO();
    int T = 1;
    while (T--) solve();
}

void solve(){
    int n, q; cin >> n >> q;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    // Precompute sorted positions per value for O(log n) count
    map<int, vector<int>> pos;
    rep(i, n) pos[a[i]].push_back(i);

    vector<S> sv(n);
    rep(i, n) sv[i] = {a[i], 1};
    segtree<S, bm_op, bm_e> seg(sv);

    rep(q){
        int l, r; cin >> l >> r;
        auto [cand, dummy] = seg.query(l, r);
        auto it = pos.find(cand);
        int cnt = 0;
        if (it != pos.end()){
            auto& v = it->second;
            cnt = (int)(lower_bound(v.begin(), v.end(), r) -
                        lower_bound(v.begin(), v.end(), l));
        }
        cout << (cnt * 2 > r - l ? cand : -1) << nl;
    }
}
