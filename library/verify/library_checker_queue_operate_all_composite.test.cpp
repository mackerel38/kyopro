#define PROBLEM "https://judge.yosupo.jp/problem/queue_operate_all_composite"
#include "template"
#include "swag"
#include "modint"

// f(x) = a*x + b  represented as {a, b}
// op(f, g) = apply f first, then g:  g(f(x)) = (a_f*a_g)*x + (a_g*b_f + b_g)
using S = pair<mint, mint>;
const auto swag_op = [](S f, S g) -> S {
    return {f.first * g.first, g.first * f.second + g.second};
};
const auto swag_e  = []() -> S { return {mint(1), mint(0)}; };

int main(){
    IO();
    int T = 1;
    while (T--) solve();
}

void solve(){
    int q; cin >> q;
    swag<S, swag_op, swag_e> sw;
    rep(q){
        int t; cin >> t;
        if (t == 0){
            mint a, b; cin >> a >> b;
            sw.push_back({a, b});
        } else if (t == 1){
            sw.pop_front();
        } else {
            mint x; cin >> x;
            auto [a, b] = sw.fold();
            cout << a * x + b << nl;
        }
    }
}
