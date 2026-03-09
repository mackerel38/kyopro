---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/rolling_hash.hpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\n// Rolling Hash (double hash to reduce collision probability)\n\
    struct rolling_hash {\n    static constexpr long long MOD1 = 1000000007LL;\n \
    \   static constexpr long long MOD2 = 998244353LL;\n    static constexpr long\
    \ long BASE1 = 131LL;\n    static constexpr long long BASE2 = 137LL;\n\n    int\
    \ n;\n    vector<long long> h1, h2, pw1, pw2;\n\n    rolling_hash(const string&\
    \ s)\n        : n(s.size()), h1(n+1,0), h2(n+1,0), pw1(n+1,1), pw2(n+1,1) {\n\
    \        for (int i = 0; i < n; i++) {\n            h1[i+1] = (h1[i] * BASE1 +\
    \ s[i]) % MOD1;\n            h2[i+1] = (h2[i] * BASE2 + s[i]) % MOD2;\n      \
    \      pw1[i+1] = pw1[i] * BASE1 % MOD1;\n            pw2[i+1] = pw2[i] * BASE2\
    \ % MOD2;\n        }\n    }\n\n    // Hash of s[l, r) (0-indexed, half-open interval)\n\
    \    pair<long long,long long> get(int l, int r) const {\n        long long v1\
    \ = (h1[r] - h1[l] * pw1[r-l] % MOD1 + MOD1 * 2) % MOD1;\n        long long v2\
    \ = (h2[r] - h2[l] * pw2[r-l] % MOD2 + MOD2 * 2) % MOD2;\n        return {v1,\
    \ v2};\n    }\n\n    // Longest common prefix of s[l1..r1) and s[l2..r2)\n   \
    \ int lcp(int l1, int r1, int l2, int r2) const {\n        int lo = 0, hi = min(r1-l1,\
    \ r2-l2);\n        while (lo < hi) {\n            int mid = (lo + hi + 1) / 2;\n\
    \            if (get(l1, l1+mid) == get(l2, l2+mid)) lo = mid;\n            else\
    \ hi = mid - 1;\n        }\n        return lo;\n    }\n\n    // Check if s[l1..r1)\
    \ == s[l2..r2)\n    bool eq(int l1, int r1, int l2, int r2) const {\n        if\
    \ (r1-l1 != r2-l2) return false;\n        return get(l1, r1) == get(l2, r2);\n\
    \    }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n// Rolling\
    \ Hash (double hash to reduce collision probability)\nstruct rolling_hash {\n\
    \    static constexpr long long MOD1 = 1000000007LL;\n    static constexpr long\
    \ long MOD2 = 998244353LL;\n    static constexpr long long BASE1 = 131LL;\n  \
    \  static constexpr long long BASE2 = 137LL;\n\n    int n;\n    vector<long long>\
    \ h1, h2, pw1, pw2;\n\n    rolling_hash(const string& s)\n        : n(s.size()),\
    \ h1(n+1,0), h2(n+1,0), pw1(n+1,1), pw2(n+1,1) {\n        for (int i = 0; i <\
    \ n; i++) {\n            h1[i+1] = (h1[i] * BASE1 + s[i]) % MOD1;\n          \
    \  h2[i+1] = (h2[i] * BASE2 + s[i]) % MOD2;\n            pw1[i+1] = pw1[i] * BASE1\
    \ % MOD1;\n            pw2[i+1] = pw2[i] * BASE2 % MOD2;\n        }\n    }\n\n\
    \    // Hash of s[l, r) (0-indexed, half-open interval)\n    pair<long long,long\
    \ long> get(int l, int r) const {\n        long long v1 = (h1[r] - h1[l] * pw1[r-l]\
    \ % MOD1 + MOD1 * 2) % MOD1;\n        long long v2 = (h2[r] - h2[l] * pw2[r-l]\
    \ % MOD2 + MOD2 * 2) % MOD2;\n        return {v1, v2};\n    }\n\n    // Longest\
    \ common prefix of s[l1..r1) and s[l2..r2)\n    int lcp(int l1, int r1, int l2,\
    \ int r2) const {\n        int lo = 0, hi = min(r1-l1, r2-l2);\n        while\
    \ (lo < hi) {\n            int mid = (lo + hi + 1) / 2;\n            if (get(l1,\
    \ l1+mid) == get(l2, l2+mid)) lo = mid;\n            else hi = mid - 1;\n    \
    \    }\n        return lo;\n    }\n\n    // Check if s[l1..r1) == s[l2..r2)\n\
    \    bool eq(int l1, int r1, int l2, int r2) const {\n        if (r1-l1 != r2-l2)\
    \ return false;\n        return get(l1, r1) == get(l2, r2);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: string/rolling_hash.hpp
  requiredBy: []
  timestamp: '2026-03-09 22:49:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/rolling_hash.hpp
layout: document
redirect_from:
- /library/string/rolling_hash.hpp
- /library/string/rolling_hash.hpp.html
title: string/rolling_hash.hpp
---
