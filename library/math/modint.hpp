#pragma once
#include <bits/stdc++.h>
using namespace std;

template <long long Mod>
struct modint {
    long long val;
    modint(long long v = 0) : val(v % Mod) { if (val < 0) val += Mod; }
    modint operator+(const modint& r) const { return modint(val + r.val); }
    modint operator-(const modint& r) const { return modint(val - r.val + Mod); }
    modint operator*(const modint& r) const { return modint(val * r.val % Mod); }
    modint operator/(const modint& r) const { return *this * r.inv(); }
    modint& operator+=(const modint& r) { return *this = *this + r; }
    modint& operator-=(const modint& r) { return *this = *this - r; }
    modint& operator*=(const modint& r) { return *this = *this * r; }
    modint& operator/=(const modint& r) { return *this = *this / r; }
    bool operator==(const modint& r) const { return val == r.val; }
    bool operator!=(const modint& r) const { return val != r.val; }
    modint pow(long long n) const {
        modint res(1), base(val);
        for (; n > 0; n >>= 1) {
            if (n & 1) res *= base;
            base *= base;
        }
        return res;
    }
    modint inv() const { return pow(Mod - 2); } // Mod must be prime
    friend ostream& operator<<(ostream& os, const modint& x) { return os << x.val; }
    friend istream& operator>>(istream& is, modint& x) {
        long long v; is >> v; x = modint(v); return is;
    }
};

using mint  = modint<998244353>;
using mint7 = modint<1000000007>;

// Combination/Permutation precomputed with mod
// Usage: combination<mint> C(MAXN); C.c(n, r);
template <class mint>
struct combination {
    vector<mint> fact, inv_fact;

    combination(int n) : fact(n+1), inv_fact(n+1) {
        fact[0] = 1;
        for (int i = 1; i <= n; i++) fact[i] = fact[i-1] * i;
        inv_fact[n] = fact[n].inv();
        for (int i = n-1; i >= 0; i--) inv_fact[i] = inv_fact[i+1] * (i+1);
    }

    // nCr
    mint c(int n, int r) const {
        if (r < 0 || r > n || n < 0) return 0;
        return fact[n] * inv_fact[r] * inv_fact[n-r];
    }
    // nPr
    mint p(int n, int r) const {
        if (r < 0 || r > n || n < 0) return 0;
        return fact[n] * inv_fact[n-r];
    }
    // Multiset coefficient H(n,r) = C(n+r-1, r)
    mint h(int n, int r) const {
        if (n == 0 && r == 0) return 1;
        return c(n+r-1, r);
    }
};
