#define PROBLEM "https://judge.yosupo.jp/problem/point_add_rectangle_sum"
#include "template"
#include "BIT2d"

int main(){
    IO();
    int T = 1;
    while (T--) solve();
}

void solve(){
    int n, q; cin >> n >> q;
    vector<int> px(n), py(n), pw(n);
    rep(i, n) cin >> px[i] >> py[i] >> pw[i];

    // Read all queries offline to enable x-coordinate compression
    vector<array<int,5>> qs(q);
    rep(i, q){
        cin >> qs[i][0];
        if (qs[i][0] == 0) cin >> qs[i][1] >> qs[i][2] >> qs[i][3];
        else               cin >> qs[i][1] >> qs[i][2] >> qs[i][3] >> qs[i][4];
    }

    // Compress x-coordinates of all add targets (initial N points)
    vector<int> xs(px.begin(), px.end());
    sort(xs.begin(), xs.end()); xs.erase(unique(xs.begin(), xs.end()), xs.end());
    int mx = xs.size();

    // 1-indexed compressed x
    auto cx1 = [&](int x) -> int {
        return (int)(lower_bound(xs.begin(), xs.end(), x) - xs.begin()) + 1;
    };

    // Build BIT2d_compressed: register all N initial points' y-values
    BIT2d_compressed<ll> seg(mx);
    rep(i, n) seg.reserve(cx1(px[i]), py[i]);
    seg.build();

    // Add initial weights
    rep(i, n) seg.add(cx1(px[i]), py[i], pw[i]);

    // Process queries
    rep(i, q){
        if (qs[i][0] == 0){
            // add qs[i][3] to point (qs[i][1], qs[i][2])
            seg.add(cx1(qs[i][1]), qs[i][2], qs[i][3]);
        } else {
            // sum over x in [l,r), y in [d,u)
            int l = qs[i][1], d = qs[i][2], r = qs[i][3], u = qs[i][4];
            if (l >= r || d >= u){ cout << 0 << nl; continue; }
            // Compressed x-indices with original value in [l, r)
            int lx = (int)(lower_bound(xs.begin(), xs.end(), l)   - xs.begin()) + 1;
            int rx = (int)(lower_bound(xs.begin(), xs.end(), r)   - xs.begin());     // last idx with xs[k]<r
            if (lx > rx){ cout << 0 << nl; continue; }
            cout << seg.sum(lx, rx, d, u - 1) << nl;
        }
    }
}
