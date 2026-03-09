#pragma once
#include <bits/stdc++.h>
using namespace std;

// Rolling Hash (double hash to reduce collision probability)
struct rolling_hash {
    static constexpr long long MOD1 = 1000000007LL;
    static constexpr long long MOD2 = 998244353LL;
    static constexpr long long BASE1 = 131LL;
    static constexpr long long BASE2 = 137LL;

    int n;
    vector<long long> h1, h2, pw1, pw2;

    rolling_hash(const string& s)
        : n(s.size()), h1(n+1,0), h2(n+1,0), pw1(n+1,1), pw2(n+1,1) {
        for (int i = 0; i < n; i++) {
            h1[i+1] = (h1[i] * BASE1 + s[i]) % MOD1;
            h2[i+1] = (h2[i] * BASE2 + s[i]) % MOD2;
            pw1[i+1] = pw1[i] * BASE1 % MOD1;
            pw2[i+1] = pw2[i] * BASE2 % MOD2;
        }
    }

    // Hash of s[l, r) (0-indexed, half-open interval)
    pair<long long,long long> get(int l, int r) const {
        long long v1 = (h1[r] - h1[l] * pw1[r-l] % MOD1 + MOD1 * 2) % MOD1;
        long long v2 = (h2[r] - h2[l] * pw2[r-l] % MOD2 + MOD2 * 2) % MOD2;
        return {v1, v2};
    }

    // Longest common prefix of s[l1..r1) and s[l2..r2)
    int lcp(int l1, int r1, int l2, int r2) const {
        int lo = 0, hi = min(r1-l1, r2-l2);
        while (lo < hi) {
            int mid = (lo + hi + 1) / 2;
            if (get(l1, l1+mid) == get(l2, l2+mid)) lo = mid;
            else hi = mid - 1;
        }
        return lo;
    }

    // Check if s[l1..r1) == s[l2..r2)
    bool eq(int l1, int r1, int l2, int r2) const {
        if (r1-l1 != r2-l2) return false;
        return get(l1, r1) == get(l2, r2);
    }
};
