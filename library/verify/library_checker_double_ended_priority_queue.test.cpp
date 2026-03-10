#define PROBLEM "https://judge.yosupo.jp/problem/double_ended_priority_queue"
#include "template"
#include "bipq"

void solve() {
    int n, q;
    cin >> n >> q;

    bipq<int> pq;
    rep(n) {
        int x; cin >> x;
        pq.push(x);
    }

    rep(q) {
        int t; cin >> t;
        if (t == 0) {
            int x; cin >> x;
            pq.push(x);
        } else if (t == 1) {
            cout << pq.top_min() << nl;
            pq.pop_min();
        } else {
            cout << pq.top_max() << nl;
            pq.pop_max();
        }
    }
}

int main() {
    IO();
    int T = 1;
    while (T--) solve();
}
