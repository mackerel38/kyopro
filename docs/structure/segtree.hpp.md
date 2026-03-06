---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker_point_add_range_sum.test.cpp
    title: verify/library_checker_point_add_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"structure/segtree.hpp\"\n#include<bits/stdc++.h>\nusing\
    \ namespace std;\ntemplate <class T, auto op, auto e>\nstruct segtree {\n    int\
    \ _n, size;\n    vector<T> data;\n\n    segtree() = default;\n    segtree(int\
    \ n) : _n(n) { build(vector<T>(n, e())); }\n    segtree(const vector<T>& v) :\
    \ _n(ssize(v)) { build(v); }\n    void build(const vector<T>& v) {\n        size\
    \ = __bit_ceil((unsigned int)_n);\n        data.assign(2*size, e());\n       \
    \ for (int i=0; i<_n; ++i) data[size+i] = v[i];\n        for (int i=size-1; 0<i;\
    \ --i) update(i);\n    }\n    \n    void update(int x) { data[x] = op(data[2*x],\
    \ data[2*x+1]); }\n\n    void set(int x, T y) {\n        assert(0<=x && x<_n);\n\
    \        x += size;\n        data[x] = y;\n        for (x>>=1; 0<x; x>>=1) update(x);\n\
    \    }\n    void add(int x, T y) { set(x, op(get(x), y)); }\n\n    T get(int x)\
    \ const {\n        assert(0<=x && x<_n);\n        return data[size+x];\n    }\n\
    \    T operator[](int x) const { return get(x); }\n    T allprod() const { return\
    \ data[1]; }\n    vector<T> values() const {\n        vector<T> re;\n        re.assign(data.begin()+size,\
    \ data.begin()+size+_n);\n        return re;\n    }\n\n    T prod(int x, int y)\
    \ const {\n        assert(0<=x && x<=y && y<=_n);\n        x += size;\n      \
    \  y += size;\n        T l = e(), r = e();\n        while (x < y) {\n        \
    \    if (x & 1) l = op(l, data[x++]);\n            if (y & 1) r = op(data[--y],\
    \ r);\n            x >>= 1;\n            y >>= 1;\n        }\n        return op(l,\
    \ r);\n    }\n\n    template<class F>\n    int max_right(int x, const F& f) const\
    \ {\n        assert(0<=x && x<=_n);\n        assert(f(e()));\n        if (x ==\
    \ _n) return _n;\n        x += size;\n        T l = e();\n        do {\n     \
    \       while ((x&1) == 0) x >>= 1;\n            if (!f(op(l, data[x]))) {\n \
    \               while (x < size) {\n                    x = x * 2;\n         \
    \           if (f(op(l, data[x]))) { \n                        l = op(l, data[x]);\n\
    \                        x++;\n                    }\n                }\n    \
    \            return x - size;\n            }\n            l = op(l, data[x]);\n\
    \            x++;\n        } while ((x & -x) != x);\n        return _n;\n    }\n\
    \    template<class F>\n    int min_left(int x, const F& f) {\n        assert(0<=x\
    \ && x<_n);\n        asserr(f(e()));\n        if (x == 0) return 0;\n        x\
    \ += size;\n        T r = e();\n        do {\n            x--;\n            while\
    \ (1<x && (x&1)) x >>= 1;\n            if (!f(op(data[x], r))) {\n           \
    \     while (x < size) {\n                    x = x * 2 + 1;\n               \
    \     if (f(op(data[x], r))) {\n                        r = op(data[x], r);\n\
    \                        x--;\n                    }\n                }\n    \
    \            return x + 1 - size;\n            }\n            r = op(data[x],\
    \ r);\n        } while ((x & -x) != x);\n        return 0;\n    }\n};\n"
  code: "#pragma once\n#include<bits/stdc++.h>\nusing namespace std;\ntemplate <class\
    \ T, auto op, auto e>\nstruct segtree {\n    int _n, size;\n    vector<T> data;\n\
    \n    segtree() = default;\n    segtree(int n) : _n(n) { build(vector<T>(n, e()));\
    \ }\n    segtree(const vector<T>& v) : _n(ssize(v)) { build(v); }\n    void build(const\
    \ vector<T>& v) {\n        size = __bit_ceil((unsigned int)_n);\n        data.assign(2*size,\
    \ e());\n        for (int i=0; i<_n; ++i) data[size+i] = v[i];\n        for (int\
    \ i=size-1; 0<i; --i) update(i);\n    }\n    \n    void update(int x) { data[x]\
    \ = op(data[2*x], data[2*x+1]); }\n\n    void set(int x, T y) {\n        assert(0<=x\
    \ && x<_n);\n        x += size;\n        data[x] = y;\n        for (x>>=1; 0<x;\
    \ x>>=1) update(x);\n    }\n    void add(int x, T y) { set(x, op(get(x), y));\
    \ }\n\n    T get(int x) const {\n        assert(0<=x && x<_n);\n        return\
    \ data[size+x];\n    }\n    T operator[](int x) const { return get(x); }\n   \
    \ T allprod() const { return data[1]; }\n    vector<T> values() const {\n    \
    \    vector<T> re;\n        re.assign(data.begin()+size, data.begin()+size+_n);\n\
    \        return re;\n    }\n\n    T prod(int x, int y) const {\n        assert(0<=x\
    \ && x<=y && y<=_n);\n        x += size;\n        y += size;\n        T l = e(),\
    \ r = e();\n        while (x < y) {\n            if (x & 1) l = op(l, data[x++]);\n\
    \            if (y & 1) r = op(data[--y], r);\n            x >>= 1;\n        \
    \    y >>= 1;\n        }\n        return op(l, r);\n    }\n\n    template<class\
    \ F>\n    int max_right(int x, const F& f) const {\n        assert(0<=x && x<=_n);\n\
    \        assert(f(e()));\n        if (x == _n) return _n;\n        x += size;\n\
    \        T l = e();\n        do {\n            while ((x&1) == 0) x >>= 1;\n \
    \           if (!f(op(l, data[x]))) {\n                while (x < size) {\n  \
    \                  x = x * 2;\n                    if (f(op(l, data[x]))) { \n\
    \                        l = op(l, data[x]);\n                        x++;\n \
    \                   }\n                }\n                return x - size;\n \
    \           }\n            l = op(l, data[x]);\n            x++;\n        } while\
    \ ((x & -x) != x);\n        return _n;\n    }\n    template<class F>\n    int\
    \ min_left(int x, const F& f) {\n        assert(0<=x && x<_n);\n        asserr(f(e()));\n\
    \        if (x == 0) return 0;\n        x += size;\n        T r = e();\n     \
    \   do {\n            x--;\n            while (1<x && (x&1)) x >>= 1;\n      \
    \      if (!f(op(data[x], r))) {\n                while (x < size) {\n       \
    \             x = x * 2 + 1;\n                    if (f(op(data[x], r))) {\n \
    \                       r = op(data[x], r);\n                        x--;\n  \
    \                  }\n                }\n                return x + 1 - size;\n\
    \            }\n            r = op(data[x], r);\n        } while ((x & -x) !=\
    \ x);\n        return 0;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/segtree.hpp
  requiredBy: []
  timestamp: '2026-03-06 22:07:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker_point_add_range_sum.test.cpp
documentation_of: structure/segtree.hpp
layout: document
redirect_from:
- /library/structure/segtree.hpp
- /library/structure/segtree.hpp.html
title: structure/segtree.hpp
---
