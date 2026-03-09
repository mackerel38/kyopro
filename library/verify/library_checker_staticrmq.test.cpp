#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include "template"
#include "sparse_table"

const auto rmq_op = [](int a, int b){ return min(a, b); };

int main(){
    IO();
    int T = 1;
    while (T--) solve();
}

void solve(){
    int n, q; cin >> n >> q;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    sparse_table<int, rmq_op> st(a);
    rep(q){
        int l, r; cin >> l >> r;
        cout << st.query(l, r) << nl;
    }
}
