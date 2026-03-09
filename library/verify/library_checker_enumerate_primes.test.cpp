#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_primes"
#include "template"
#include "prime"

int main() {
    IO();
    int T = 1;
    while (T--) solve();
}

// Input : N A B
// Output: pi(N) X  (X = #{i>=0 | p_{A*i+B} <= N})
//         p_B p_{A+B} ... p_{A*(X-1)+B}
void solve() {
    int n, a, b; cin >> n >> a >> b;
    auto primes = enumprimes(n);
    int pi = (int)primes.size();
    vector<int> res;
    for (int i = b; i < pi; i += a) res.push_back(primes[i]);
    cout << pi << sp << (int)res.size() << nl;
    rep(i, (int)res.size()) {
        cout << res[i] << (i + 1 == (int)res.size() ? '\n' : ' ');
    }
}
