#pragma once
#include <bits/stdc++.h>
using namespace std;

// ===========================================================
//  prime.hpp  --  primality, enumeration, factorization
// ===========================================================
//
//  is_prime(n)       : 64bit 決定論的 Miller-Rabin 素数判定
//  enumprimes(n)     : n 以下の素数列挙  Wheel Sieve mod 30
//                      O(n / loglog n)
//  factorize(n)      : Pollard's rho + Miller-Rabin 素因数分解
//                      返り値: ソート済み素因数リスト (重複あり)
// ===========================================================

namespace _prime_detail {
    using u64  = unsigned long long;
    using u128 = unsigned __int128;

    inline u64 mulmod(u64 a, u64 b, u64 m) {
        return (u128)a * b % m;
    }
    inline u64 powmod(u64 a, u64 n, u64 m) {
        u64 r = 1 % m; a %= m;
        for (; n; n >>= 1, a = mulmod(a, a, m))
            if (n & 1) r = mulmod(r, a, m);
        return r;
    }
    // Miller-Rabin: 1 回の witness チェック
    inline bool witness(u64 a, u64 n, u64 d, int s) {
        u64 x = powmod(a, d, n);
        if (x == 1 || x == n - 1) return true;
        for (int i = 0; i < s - 1; i++) {
            x = mulmod(x, x, n);
            if (x == n - 1) return true;
        }
        return false;
    }
    inline mt19937_64& rng() {
        static mt19937_64 r(chrono::steady_clock::now().time_since_epoch().count());
        return r;
    }
    // Pollard's rho: n の非自明因子を 1 つ返す。失敗時は 0
    inline u64 rho_step(u64 n) {
        if (n % 2 == 0) return 2;
        u64 x = rng()() % (n - 2) + 2;
        u64 y = x;
        u64 c = rng()() % (n - 1) + 1;
        u64 d = 1;
        while (d == 1) {
            x = (mulmod(x, x, n) + c) % n;
            y = (mulmod(y, y, n) + c) % n;
            y = (mulmod(y, y, n) + c) % n;
            d = __gcd(x < y ? y - x : x - y, n);
        }
        return d == n ? 0 : d;
    }
} // namespace _prime_detail

// -----------------------------------------------------------
//  is_prime  --  決定論的 Miller-Rabin
//  witnesses {2,3,5,...,37} で 64bit 全域を正確に判定
// -----------------------------------------------------------
bool is_prime(unsigned long long n) {
    using namespace _prime_detail;
    if (n < 2) return false;
    for (u64 p : {2ULL,3ULL,5ULL,7ULL,11ULL,13ULL,17ULL,19ULL,23ULL})
        if (n == p) return true;
        else if (n % p == 0) return false;
    u64 d = n - 1; int s = 0;
    while (d % 2 == 0) { d >>= 1; s++; }
    for (u64 a : {2ULL,3ULL,5ULL,7ULL,11ULL,13ULL,17ULL,19ULL,23ULL,29ULL,31ULL,37ULL})
        if (a < n && !witness(a, n, d, s)) return false;
    return true;
}

// -----------------------------------------------------------
//  enumprimes  --  Wheel Sieve (mod 30)  O(n / loglog n)
//
//  mod 30 の wheel: 2×3×5 = 30 の倍数を除いた 8 残差
//  {1,7,11,13,17,19,23,29} のみを管理し定数倍を削減
// -----------------------------------------------------------
vector<int> enumprimes(int n) {
    vector<int> primes;
    for (int p : {2, 3, 5}) if (p <= n) primes.push_back(p);
    if (n < 7) return primes;

    // wheel residues & reverse map
    static const int res[8]   = {1, 7, 11, 13, 17, 19, 23, 29};
    static const int ridx[30] = {
        -1, 0,-1,-1,-1,-1,-1, 1,-1,-1,
        -1, 2,-1, 3,-1,-1,-1, 4,-1, 5,
        -1,-1,-1, 6,-1,-1,-1,-1,-1, 7
    };
    const int W = 30;
    int sz = n / W + 2;
    // comp[k] : ビット j が立つ ⟺ (30k + res[j]) が合成数
    vector<uint8_t> comp(sz, 0);

    for (int k = 0; (long long)k * W + 1 <= n; k++) {
        for (int j = 0; j < 8; j++) {
            long long p = (long long)k * W + res[j];
            if (p < 7)  continue;
            if (p > n)  break;
            if ((comp[k] >> j) & 1) continue;   // 合成数はスキップ
            primes.push_back((int)p);
            // p の倍数 p*m を篩う (m >= p, m は 30 と互いに素)
            // p*m も 30 と互いに素 ⟹ ridx は常に有効
            for (int mk = k, mj = j;;) {
                long long pm = p * ((long long)mk * W + res[mj]);
                if (pm > n) break;
                comp[pm / W] |= (uint8_t)(1u << ridx[(res[j] * res[mj]) % W]);
                if (++mj == 8) { mj = 0; mk++; }
            }
        }
    }
    return primes;
}

// -----------------------------------------------------------
//  factorize  --  Pollard's rho + Miller-Rabin
//  返り値: ソート済み素因数リスト (重複あり)
//  例: factorize(12) => {2, 2, 3}
// -----------------------------------------------------------
vector<long long> factorize(long long n) {
    using namespace _prime_detail;
    using u64 = unsigned long long;
    if (n <= 1) return {};
    if (is_prime((u64)n)) return {n};
    u64 d = 0;
    while (!d) d = rho_step((u64)n);
    auto a = factorize((long long)d);
    auto b = factorize(n / (long long)d);
    for (auto x : b) a.push_back(x);
    sort(a.begin(), a.end());
    return a;
}
