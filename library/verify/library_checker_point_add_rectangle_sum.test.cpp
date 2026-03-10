#define PROBLEM "https://judge.yosupo.jp/problem/point_add_rectangle_sum"
#include "template"
#include "BIT2d"

int main() {
    IO();
    int T = 1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, q; cin >> n >> q;
    struct point {
        int x, y;
        ll w;
    };
    vec<point> ps(n);
    vi xv;
    range(i, ps) {
        cin >> i.x >> i.y >> i.w;
        xv.pb(i.x);
    }
    vec<array<int, 5>> queries(q);
    range(i, queries) {
        cin >> i[0];
        if (i[0] == 0) {
            rep1(j, 3) cin >> i[j];
            xv.pb(i[1]);
        }
        else rep1(j, 4) cin >> i[j];
    }
    uniq(xv);
    int m = xv.size();
    BIT2d_compressed<ll> seg(m);
    rep(i, n) ps[i].x = (lower_bound(all(xv), ps[i].x)-xv.begin())+1;
    rep(i, q) queries[i][1] = (lower_bound(all(xv), queries[i][1]) - xv.begin()) + 1;
    rep(i, q) if (queries[i][0] == 1) queries[i][2] = lower_bound(all(xv), queries[i][2])-xv.begin();
    rep(i, n) seg.reserve(ps[i].x, ps[i].y);
    seg.build();
    range(i, ps) seg.add(i.x, i.y, i.w);
    range(i, queries) {
        if (i[0] == 0) seg.add(i[1], i[2], i[3]);
        else cout << seg.sum(i[1], i[2], i[3], i[4]-1) << nl;
    }
}
