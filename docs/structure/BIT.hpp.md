---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker_point_add_range_sum_1.test.cpp
    title: verify/library_checker_point_add_range_sum_1.test.cpp
  - icon: ':x:'
    path: verify/library_checker_static_range_inversions_query.test.cpp
    title: verify/library_checker_static_range_inversions_query.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"structure/BIT.hpp\"\n#include<bits/stdc++.h>\nusing namespace\
    \ std;\n\ntemplate <class T>\nstruct BIT {\n    int _n;\n    vector<T> data;\n\
    \n    BIT() = default;\n    BIT(int n) : _n(n), data(_n, T{}) {}\n    BIT(const\
    \ vector<T>& v) : _n(ssize(v)), data(v) {\n        for (int i=1; i<=_n; ++i) {\n\
    \            int I = i + (i & -i);\n            if (I <= _n) data[I-1] += data[i-1];\n\
    \        }\n    }\n\n    void add(int x, T y) {\n        assert(0<=x && x<_n);\n\
    \        x++;\n        while (x <= _n) {\n            data[x-1] += y;\n      \
    \      x += x & -x;\n        }\n    }\n    void set(int x, T y) { add(x, y-get(x));\
    \ }\n\n    void get(int x) const { return sum(x+1) - sum(x); }\n    void operator[](int\
    \ x) const { return get(x); }\n\n    T sum(int x) const {\n        assert(0<=x\
    \ && x<=_n);\n        T s = T{};\n        while (0 < x) {\n            s += data[x-1];\n\
    \            x -= x & -x;\n        }\n        return s;\n    }\n    T sum(int\
    \ x, int y) const {\n        assert(x <= y);\n        return sum(y) - sum(x);\n\
    \    }\n};\n"
  code: "#pragma once\n#include<bits/stdc++.h>\nusing namespace std;\n\ntemplate <class\
    \ T>\nstruct BIT {\n    int _n;\n    vector<T> data;\n\n    BIT() = default;\n\
    \    BIT(int n) : _n(n), data(_n, T{}) {}\n    BIT(const vector<T>& v) : _n(ssize(v)),\
    \ data(v) {\n        for (int i=1; i<=_n; ++i) {\n            int I = i + (i &\
    \ -i);\n            if (I <= _n) data[I-1] += data[i-1];\n        }\n    }\n\n\
    \    void add(int x, T y) {\n        assert(0<=x && x<_n);\n        x++;\n   \
    \     while (x <= _n) {\n            data[x-1] += y;\n            x += x & -x;\n\
    \        }\n    }\n    void set(int x, T y) { add(x, y-get(x)); }\n\n    void\
    \ get(int x) const { return sum(x+1) - sum(x); }\n    void operator[](int x) const\
    \ { return get(x); }\n\n    T sum(int x) const {\n        assert(0<=x && x<=_n);\n\
    \        T s = T{};\n        while (0 < x) {\n            s += data[x-1];\n  \
    \          x -= x & -x;\n        }\n        return s;\n    }\n    T sum(int x,\
    \ int y) const {\n        assert(x <= y);\n        return sum(y) - sum(x);\n \
    \   }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/BIT.hpp
  requiredBy: []
  timestamp: '2026-03-07 14:47:14+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/library_checker_static_range_inversions_query.test.cpp
  - verify/library_checker_point_add_range_sum_1.test.cpp
documentation_of: structure/BIT.hpp
layout: document
redirect_from:
- /library/structure/BIT.hpp
- /library/structure/BIT.hpp.html
title: structure/BIT.hpp
---
