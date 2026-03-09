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
  bundledCode: "#line 2 \"math/extgcd.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n// Extended Euclidean: finds x, y s.t. a*x + b*y = gcd(a, b)\n// Returns\
    \ gcd(a, b)\ntemplate <class T>\nT extgcd(T a, T b, T& x, T& y) {\n    if (b ==\
    \ 0) { x = 1; y = 0; return a; }\n    T x1, y1;\n    T g = extgcd(b, a % b, x1,\
    \ y1);\n    x = y1;\n    y = x1 - (a / b) * y1;\n    return g;\n}\n\n// Modular\
    \ inverse using extgcd (works for non-prime mod)\n// Requires gcd(a, mod) == 1\n\
    template <class T>\nT modinv(T a, T mod) {\n    T x, y;\n    extgcd(a, mod, x,\
    \ y);\n    return (x % mod + mod) % mod;\n}\n\n// Chinese Remainder Theorem\n\
    // Finds x s.t. x \u2261 r1 (mod m1) and x \u2261 r2 (mod m2)\n// Returns {r,\
    \ lcm(m1,m2)}, or {0, 0} if no solution exists\npair<long long, long long> crt(long\
    \ long r1, long long m1, long long r2, long long m2) {\n    long long x, y;\n\
    \    long long g = extgcd(m1, m2, x, y);\n    if ((r2 - r1) % g != 0) return {0,\
    \ 0};\n    long long m = m1 / g * m2;\n    long long r = (r1 + m1 * ((r2 - r1)\
    \ / g % (m2/g) * (x % (m2/g)) % (m2/g))) % m;\n    if (r < 0) r += m;\n    return\
    \ {r, m};\n}\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n// Extended\
    \ Euclidean: finds x, y s.t. a*x + b*y = gcd(a, b)\n// Returns gcd(a, b)\ntemplate\
    \ <class T>\nT extgcd(T a, T b, T& x, T& y) {\n    if (b == 0) { x = 1; y = 0;\
    \ return a; }\n    T x1, y1;\n    T g = extgcd(b, a % b, x1, y1);\n    x = y1;\n\
    \    y = x1 - (a / b) * y1;\n    return g;\n}\n\n// Modular inverse using extgcd\
    \ (works for non-prime mod)\n// Requires gcd(a, mod) == 1\ntemplate <class T>\n\
    T modinv(T a, T mod) {\n    T x, y;\n    extgcd(a, mod, x, y);\n    return (x\
    \ % mod + mod) % mod;\n}\n\n// Chinese Remainder Theorem\n// Finds x s.t. x \u2261\
    \ r1 (mod m1) and x \u2261 r2 (mod m2)\n// Returns {r, lcm(m1,m2)}, or {0, 0}\
    \ if no solution exists\npair<long long, long long> crt(long long r1, long long\
    \ m1, long long r2, long long m2) {\n    long long x, y;\n    long long g = extgcd(m1,\
    \ m2, x, y);\n    if ((r2 - r1) % g != 0) return {0, 0};\n    long long m = m1\
    \ / g * m2;\n    long long r = (r1 + m1 * ((r2 - r1) / g % (m2/g) * (x % (m2/g))\
    \ % (m2/g))) % m;\n    if (r < 0) r += m;\n    return {r, m};\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/extgcd.hpp
  requiredBy: []
  timestamp: '2026-03-09 22:49:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/extgcd.hpp
layout: document
redirect_from:
- /library/math/extgcd.hpp
- /library/math/extgcd.hpp.html
title: math/extgcd.hpp
---
