#define PROBLEM "https://judge.yosupo.jp/problem/set_xor_min"
#include "template"
#include "binary_trie"

int main(){
    IO();
    int T = 1;
    while (T--) solve();
}

void solve(){
    int q; cin >> q;
    binary_trie<30> bt;
    rep(q){
        int t, x; cin >> t >> x;
        if (t == 0)      bt.insert(x);
        else if (t == 1) bt.erase(x);
        else             cout << bt.xor_min(x) << nl;
    }
}
