#define PROBLEM "https://judge.yosupo.jp/problem/range_kth_smallest"
#include "template"
#include "wavelet_matrix"

int main(){
    IO();
    int T = 1;
    while (T--) solve();
}

void solve(){
    int n, q; cin >> n >> q;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    // Coordinate compress (values up to ~10^9)
    vector<int> vals = a;
    sort(vals.begin(), vals.end()); vals.erase(unique(vals.begin(), vals.end()), vals.end());
    vector<int> ca(n);
    rep(i, n) ca[i] = (int)(lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin());

    // Compressed values fit in [0, n) ⊂ [0, 2^20), so B=20 is sufficient for n<=10^6
    wavelet_matrix<20> wm;
    wm.build(ca);

    rep(q){
        int l, r, k; cin >> l >> r >> k;
        cout << vals[wm.kth(l, r, k)] << nl;
    }
}
