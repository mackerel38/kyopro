#define PROBLEM "https://judge.yosupo.jp/problem/double_ended_priority_queue"
#include "template"
#include "bipq"

int main() {
    IO();
    int T = 1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, q; cin >> n >> q;
    vi s(n); cin >> s;
    bipq<int> qu;
    range(i, s) qu.push(i);
    rep(q) {
        int t; cin >> t;
        if (t == 0) {
            int x; cin >> x;
            qu.push(x);
        } elif (t == 1) {
            cout << qu.top_min() << nl;
            qu.pop_min();
        } else {
            cout << qu.top_max() << nl;
            qu.pop_max();
        }
    }
}
