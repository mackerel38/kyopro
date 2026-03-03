#include "template"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n; cin >> n;
    vi a(n); cin >> a;
    int two = infty<int>, three = infty<int>;
    int Two = 0, Three = 0;
    vi b;
    range(i, a) {
        int x = i;
        int cnt2=0, cnt3=0;
        while (x % 2 == 0) {
            cnt2++;
            x /= 2;
        }
        while (x % 3 == 0) {
            cnt3++;
            x /= 3;
        }
        b.pb(x);
        chmin(two, cnt2);
        Two += cnt2;
        chmin(three, cnt3);
        Three += cnt3;
    }
    uniq(b);
    cout << (len(b)==1 ? Two+Three-n*(two+three) : -1) << nl;
}
