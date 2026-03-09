#define PROBLEM "https://judge.yosupo.jp/problem/majority_voting"
#include "template"
#include "majority_vote"

// Policy-based order-statistics tree for O(log n) rank queries
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using pbds_set = tree<int, null_type, less<int>,
                       rb_tree_tag, tree_order_statistics_node_update>;

int main(){
    IO();
    int T = 1;
    while (T--) solve();
}

void solve(){
    int n, q; cin >> n >> q;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    // BM segtree for candidate queries
    majority_segtree<int> ms(a);

    // positions[v] = sorted set of indices where a[i] == v
    // Use pb_ds for O(log n) count in range [l, r)
    map<int, pbds_set> pos;
    rep(i, n) pos[a[i]].insert(i);

    rep(q){
        int t; cin >> t;
        if (t == 0){
            // point update: a[p] = x
            int p, x; cin >> p >> x;
            pos[a[p]].erase(p);
            a[p] = x;
            pos[x].insert(p);
            ms.set(p, x);
        } else {
            // range majority query [l, r)
            int l, r; cin >> l >> r;
            auto [cand, excess] = ms.query(l, r);
            // count occurrences of cand in [l, r)
            auto it = pos.find(cand);
            int cnt = 0;
            if (it != pos.end()){
                auto& S = it->second;
                cnt = (int)S.order_of_key(r) - (int)S.order_of_key(l);
            }
            cout << (cnt * 2 > r - l ? cand : -1) << nl;
        }
    }
}
