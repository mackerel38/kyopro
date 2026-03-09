---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker_enumerate_primes.test.cpp
    title: verify/library_checker_enumerate_primes.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker_factorize.test.cpp
    title: verify/library_checker_factorize.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker_primality_test.test.cpp
    title: verify/library_checker_primality_test.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/prime.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n// ===========================================================\n// \
    \ prime.hpp  --  primality, enumeration, factorization\n// ===========================================================\n\
    //\n//  is_prime(n)       : 64bit \u6C7A\u5B9A\u8AD6\u7684 Miller-Rabin \u7D20\
    \u6570\u5224\u5B9A\n//  enumprimes(n)     : n \u4EE5\u4E0B\u306E\u7D20\u6570\u5217\
    \u6319  Wheel Sieve mod 30\n//                      O(n / loglog n)\n//  factorize(n)\
    \      : Pollard's rho + Miller-Rabin \u7D20\u56E0\u6570\u5206\u89E3\n//     \
    \                 \u8FD4\u308A\u5024: \u30BD\u30FC\u30C8\u6E08\u307F\u7D20\u56E0\
    \u6570\u30EA\u30B9\u30C8 (\u91CD\u8907\u3042\u308A)\n// ===========================================================\n\
    \nnamespace _prime_detail {\n    using u64  = unsigned long long;\n    using u128\
    \ = unsigned __int128;\n\n    inline u64 mulmod(u64 a, u64 b, u64 m) {\n     \
    \   return (u128)a * b % m;\n    }\n    inline u64 powmod(u64 a, u64 n, u64 m)\
    \ {\n        u64 r = 1 % m; a %= m;\n        for (; n; n >>= 1, a = mulmod(a,\
    \ a, m))\n            if (n & 1) r = mulmod(r, a, m);\n        return r;\n   \
    \ }\n    // Miller-Rabin: 1 \u56DE\u306E witness \u30C1\u30A7\u30C3\u30AF\n  \
    \  inline bool witness(u64 a, u64 n, u64 d, int s) {\n        u64 x = powmod(a,\
    \ d, n);\n        if (x == 1 || x == n - 1) return true;\n        for (int i =\
    \ 0; i < s - 1; i++) {\n            x = mulmod(x, x, n);\n            if (x ==\
    \ n - 1) return true;\n        }\n        return false;\n    }\n    inline mt19937_64&\
    \ rng() {\n        static mt19937_64 r(chrono::steady_clock::now().time_since_epoch().count());\n\
    \        return r;\n    }\n    // Pollard's rho: n \u306E\u975E\u81EA\u660E\u56E0\
    \u5B50\u3092 1 \u3064\u8FD4\u3059\u3002\u5931\u6557\u6642\u306F 0\n    inline\
    \ u64 rho_step(u64 n) {\n        if (n % 2 == 0) return 2;\n        u64 x = rng()()\
    \ % (n - 2) + 2;\n        u64 y = x;\n        u64 c = rng()() % (n - 1) + 1;\n\
    \        u64 d = 1;\n        while (d == 1) {\n            x = (mulmod(x, x, n)\
    \ + c) % n;\n            y = (mulmod(y, y, n) + c) % n;\n            y = (mulmod(y,\
    \ y, n) + c) % n;\n            d = __gcd(x < y ? y - x : x - y, n);\n        }\n\
    \        return d == n ? 0 : d;\n    }\n} // namespace _prime_detail\n\n// -----------------------------------------------------------\n\
    //  is_prime  --  \u6C7A\u5B9A\u8AD6\u7684 Miller-Rabin\n//  witnesses {2,3,5,...,37}\
    \ \u3067 64bit \u5168\u57DF\u3092\u6B63\u78BA\u306B\u5224\u5B9A\n// -----------------------------------------------------------\n\
    bool is_prime(unsigned long long n) {\n    using namespace _prime_detail;\n  \
    \  if (n < 2) return false;\n    for (u64 p : {2ULL,3ULL,5ULL,7ULL,11ULL,13ULL,17ULL,19ULL,23ULL})\n\
    \        if (n == p) return true;\n        else if (n % p == 0) return false;\n\
    \    u64 d = n - 1; int s = 0;\n    while (d % 2 == 0) { d >>= 1; s++; }\n   \
    \ for (u64 a : {2ULL,3ULL,5ULL,7ULL,11ULL,13ULL,17ULL,19ULL,23ULL,29ULL,31ULL,37ULL})\n\
    \        if (a < n && !witness(a, n, d, s)) return false;\n    return true;\n\
    }\n\n// -----------------------------------------------------------\n//  enumprimes\
    \  --  Wheel Sieve (mod 30)  O(n / loglog n)\n//\n//  mod 30 \u306E wheel: 2\xD7\
    3\xD75 = 30 \u306E\u500D\u6570\u3092\u9664\u3044\u305F 8 \u6B8B\u5DEE\n//  {1,7,11,13,17,19,23,29}\
    \ \u306E\u307F\u3092\u7BA1\u7406\u3057\u5B9A\u6570\u500D\u3092\u524A\u6E1B\n//\
    \ -----------------------------------------------------------\nvector<int> enumprimes(int\
    \ n) {\n    vector<int> primes;\n    for (int p : {2, 3, 5}) if (p <= n) primes.push_back(p);\n\
    \    if (n < 7) return primes;\n\n    // wheel residues & reverse map\n    static\
    \ const int res[8]   = {1, 7, 11, 13, 17, 19, 23, 29};\n    static const int ridx[30]\
    \ = {\n        -1, 0,-1,-1,-1,-1,-1, 1,-1,-1,\n        -1, 2,-1, 3,-1,-1,-1, 4,-1,\
    \ 5,\n        -1,-1,-1, 6,-1,-1,-1,-1,-1, 7\n    };\n    const int W = 30;\n \
    \   int sz = n / W + 2;\n    // comp[k] : \u30D3\u30C3\u30C8 j \u304C\u7ACB\u3064\
    \ \u27FA (30k + res[j]) \u304C\u5408\u6210\u6570\n    vector<uint8_t> comp(sz,\
    \ 0);\n\n    for (int k = 0; (long long)k * W + 1 <= n; k++) {\n        for (int\
    \ j = 0; j < 8; j++) {\n            long long p = (long long)k * W + res[j];\n\
    \            if (p < 7)  continue;\n            if (p > n)  break;\n         \
    \   if ((comp[k] >> j) & 1) continue;   // \u5408\u6210\u6570\u306F\u30B9\u30AD\
    \u30C3\u30D7\n            primes.push_back((int)p);\n            // p \u306E\u500D\
    \u6570 p*m \u3092\u7BE9\u3046 (m >= p, m \u306F 30 \u3068\u4E92\u3044\u306B\u7D20\
    )\n            // p*m \u3082 30 \u3068\u4E92\u3044\u306B\u7D20 \u27F9 ridx \u306F\
    \u5E38\u306B\u6709\u52B9\n            for (int mk = k, mj = j;;) {\n         \
    \       long long pm = p * ((long long)mk * W + res[mj]);\n                if\
    \ (pm > n) break;\n                comp[pm / W] |= (uint8_t)(1u << ridx[(res[j]\
    \ * res[mj]) % W]);\n                if (++mj == 8) { mj = 0; mk++; }\n      \
    \      }\n        }\n    }\n    return primes;\n}\n\n// -----------------------------------------------------------\n\
    //  factorize  --  Pollard's rho + Miller-Rabin\n//  \u8FD4\u308A\u5024: \u30BD\
    \u30FC\u30C8\u6E08\u307F\u7D20\u56E0\u6570\u30EA\u30B9\u30C8 (\u91CD\u8907\u3042\
    \u308A)\n//  \u4F8B: factorize(12) => {2, 2, 3}\n// -----------------------------------------------------------\n\
    vector<long long> factorize(long long n) {\n    using namespace _prime_detail;\n\
    \    using u64 = unsigned long long;\n    if (n <= 1) return {};\n    if (is_prime((u64)n))\
    \ return {n};\n    u64 d = 0;\n    while (!d) d = rho_step((u64)n);\n    auto\
    \ a = factorize((long long)d);\n    auto b = factorize(n / (long long)d);\n  \
    \  for (auto x : b) a.push_back(x);\n    sort(a.begin(), a.end());\n    return\
    \ a;\n}\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n// ===========================================================\n\
    //  prime.hpp  --  primality, enumeration, factorization\n// ===========================================================\n\
    //\n//  is_prime(n)       : 64bit \u6C7A\u5B9A\u8AD6\u7684 Miller-Rabin \u7D20\
    \u6570\u5224\u5B9A\n//  enumprimes(n)     : n \u4EE5\u4E0B\u306E\u7D20\u6570\u5217\
    \u6319  Wheel Sieve mod 30\n//                      O(n / loglog n)\n//  factorize(n)\
    \      : Pollard's rho + Miller-Rabin \u7D20\u56E0\u6570\u5206\u89E3\n//     \
    \                 \u8FD4\u308A\u5024: \u30BD\u30FC\u30C8\u6E08\u307F\u7D20\u56E0\
    \u6570\u30EA\u30B9\u30C8 (\u91CD\u8907\u3042\u308A)\n// ===========================================================\n\
    \nnamespace _prime_detail {\n    using u64  = unsigned long long;\n    using u128\
    \ = unsigned __int128;\n\n    inline u64 mulmod(u64 a, u64 b, u64 m) {\n     \
    \   return (u128)a * b % m;\n    }\n    inline u64 powmod(u64 a, u64 n, u64 m)\
    \ {\n        u64 r = 1 % m; a %= m;\n        for (; n; n >>= 1, a = mulmod(a,\
    \ a, m))\n            if (n & 1) r = mulmod(r, a, m);\n        return r;\n   \
    \ }\n    // Miller-Rabin: 1 \u56DE\u306E witness \u30C1\u30A7\u30C3\u30AF\n  \
    \  inline bool witness(u64 a, u64 n, u64 d, int s) {\n        u64 x = powmod(a,\
    \ d, n);\n        if (x == 1 || x == n - 1) return true;\n        for (int i =\
    \ 0; i < s - 1; i++) {\n            x = mulmod(x, x, n);\n            if (x ==\
    \ n - 1) return true;\n        }\n        return false;\n    }\n    inline mt19937_64&\
    \ rng() {\n        static mt19937_64 r(chrono::steady_clock::now().time_since_epoch().count());\n\
    \        return r;\n    }\n    // Pollard's rho: n \u306E\u975E\u81EA\u660E\u56E0\
    \u5B50\u3092 1 \u3064\u8FD4\u3059\u3002\u5931\u6557\u6642\u306F 0\n    inline\
    \ u64 rho_step(u64 n) {\n        if (n % 2 == 0) return 2;\n        u64 x = rng()()\
    \ % (n - 2) + 2;\n        u64 y = x;\n        u64 c = rng()() % (n - 1) + 1;\n\
    \        u64 d = 1;\n        while (d == 1) {\n            x = (mulmod(x, x, n)\
    \ + c) % n;\n            y = (mulmod(y, y, n) + c) % n;\n            y = (mulmod(y,\
    \ y, n) + c) % n;\n            d = __gcd(x < y ? y - x : x - y, n);\n        }\n\
    \        return d == n ? 0 : d;\n    }\n} // namespace _prime_detail\n\n// -----------------------------------------------------------\n\
    //  is_prime  --  \u6C7A\u5B9A\u8AD6\u7684 Miller-Rabin\n//  witnesses {2,3,5,...,37}\
    \ \u3067 64bit \u5168\u57DF\u3092\u6B63\u78BA\u306B\u5224\u5B9A\n// -----------------------------------------------------------\n\
    bool is_prime(unsigned long long n) {\n    using namespace _prime_detail;\n  \
    \  if (n < 2) return false;\n    for (u64 p : {2ULL,3ULL,5ULL,7ULL,11ULL,13ULL,17ULL,19ULL,23ULL})\n\
    \        if (n == p) return true;\n        else if (n % p == 0) return false;\n\
    \    u64 d = n - 1; int s = 0;\n    while (d % 2 == 0) { d >>= 1; s++; }\n   \
    \ for (u64 a : {2ULL,3ULL,5ULL,7ULL,11ULL,13ULL,17ULL,19ULL,23ULL,29ULL,31ULL,37ULL})\n\
    \        if (a < n && !witness(a, n, d, s)) return false;\n    return true;\n\
    }\n\n// -----------------------------------------------------------\n//  enumprimes\
    \  --  Wheel Sieve (mod 30)  O(n / loglog n)\n//\n//  mod 30 \u306E wheel: 2\xD7\
    3\xD75 = 30 \u306E\u500D\u6570\u3092\u9664\u3044\u305F 8 \u6B8B\u5DEE\n//  {1,7,11,13,17,19,23,29}\
    \ \u306E\u307F\u3092\u7BA1\u7406\u3057\u5B9A\u6570\u500D\u3092\u524A\u6E1B\n//\
    \ -----------------------------------------------------------\nvector<int> enumprimes(int\
    \ n) {\n    vector<int> primes;\n    for (int p : {2, 3, 5}) if (p <= n) primes.push_back(p);\n\
    \    if (n < 7) return primes;\n\n    // wheel residues & reverse map\n    static\
    \ const int res[8]   = {1, 7, 11, 13, 17, 19, 23, 29};\n    static const int ridx[30]\
    \ = {\n        -1, 0,-1,-1,-1,-1,-1, 1,-1,-1,\n        -1, 2,-1, 3,-1,-1,-1, 4,-1,\
    \ 5,\n        -1,-1,-1, 6,-1,-1,-1,-1,-1, 7\n    };\n    const int W = 30;\n \
    \   int sz = n / W + 2;\n    // comp[k] : \u30D3\u30C3\u30C8 j \u304C\u7ACB\u3064\
    \ \u27FA (30k + res[j]) \u304C\u5408\u6210\u6570\n    vector<uint8_t> comp(sz,\
    \ 0);\n\n    for (int k = 0; (long long)k * W + 1 <= n; k++) {\n        for (int\
    \ j = 0; j < 8; j++) {\n            long long p = (long long)k * W + res[j];\n\
    \            if (p < 7)  continue;\n            if (p > n)  break;\n         \
    \   if ((comp[k] >> j) & 1) continue;   // \u5408\u6210\u6570\u306F\u30B9\u30AD\
    \u30C3\u30D7\n            primes.push_back((int)p);\n            // p \u306E\u500D\
    \u6570 p*m \u3092\u7BE9\u3046 (m >= p, m \u306F 30 \u3068\u4E92\u3044\u306B\u7D20\
    )\n            // p*m \u3082 30 \u3068\u4E92\u3044\u306B\u7D20 \u27F9 ridx \u306F\
    \u5E38\u306B\u6709\u52B9\n            for (int mk = k, mj = j;;) {\n         \
    \       long long pm = p * ((long long)mk * W + res[mj]);\n                if\
    \ (pm > n) break;\n                comp[pm / W] |= (uint8_t)(1u << ridx[(res[j]\
    \ * res[mj]) % W]);\n                if (++mj == 8) { mj = 0; mk++; }\n      \
    \      }\n        }\n    }\n    return primes;\n}\n\n// -----------------------------------------------------------\n\
    //  factorize  --  Pollard's rho + Miller-Rabin\n//  \u8FD4\u308A\u5024: \u30BD\
    \u30FC\u30C8\u6E08\u307F\u7D20\u56E0\u6570\u30EA\u30B9\u30C8 (\u91CD\u8907\u3042\
    \u308A)\n//  \u4F8B: factorize(12) => {2, 2, 3}\n// -----------------------------------------------------------\n\
    vector<long long> factorize(long long n) {\n    using namespace _prime_detail;\n\
    \    using u64 = unsigned long long;\n    if (n <= 1) return {};\n    if (is_prime((u64)n))\
    \ return {n};\n    u64 d = 0;\n    while (!d) d = rho_step((u64)n);\n    auto\
    \ a = factorize((long long)d);\n    auto b = factorize(n / (long long)d);\n  \
    \  for (auto x : b) a.push_back(x);\n    sort(a.begin(), a.end());\n    return\
    \ a;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/prime.hpp
  requiredBy: []
  timestamp: '2026-03-09 22:49:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker_enumerate_primes.test.cpp
  - verify/library_checker_factorize.test.cpp
  - verify/library_checker_primality_test.test.cpp
documentation_of: math/prime.hpp
layout: document
redirect_from:
- /library/math/prime.hpp
- /library/math/prime.hpp.html
title: math/prime.hpp
---
