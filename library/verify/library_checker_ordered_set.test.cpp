#define PROBLEM "https://judge.yosupo.jp/problem/ordered_set"
#include "template"
#include "ordered_set"

int main(){
    IO();
    int T = 1;
    while (T--) solve();
}

void solve(){
    int q; cin >> q;
    // Read all queries first for offline coordinate compression
    vector<pair<int,int>> qs(q);
    rep(i, q) cin >> qs[i].first >> qs[i].second;

    // Collect all element values (types 0,1,3,4,5 use values; type 2 uses rank k)
    vector<int> vals;
    rep(i, q) if (qs[i].first != 2) vals.push_back(qs[i].second);
    sort(vals.begin(), vals.end()); vals.erase(unique(vals.begin(), vals.end()), vals.end());
    int m = (int)vals.size();

    auto comp = [&](int x) -> int {
        return (int)(lower_bound(vals.begin(), vals.end(), x) - vals.begin());
    };

    ordered_set os(m);
    rep(i, q){
        int t = qs[i].first, x = qs[i].second;
        if (t == 0){
            os.insert(comp(x));
        } else if (t == 1){
            os.erase(comp(x));
        } else if (t == 2){
            // k-th smallest (0-indexed)
            cout << vals[os.kth(x)] << nl;
        } else if (t == 3){
            // count of elements strictly less than x
            cout << os.rank(comp(x)) << nl;
        } else if (t == 4){
            // largest element <= x  (or 0 if none)
            int r = os.rank(comp(x) + 1); // count of elements with value <= x
            if (r == 0) cout << 0 << nl;
            else cout << vals[os.kth(r - 1)] << nl;
        } else {
            // t == 5: smallest element >= x  (or 2e9+1 if none)
            int r = os.rank(comp(x)); // count of elements with value < x
            if (r >= os.size()) cout << (int)2e9 + 1 << nl;
            else cout << vals[os.kth(r)] << nl;
        }
    }
}
