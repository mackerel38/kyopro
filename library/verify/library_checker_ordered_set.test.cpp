#define PROBLEM "https://judge.yosupo.jp/problem/ordered_set"
#include "template"
#include "dynamic_segtree"

int main() {
    IO();
    int T = 1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, q; cin >> n >> q;
    vi a(n); cin >> a;
    dynamic_segtree<int,[](int x,int y){return x+y;},[](){return 0;}> seg(0, INF);
    range(i, a) seg.set(i, 1);
    rep(q) {
        int t, x; cin >> t >> x;
        if (t == 0) seg.set(x, 1);
        elif (t == 1) seg.set(x, 0);
        elif (t == 2) {
            int y = seg.max_right(0, [&](int z){return z<x;});
            cout << (y<INF ? y : -1) << nl;
        } elif (t == 3) cout << seg.prod(0, x+1) << nl;
        elif (t == 4) {
            int y = seg.min_left(x+1, [](int z){return z==0;});
            cout << (0<y ? y-1 : -1) << nl;
        } else {
            int y = seg.max_right(x, [](int z){return z==0;});
            cout << (y<INF ? y : -1) << nl;
        }
    }
}
