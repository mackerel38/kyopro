---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker_ordered_set.test.cpp
    title: verify/library_checker_ordered_set.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"structure/dynamic_segtree.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n// Dynamic Segment Tree\n// Template parameters:\n// \
    \  T   : value type\n//   op  : binary operation  T op(T, T)  (associative)\n\
    //   e   : identity element  T e()\n//   Idx : index type (default: long long)\n\
    //\n// Range: [lo, hi)  (specified at construction)\n// Nodes are allocated on\
    \ demand, so only O(q log(range)) memory is used.\n//\n// Operations:\n//   get(pos)\
    \        : value at pos\n//   set(pos, val)   : a[pos] = val\n//   apply(pos,\
    \ val) : a[pos] = op(a[pos], val)\n//   prod(ql, qr)    : op-product of [ql, qr)\n\
    //   all_prod()      : op-product of [lo, hi)\n//   max_right(ql,f) : max r in\
    \ [ql,hi] s.t. f(prod(ql,r))==true  (*)\n//   min_left(qr, f) : min l in [lo,qr]\
    \ s.t. f(prod(l,qr))==true  (*)\n//     (*) f must be monotone and f(e()) must\
    \ be true.\n\ntemplate <class T, auto op, auto e, class Idx = long long>\nstruct\
    \ dynamic_segtree {\nprivate:\n    struct Node {\n        T   val;\n        int\
    \ left, right;\n    };\n\n    vector<Node> pool;\n    int  root;\n    Idx  lo,\
    \ hi;\n\n    int new_node() {\n        pool.emplace_back(e(), -1, -1);\n     \
    \   return (int)pool.size() - 1;\n    }\n\n    T node_val(int v) const noexcept\
    \ {\n        return v == -1 ? e() : pool[v].val;\n    }\n\n    void push_up(int\
    \ v) noexcept {\n        pool[v].val = op(node_val(pool[v].left), node_val(pool[v].right));\n\
    \    }\n\n    // ---- prod ----\n    T _prod(int v, Idx l, Idx r, Idx ql, Idx\
    \ qr) const {\n        if (v == -1 || qr <= l || r <= ql) return e();\n      \
    \  if (ql <= l && r <= qr) return pool[v].val;\n        Idx m = l + (r - l) /\
    \ 2;\n        return op(_prod(pool[v].left,  l, m, ql, qr),\n                \
    \  _prod(pool[v].right, m, r, ql, qr));\n    }\n\n    // ---- set ----\n    //\
    \ Returns (possibly new) node index.\n    // Must NOT pass pool[v].left/right\
    \ as int& \u2014 new_node() may reallocate pool.\n    int _set(int v, Idx l, Idx\
    \ r, Idx pos, T val) {\n        if (v == -1) v = new_node();\n        if (r -\
    \ l == 1) { pool[v].val = val; return v; }\n        Idx m = l + (r - l) / 2;\n\
    \        if (pos < m) pool[v].left  = _set(pool[v].left,  l, m, pos, val);\n \
    \       else         pool[v].right = _set(pool[v].right, m, r, pos, val);\n  \
    \      push_up(v);\n        return v;\n    }\n\n    // ---- apply ----\n    int\
    \ _apply(int v, Idx l, Idx r, Idx pos, T val) {\n        if (v == -1) v = new_node();\n\
    \        if (r - l == 1) { pool[v].val = op(pool[v].val, val); return v; }\n \
    \       Idx m = l + (r - l) / 2;\n        if (pos < m) pool[v].left  = _apply(pool[v].left,\
    \  l, m, pos, val);\n        else         pool[v].right = _apply(pool[v].right,\
    \ m, r, pos, val);\n        push_up(v);\n        return v;\n    }\n\n    // ----\
    \ max_right ----\n    template <class F>\n    Idx _max_right(int v, Idx l, Idx\
    \ r, Idx ql, T& acc, const F& f) const {\n        if (r <= ql || v == -1) return\
    \ hi;\n        if (ql <= l) {\n            T nxt = op(acc, pool[v].val);\n   \
    \         if (f(nxt)) { acc = nxt; return hi; }\n            if (r - l == 1) return\
    \ l;\n        }\n        Idx m = l + (r - l) / 2;\n        Idx res = _max_right(pool[v].left,\
    \  l, m, ql, acc, f);\n        if (res != hi) return res;\n        return  _max_right(pool[v].right,\
    \ m, r, ql, acc, f);\n    }\n\n    // ---- min_left ----\n    template <class\
    \ F>\n    Idx _min_left(int v, Idx l, Idx r, Idx qr, T& acc, const F& f) const\
    \ {\n        if (qr <= l || v == -1) return lo;\n        if (r <= qr) {\n    \
    \        T nxt = op(pool[v].val, acc);\n            if (f(nxt)) { acc = nxt; return\
    \ lo; }\n            if (r - l == 1) return r;\n        }\n        Idx m = l +\
    \ (r - l) / 2;\n        Idx res = _min_left(pool[v].right, m, r, qr, acc, f);\n\
    \        if (res != lo) return res;\n        return   _min_left(pool[v].left,\
    \  l, m, qr, acc, f);\n    }\n\npublic:\n    dynamic_segtree() = default;\n  \
    \  dynamic_segtree(Idx lo, Idx hi, int reserve_size = 1 << 22)\n        : lo(lo),\
    \ hi(hi), root(-1) {\n        pool.reserve(reserve_size);\n    }\n\n    T prod(Idx\
    \ ql, Idx qr) const {\n        assert(lo <= ql && qr <= hi);\n        return _prod(root,\
    \ lo, hi, ql, qr);\n    }\n\n    T all_prod() const { return node_val(root); }\n\
    \n    T get(Idx pos) const {\n        assert(lo <= pos && pos < hi);\n       \
    \ return _prod(root, lo, hi, pos, pos + 1);\n    }\n\n    void set(Idx pos, T\
    \ val) {\n        assert(lo <= pos && pos < hi);\n        root = _set(root, lo,\
    \ hi, pos, val);\n    }\n\n    void apply(Idx pos, T val) {\n        assert(lo\
    \ <= pos && pos < hi);\n        root = _apply(root, lo, hi, pos, val);\n    }\n\
    \n    template <class F>\n    Idx max_right(Idx ql, const F& f) const {\n    \
    \    assert(lo <= ql && ql <= hi);\n        assert(f(e()));\n        T acc = e();\n\
    \        return _max_right(root, lo, hi, ql, acc, f);\n    }\n\n    template <class\
    \ F>\n    Idx min_left(Idx qr, const F& f) const {\n        assert(lo <= qr &&\
    \ qr <= hi);\n        assert(f(e()));\n        T acc = e();\n        return _min_left(root,\
    \ lo, hi, qr, acc, f);\n    }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n// Dynamic\
    \ Segment Tree\n// Template parameters:\n//   T   : value type\n//   op  : binary\
    \ operation  T op(T, T)  (associative)\n//   e   : identity element  T e()\n//\
    \   Idx : index type (default: long long)\n//\n// Range: [lo, hi)  (specified\
    \ at construction)\n// Nodes are allocated on demand, so only O(q log(range))\
    \ memory is used.\n//\n// Operations:\n//   get(pos)        : value at pos\n//\
    \   set(pos, val)   : a[pos] = val\n//   apply(pos, val) : a[pos] = op(a[pos],\
    \ val)\n//   prod(ql, qr)    : op-product of [ql, qr)\n//   all_prod()      :\
    \ op-product of [lo, hi)\n//   max_right(ql,f) : max r in [ql,hi] s.t. f(prod(ql,r))==true\
    \  (*)\n//   min_left(qr, f) : min l in [lo,qr] s.t. f(prod(l,qr))==true  (*)\n\
    //     (*) f must be monotone and f(e()) must be true.\n\ntemplate <class T, auto\
    \ op, auto e, class Idx = long long>\nstruct dynamic_segtree {\nprivate:\n   \
    \ struct Node {\n        T   val;\n        int left, right;\n    };\n\n    vector<Node>\
    \ pool;\n    int  root;\n    Idx  lo, hi;\n\n    int new_node() {\n        pool.emplace_back(e(),\
    \ -1, -1);\n        return (int)pool.size() - 1;\n    }\n\n    T node_val(int\
    \ v) const noexcept {\n        return v == -1 ? e() : pool[v].val;\n    }\n\n\
    \    void push_up(int v) noexcept {\n        pool[v].val = op(node_val(pool[v].left),\
    \ node_val(pool[v].right));\n    }\n\n    // ---- prod ----\n    T _prod(int v,\
    \ Idx l, Idx r, Idx ql, Idx qr) const {\n        if (v == -1 || qr <= l || r <=\
    \ ql) return e();\n        if (ql <= l && r <= qr) return pool[v].val;\n     \
    \   Idx m = l + (r - l) / 2;\n        return op(_prod(pool[v].left,  l, m, ql,\
    \ qr),\n                  _prod(pool[v].right, m, r, ql, qr));\n    }\n\n    //\
    \ ---- set ----\n    // Returns (possibly new) node index.\n    // Must NOT pass\
    \ pool[v].left/right as int& \u2014 new_node() may reallocate pool.\n    int _set(int\
    \ v, Idx l, Idx r, Idx pos, T val) {\n        if (v == -1) v = new_node();\n \
    \       if (r - l == 1) { pool[v].val = val; return v; }\n        Idx m = l +\
    \ (r - l) / 2;\n        if (pos < m) pool[v].left  = _set(pool[v].left,  l, m,\
    \ pos, val);\n        else         pool[v].right = _set(pool[v].right, m, r, pos,\
    \ val);\n        push_up(v);\n        return v;\n    }\n\n    // ---- apply ----\n\
    \    int _apply(int v, Idx l, Idx r, Idx pos, T val) {\n        if (v == -1) v\
    \ = new_node();\n        if (r - l == 1) { pool[v].val = op(pool[v].val, val);\
    \ return v; }\n        Idx m = l + (r - l) / 2;\n        if (pos < m) pool[v].left\
    \  = _apply(pool[v].left,  l, m, pos, val);\n        else         pool[v].right\
    \ = _apply(pool[v].right, m, r, pos, val);\n        push_up(v);\n        return\
    \ v;\n    }\n\n    // ---- max_right ----\n    template <class F>\n    Idx _max_right(int\
    \ v, Idx l, Idx r, Idx ql, T& acc, const F& f) const {\n        if (r <= ql ||\
    \ v == -1) return hi;\n        if (ql <= l) {\n            T nxt = op(acc, pool[v].val);\n\
    \            if (f(nxt)) { acc = nxt; return hi; }\n            if (r - l == 1)\
    \ return l;\n        }\n        Idx m = l + (r - l) / 2;\n        Idx res = _max_right(pool[v].left,\
    \  l, m, ql, acc, f);\n        if (res != hi) return res;\n        return  _max_right(pool[v].right,\
    \ m, r, ql, acc, f);\n    }\n\n    // ---- min_left ----\n    template <class\
    \ F>\n    Idx _min_left(int v, Idx l, Idx r, Idx qr, T& acc, const F& f) const\
    \ {\n        if (qr <= l || v == -1) return lo;\n        if (r <= qr) {\n    \
    \        T nxt = op(pool[v].val, acc);\n            if (f(nxt)) { acc = nxt; return\
    \ lo; }\n            if (r - l == 1) return r;\n        }\n        Idx m = l +\
    \ (r - l) / 2;\n        Idx res = _min_left(pool[v].right, m, r, qr, acc, f);\n\
    \        if (res != lo) return res;\n        return   _min_left(pool[v].left,\
    \  l, m, qr, acc, f);\n    }\n\npublic:\n    dynamic_segtree() = default;\n  \
    \  dynamic_segtree(Idx lo, Idx hi, int reserve_size = 1 << 22)\n        : lo(lo),\
    \ hi(hi), root(-1) {\n        pool.reserve(reserve_size);\n    }\n\n    T prod(Idx\
    \ ql, Idx qr) const {\n        assert(lo <= ql && qr <= hi);\n        return _prod(root,\
    \ lo, hi, ql, qr);\n    }\n\n    T all_prod() const { return node_val(root); }\n\
    \n    T get(Idx pos) const {\n        assert(lo <= pos && pos < hi);\n       \
    \ return _prod(root, lo, hi, pos, pos + 1);\n    }\n\n    void set(Idx pos, T\
    \ val) {\n        assert(lo <= pos && pos < hi);\n        root = _set(root, lo,\
    \ hi, pos, val);\n    }\n\n    void apply(Idx pos, T val) {\n        assert(lo\
    \ <= pos && pos < hi);\n        root = _apply(root, lo, hi, pos, val);\n    }\n\
    \n    template <class F>\n    Idx max_right(Idx ql, const F& f) const {\n    \
    \    assert(lo <= ql && ql <= hi);\n        assert(f(e()));\n        T acc = e();\n\
    \        return _max_right(root, lo, hi, ql, acc, f);\n    }\n\n    template <class\
    \ F>\n    Idx min_left(Idx qr, const F& f) const {\n        assert(lo <= qr &&\
    \ qr <= hi);\n        assert(f(e()));\n        T acc = e();\n        return _min_left(root,\
    \ lo, hi, qr, acc, f);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/dynamic_segtree.hpp
  requiredBy: []
  timestamp: '2026-03-10 10:48:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker_ordered_set.test.cpp
documentation_of: structure/dynamic_segtree.hpp
layout: document
redirect_from:
- /library/structure/dynamic_segtree.hpp
- /library/structure/dynamic_segtree.hpp.html
title: structure/dynamic_segtree.hpp
---
