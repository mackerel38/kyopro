---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/modint.hpp
    title: math/modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/modint.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\ntemplate <long long Mod>\nstruct modint {\n    long long val;\n    modint(long\
    \ long v = 0) : val(v % Mod) { if (val < 0) val += Mod; }\n    modint operator+(const\
    \ modint& r) const { return modint(val + r.val); }\n    modint operator-(const\
    \ modint& r) const { return modint(val - r.val + Mod); }\n    modint operator*(const\
    \ modint& r) const { return modint(val * r.val % Mod); }\n    modint operator/(const\
    \ modint& r) const { return *this * r.inv(); }\n    modint& operator+=(const modint&\
    \ r) { return *this = *this + r; }\n    modint& operator-=(const modint& r) {\
    \ return *this = *this - r; }\n    modint& operator*=(const modint& r) { return\
    \ *this = *this * r; }\n    modint& operator/=(const modint& r) { return *this\
    \ = *this / r; }\n    bool operator==(const modint& r) const { return val == r.val;\
    \ }\n    bool operator!=(const modint& r) const { return val != r.val; }\n   \
    \ modint pow(long long n) const {\n        modint res(1), base(val);\n       \
    \ for (; n > 0; n >>= 1) {\n            if (n & 1) res *= base;\n            base\
    \ *= base;\n        }\n        return res;\n    }\n    modint inv() const { return\
    \ pow(Mod - 2); } // Mod must be prime\n    friend ostream& operator<<(ostream&\
    \ os, const modint& x) { return os << x.val; }\n    friend istream& operator>>(istream&\
    \ is, modint& x) {\n        long long v; is >> v; x = modint(v); return is;\n\
    \    }\n};\n\nusing mint  = modint<998244353>;\nusing mint7 = modint<1000000007>;\n\
    \n// Combination/Permutation precomputed with mod\n// Usage: combination<mint>\
    \ C(MAXN); C.c(n, r);\ntemplate <class mint>\nstruct combination {\n    vector<mint>\
    \ fact, inv_fact;\n\n    combination(int n) : fact(n+1), inv_fact(n+1) {\n   \
    \     fact[0] = 1;\n        for (int i = 1; i <= n; i++) fact[i] = fact[i-1] *\
    \ i;\n        inv_fact[n] = fact[n].inv();\n        for (int i = n-1; i >= 0;\
    \ i--) inv_fact[i] = inv_fact[i+1] * (i+1);\n    }\n\n    // nCr\n    mint c(int\
    \ n, int r) const {\n        if (r < 0 || r > n || n < 0) return 0;\n        return\
    \ fact[n] * inv_fact[r] * inv_fact[n-r];\n    }\n    // nPr\n    mint p(int n,\
    \ int r) const {\n        if (r < 0 || r > n || n < 0) return 0;\n        return\
    \ fact[n] * inv_fact[n-r];\n    }\n    // Multiset coefficient H(n,r) = C(n+r-1,\
    \ r)\n    mint h(int n, int r) const {\n        if (n == 0 && r == 0) return 1;\n\
    \        return c(n+r-1, r);\n    }\n};\n#line 2 \"math/combination.hpp\"\n"
  code: '#include "modint.hpp"

    '
  dependsOn:
  - math/modint.hpp
  isVerificationFile: false
  path: math/combination.hpp
  requiredBy: []
  timestamp: '2026-03-09 22:49:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/combination.hpp
layout: document
redirect_from:
- /library/math/combination.hpp
- /library/math/combination.hpp.html
title: math/combination.hpp
---
