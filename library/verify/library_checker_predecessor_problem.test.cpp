#define PROBLEM "https://judge.yosupo.jp/problem/predecessor_problem"
#include "template"
#include "splay_tree"

int main(){
    IO();
    int T = 1;
    while (T--) solve();
}

void solve(){
    int n, q;
    cin >> n >> q;
    string t;
    cin >> t;

    splay_tree<int> st;
    rep(i, n) {
        if (t[i] == '1') st.insert(i);
    }

    rep(q){
        int type, k;
        cin >> type >> k;
        if (type == 0) {
            st.insert(k);
        } else if (type == 1) {
            st.erase(k);
        } else if (type == 2) {
            cout << (st.contains(k) ? 1 : 0) << nl;
        } else if (type == 3) {
            auto res = st.lower_bound(k);  // min >= k
            cout << (res ? *res : -1) << nl;
        } else { // type == 4
            auto res = st.prev_le(k);      // max <= k
            cout << (res ? *res : -1) << nl;
        }
    }
}
