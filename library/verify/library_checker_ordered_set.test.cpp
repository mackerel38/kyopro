#define PROBLEM "https://judge.yosupo.jp/problem/ordered_set"
#include "template"
#include "dynamic_segtree"

// Ordered Set using Dynamic Segment Tree (frequency array over coordinate space)
// Range: [0, 2^30)  which covers all x < 10^9
// a[x] = 1 if x is in the set, 0 otherwise
//
// Query mapping:
//   insert x         : set(x, 1)
//   erase  x         : set(x, 0)
//   count_lt(x)      : prod(0, x)          ... # elements in [0, x)
//   kth(k, 0-indexed): max_right(0, s<=k)  ... 1st pos where prefix-sum exceeds k
//   prev_le(x)       : min_left(x+1, s==0) - 1  (l-1 where [l, x+1) is empty)
//   next_ge(x)       : max_right(x,  s==0)       (1st pos >= x with a[pos]=1)

void solve() {
    int n, q;
    cin >> n >> q;

    const long long LO = 0, HI = 1LL << 30;  // covers [0, 10^9)
    dynamic_segtree<int, [](int a, int b){ return a + b; }, []{ return 0; }> seg(LO, HI);

    rep(n) {
        int x; cin >> x;
        seg.set((long long)x, 1);
    }

    rep(q) {
        int t; cin >> t;
        if (t == 0) {
            // insert x
            int x; cin >> x;
            seg.set((long long)x, 1);
        } else if (t == 1) {
            // erase x
            int x; cin >> x;
            seg.set((long long)x, 0);
        } else if (t == 2) {
            // count elements < x
            int x; cin >> x;
            cout << seg.prod(LO, (long long)x) << nl;
        } else if (t == 3) {
            // k-th smallest (0-indexed)
            int k; cin >> k;
            cout << seg.max_right(LO, [&](int s){ return s <= k; }) << nl;
        } else if (t == 4) {
            // max element <= x  (-1 if none)
            int x; cin >> x;
            long long l = seg.min_left((long long)x + 1, [](int s){ return s == 0; });
            cout << (l > LO ? l - 1 : -1LL) << nl;
        } else {
            // min element >= x  (2147483648 if none)
            int x; cin >> x;
            long long r = seg.max_right((long long)x, [](int s){ return s == 0; });
            cout << (r < HI ? r : 2147483648LL) << nl;
        }
    }
}

int main() {
    IO();
    int T = 1;
    while (T--) solve();
}
