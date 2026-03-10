#define PROBLEM "https://judge.yosupo.jp/problem/predecessor_problem"
#include "template"
#include "splay_tree"

int main() {
    IO();
    int T = 1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, q; cin >> n >> q;
    str t; cin >> t;
    splay_tree<int> tree;
    rep(i, n) if (t[i] == '1') tree.insert(i);
    rep(q) {
        int t, k; cin >> t >> k;
        if (t == 0) tree.insert(k);
        elif (t == 1) tree.erase(k);
        elif (t == 2) cout << tree.contains(k) << nl;
        elif (t == 3) {
            auto x = tree.lower_bound(k);
            cout << (x ? *x : -1) << nl;
        } elif (t == 4) {
            auto x = tree.prev_le(k);
            cout << (x ? *x : -1) << nl;
        }
    }
}
