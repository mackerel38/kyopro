#pragma once
#include "modint.hpp"

// Combination/Permutation precomputed with mod
// Usage: Combination<mint> C(MAXN);
template <class mint>
struct Combination {
    vector<mint> fact, inv_fact;

    Combination(int n) : fact(n+1), inv_fact(n+1) {
        fact[0] = 1;
        for (int i = 1; i <= n; i++) fact[i] = fact[i-1] * i;
        inv_fact[n] = fact[n].inv();
        for (int i = n-1; i >= 0; i--) inv_fact[i] = inv_fact[i+1] * (i+1);
    }

    // nCr
    mint C(int n, int r) const {
        if (r < 0 || r > n || n < 0) return 0;
        return fact[n] * inv_fact[r] * inv_fact[n-r];
    }
    // nPr
    mint P(int n, int r) const {
        if (r < 0 || r > n || n < 0) return 0;
        return fact[n] * inv_fact[n-r];
    }
    // Multiset coefficient H(n,r) = C(n+r-1, r)
    mint H(int n, int r) const {
        if (n == 0 && r == 0) return 1;
        return C(n+r-1, r);
    }
};
