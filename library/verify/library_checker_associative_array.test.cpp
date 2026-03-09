#define PROBLEM "https://judge.yosupo.jp/problem/associative_array"
#include "template"
#include "hashmap"

int main(){
    IO();
    int T = 1;
    while (T--) solve();
}

void solve(){
    int q; cin >> q;
    hashmap<ll, ll> mp;
    rep(q){
        int t; cin >> t;
        if (t == 0){
            ll k, v; cin >> k >> v;
            mp[k] = v;
        } else {
            ll k; cin >> k;
            auto it = mp.find(k);
            cout << (it == mp.end() ? 0LL : it->second) << nl;
        }
    }
}
