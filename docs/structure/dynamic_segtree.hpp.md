---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/library_checker_ordered_set.test.cpp
    title: verify/library_checker_ordered_set.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
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
    \ hi;\n\n    int new_node() {\n        pool.push_back({e(), -1, -1});\n      \
    \  return (int)pool.size() - 1;\n    }\n\n    T node_val(int v) const noexcept\
    \ {\n        return v == -1 ? e() : pool[v].val;\n    }\n\n    void push_up(int\
    \ v) noexcept {\n        pool[v].val = op(node_val(pool[v].left), node_val(pool[v].right));\n\
    \    }\n\n    // ---- prod ----\n    T _prod(int v, Idx l, Idx r, Idx ql, Idx\
    \ qr) const {\n        if (v == -1 || qr <= l || r <= ql) return e();\n      \
    \  if (ql <= l && r <= qr) return pool[v].val;\n        Idx m = l + (r - l) /\
    \ 2;\n        return op(_prod(pool[v].left,  l, m, ql, qr),\n                \
    \  _prod(pool[v].right, m, r, ql, qr));\n    }\n\n    // ---- set ----\n    void\
    \ _set(int& v, Idx l, Idx r, Idx pos, T val) {\n        if (v == -1) v = new_node();\n\
    \        if (r - l == 1) { pool[v].val = val; return; }\n        Idx m = l + (r\
    \ - l) / 2;\n        if (pos < m) _set(pool[v].left,  l, m, pos, val);\n     \
    \   else         _set(pool[v].right, m, r, pos, val);\n        push_up(v);\n \
    \   }\n\n    // ---- apply ----\n    void _apply(int& v, Idx l, Idx r, Idx pos,\
    \ T val) {\n        if (v == -1) v = new_node();\n        if (r - l == 1) { pool[v].val\
    \ = op(pool[v].val, val); return; }\n        Idx m = l + (r - l) / 2;\n      \
    \  if (pos < m) _apply(pool[v].left,  l, m, pos, val);\n        else         _apply(pool[v].right,\
    \ m, r, pos, val);\n        push_up(v);\n    }\n\n    // ---- max_right ----\n\
    \    // Returns the leftmost position where the running product (from ql) first\n\
    \    // fails f.  Returns hi if f holds throughout.\n    // acc : product accumulated\
    \ so far (left of current subtree)\n    template <class F>\n    Idx _max_right(int\
    \ v, Idx l, Idx r, Idx ql, T& acc, const F& f) const {\n        if (r <= ql ||\
    \ v == -1) return hi;   // out of range or null (contributes e())\n        if\
    \ (ql <= l) {\n            // fully in range\n            T nxt = op(acc, pool[v].val);\n\
    \            if (f(nxt)) { acc = nxt; return hi; }  // whole node ok, keep going\
    \ right\n            if (r - l == 1) return l;              // leaf fails: boundary\
    \ is here\n        }\n        Idx m = l + (r - l) / 2;\n        Idx res = _max_right(pool[v].left,\
    \  l, m, ql, acc, f);\n        if (res != hi) return res;\n        return  _max_right(pool[v].right,\
    \ m, r, ql, acc, f);\n    }\n\n    // ---- min_left ----\n    // Returns the rightmost\
    \ position where the running product (up to qr) first\n    // fails f when we\
    \ extend leftward.  Returns lo if f holds throughout.\n    // acc : product accumulated\
    \ so far (right of current subtree)\n    template <class F>\n    Idx _min_left(int\
    \ v, Idx l, Idx r, Idx qr, T& acc, const F& f) const {\n        if (qr <= l ||\
    \ v == -1) return lo;   // out of range or null (contributes e())\n        if\
    \ (r <= qr) {\n            // fully in range\n            T nxt = op(pool[v].val,\
    \ acc);\n            if (f(nxt)) { acc = nxt; return lo; }  // whole node ok,\
    \ keep going left\n            if (r - l == 1) return r;              // leaf\
    \ fails: boundary is r (= l+1)\n        }\n        Idx m = l + (r - l) / 2;\n\
    \        Idx res = _min_left(pool[v].right, m, r, qr, acc, f);\n        if (res\
    \ != lo) return res;\n        return   _min_left(pool[v].left,  l, m, qr, acc,\
    \ f);\n    }\n\npublic:\n    dynamic_segtree() = default;\n    // reserve_size:\
    \ pre-allocated node pool capacity\n    dynamic_segtree(Idx lo, Idx hi, int reserve_size\
    \ = 1 << 22)\n        : lo(lo), hi(hi), root(-1) {\n        pool.reserve(reserve_size);\n\
    \    }\n\n    // prod(ql, qr): op-product of [ql, qr)\n    T prod(Idx ql, Idx\
    \ qr) const {\n        assert(lo <= ql && qr <= hi);\n        return _prod(root,\
    \ lo, hi, ql, qr);\n    }\n\n    T all_prod() const { return node_val(root); }\n\
    \n    // get(pos): value at pos\n    T get(Idx pos) const {\n        assert(lo\
    \ <= pos && pos < hi);\n        return _prod(root, lo, hi, pos, pos + 1);\n  \
    \  }\n\n    // set(pos, val): a[pos] = val\n    void set(Idx pos, T val) {\n \
    \       assert(lo <= pos && pos < hi);\n        _set(root, lo, hi, pos, val);\n\
    \    }\n\n    // apply(pos, val): a[pos] = op(a[pos], val)\n    void apply(Idx\
    \ pos, T val) {\n        assert(lo <= pos && pos < hi);\n        _apply(root,\
    \ lo, hi, pos, val);\n    }\n\n    // max_right(ql, f):\n    //   Returns r in\
    \ [ql, hi] s.t. f(prod(ql, r)) == true\n    //   and (r == hi  or  f(prod(ql,\
    \ r+1)) == false).\n    //   Precondition: f(e()) == true, f must be monotone.\n\
    \    template <class F>\n    Idx max_right(Idx ql, const F& f) const {\n     \
    \   assert(lo <= ql && ql <= hi);\n        assert(f(e()));\n        T acc = e();\n\
    \        return _max_right(root, lo, hi, ql, acc, f);\n    }\n\n    // min_left(qr,\
    \ f):\n    //   Returns l in [lo, qr] s.t. f(prod(l, qr)) == true\n    //   and\
    \ (l == lo  or  f(prod(l-1, qr)) == false).\n    //   Precondition: f(e()) ==\
    \ true, f must be monotone.\n    template <class F>\n    Idx min_left(Idx qr,\
    \ const F& f) const {\n        assert(lo <= qr && qr <= hi);\n        assert(f(e()));\n\
    \        T acc = e();\n        return _min_left(root, lo, hi, qr, acc, f);\n \
    \   }\n};\n"
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
    \ pool;\n    int  root;\n    Idx  lo, hi;\n\n    int new_node() {\n        pool.push_back({e(),\
    \ -1, -1});\n        return (int)pool.size() - 1;\n    }\n\n    T node_val(int\
    \ v) const noexcept {\n        return v == -1 ? e() : pool[v].val;\n    }\n\n\
    \    void push_up(int v) noexcept {\n        pool[v].val = op(node_val(pool[v].left),\
    \ node_val(pool[v].right));\n    }\n\n    // ---- prod ----\n    T _prod(int v,\
    \ Idx l, Idx r, Idx ql, Idx qr) const {\n        if (v == -1 || qr <= l || r <=\
    \ ql) return e();\n        if (ql <= l && r <= qr) return pool[v].val;\n     \
    \   Idx m = l + (r - l) / 2;\n        return op(_prod(pool[v].left,  l, m, ql,\
    \ qr),\n                  _prod(pool[v].right, m, r, ql, qr));\n    }\n\n    //\
    \ ---- set ----\n    void _set(int& v, Idx l, Idx r, Idx pos, T val) {\n     \
    \   if (v == -1) v = new_node();\n        if (r - l == 1) { pool[v].val = val;\
    \ return; }\n        Idx m = l + (r - l) / 2;\n        if (pos < m) _set(pool[v].left,\
    \  l, m, pos, val);\n        else         _set(pool[v].right, m, r, pos, val);\n\
    \        push_up(v);\n    }\n\n    // ---- apply ----\n    void _apply(int& v,\
    \ Idx l, Idx r, Idx pos, T val) {\n        if (v == -1) v = new_node();\n    \
    \    if (r - l == 1) { pool[v].val = op(pool[v].val, val); return; }\n       \
    \ Idx m = l + (r - l) / 2;\n        if (pos < m) _apply(pool[v].left,  l, m, pos,\
    \ val);\n        else         _apply(pool[v].right, m, r, pos, val);\n       \
    \ push_up(v);\n    }\n\n    // ---- max_right ----\n    // Returns the leftmost\
    \ position where the running product (from ql) first\n    // fails f.  Returns\
    \ hi if f holds throughout.\n    // acc : product accumulated so far (left of\
    \ current subtree)\n    template <class F>\n    Idx _max_right(int v, Idx l, Idx\
    \ r, Idx ql, T& acc, const F& f) const {\n        if (r <= ql || v == -1) return\
    \ hi;   // out of range or null (contributes e())\n        if (ql <= l) {\n  \
    \          // fully in range\n            T nxt = op(acc, pool[v].val);\n    \
    \        if (f(nxt)) { acc = nxt; return hi; }  // whole node ok, keep going right\n\
    \            if (r - l == 1) return l;              // leaf fails: boundary is\
    \ here\n        }\n        Idx m = l + (r - l) / 2;\n        Idx res = _max_right(pool[v].left,\
    \  l, m, ql, acc, f);\n        if (res != hi) return res;\n        return  _max_right(pool[v].right,\
    \ m, r, ql, acc, f);\n    }\n\n    // ---- min_left ----\n    // Returns the rightmost\
    \ position where the running product (up to qr) first\n    // fails f when we\
    \ extend leftward.  Returns lo if f holds throughout.\n    // acc : product accumulated\
    \ so far (right of current subtree)\n    template <class F>\n    Idx _min_left(int\
    \ v, Idx l, Idx r, Idx qr, T& acc, const F& f) const {\n        if (qr <= l ||\
    \ v == -1) return lo;   // out of range or null (contributes e())\n        if\
    \ (r <= qr) {\n            // fully in range\n            T nxt = op(pool[v].val,\
    \ acc);\n            if (f(nxt)) { acc = nxt; return lo; }  // whole node ok,\
    \ keep going left\n            if (r - l == 1) return r;              // leaf\
    \ fails: boundary is r (= l+1)\n        }\n        Idx m = l + (r - l) / 2;\n\
    \        Idx res = _min_left(pool[v].right, m, r, qr, acc, f);\n        if (res\
    \ != lo) return res;\n        return   _min_left(pool[v].left,  l, m, qr, acc,\
    \ f);\n    }\n\npublic:\n    dynamic_segtree() = default;\n    // reserve_size:\
    \ pre-allocated node pool capacity\n    dynamic_segtree(Idx lo, Idx hi, int reserve_size\
    \ = 1 << 22)\n        : lo(lo), hi(hi), root(-1) {\n        pool.reserve(reserve_size);\n\
    \    }\n\n    // prod(ql, qr): op-product of [ql, qr)\n    T prod(Idx ql, Idx\
    \ qr) const {\n        assert(lo <= ql && qr <= hi);\n        return _prod(root,\
    \ lo, hi, ql, qr);\n    }\n\n    T all_prod() const { return node_val(root); }\n\
    \n    // get(pos): value at pos\n    T get(Idx pos) const {\n        assert(lo\
    \ <= pos && pos < hi);\n        return _prod(root, lo, hi, pos, pos + 1);\n  \
    \  }\n\n    // set(pos, val): a[pos] = val\n    void set(Idx pos, T val) {\n \
    \       assert(lo <= pos && pos < hi);\n        _set(root, lo, hi, pos, val);\n\
    \    }\n\n    // apply(pos, val): a[pos] = op(a[pos], val)\n    void apply(Idx\
    \ pos, T val) {\n        assert(lo <= pos && pos < hi);\n        _apply(root,\
    \ lo, hi, pos, val);\n    }\n\n    // max_right(ql, f):\n    //   Returns r in\
    \ [ql, hi] s.t. f(prod(ql, r)) == true\n    //   and (r == hi  or  f(prod(ql,\
    \ r+1)) == false).\n    //   Precondition: f(e()) == true, f must be monotone.\n\
    \    template <class F>\n    Idx max_right(Idx ql, const F& f) const {\n     \
    \   assert(lo <= ql && ql <= hi);\n        assert(f(e()));\n        T acc = e();\n\
    \        return _max_right(root, lo, hi, ql, acc, f);\n    }\n\n    // min_left(qr,\
    \ f):\n    //   Returns l in [lo, qr] s.t. f(prod(l, qr)) == true\n    //   and\
    \ (l == lo  or  f(prod(l-1, qr)) == false).\n    //   Precondition: f(e()) ==\
    \ true, f must be monotone.\n    template <class F>\n    Idx min_left(Idx qr,\
    \ const F& f) const {\n        assert(lo <= qr && qr <= hi);\n        assert(f(e()));\n\
    \        T acc = e();\n        return _min_left(root, lo, hi, qr, acc, f);\n \
    \   }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/dynamic_segtree.hpp
  requiredBy: []
  timestamp: '2026-03-10 09:14:03+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/library_checker_ordered_set.test.cpp
documentation_of: structure/dynamic_segtree.hpp
layout: document
redirect_from:
- /library/structure/dynamic_segtree.hpp
- /library/structure/dynamic_segtree.hpp.html
title: structure/dynamic_segtree.hpp
---
