---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker_majority_voting.test.cpp
    title: verify/library_checker_majority_voting.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"structure/majority_vote.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n// Boyer-Moore majority voting  (single-pass streaming)\n\
    // After pushing N elements, query() returns the majority candidate.\n// IMPORTANT:\
    \ verify externally that the candidate appears > N/2 times.\ntemplate <class T\
    \ = int>\nstruct majority_vote {\n    T cand{};\n    int cnt = 0;\n\n    void\
    \ push(T x) {\n        if (cnt == 0) { cand = x; cnt = 1; }\n        else if (cand\
    \ == x) ++cnt;\n        else --cnt;\n    }\n    T   query()          const { return\
    \ cand; }\n    bool has_candidate() const { return cnt > 0; }\n    void clear()\
    \ { cand = T{}; cnt = 0; }\n};\n\n// Segment-tree-based majority query with point\
    \ updates\n// S = pair<T, int>: {candidate, excess}\n// Use with segtree<S, bm_op<T>,\
    \ bm_e<T>>\n//\n// After query(l, r), the returned candidate MIGHT be the majority.\n\
    // Verify by counting occurrences externally (e.g. using map<T, pbds_set>).\n\n\
    template <class T = int>\nstruct majority_segtree {\n    using S = pair<T, int>;\n\
    \n    static S bm_op(S a, S b) {\n        if (a.second == 0) return b;\n     \
    \   if (b.second == 0) return a;\n        if (a.first == b.first) return {a.first,\
    \ a.second + b.second};\n        if (a.second > b.second) return {a.first, a.second\
    \ - b.second};\n        if (a.second < b.second) return {b.first, b.second - a.second};\n\
    \        return {b.first, 0};\n    }\n    static S bm_e() { return {T{}, 0}; }\n\
    \n    int n;\n    vector<S> seg;\n\n    majority_segtree() = default;\n    majority_segtree(const\
    \ vector<T>& a) : n(a.size()), seg(4 * a.size()) {\n        build(a, 1, 0, n);\n\
    \    }\n\n    void build(const vector<T>& a, int v, int l, int r) {\n        if\
    \ (r - l == 1) { seg[v] = {a[l], 1}; return; }\n        int m = (l + r) / 2;\n\
    \        build(a, 2*v, l, m); build(a, 2*v+1, m, r);\n        seg[v] = bm_op(seg[2*v],\
    \ seg[2*v+1]);\n    }\n    void set(int i, T x, int v, int l, int r) {\n     \
    \   if (r - l == 1) { seg[v] = {x, 1}; return; }\n        int m = (l + r) / 2;\n\
    \        if (i < m) set(i, x, 2*v, l, m); else set(i, x, 2*v+1, m, r);\n     \
    \   seg[v] = bm_op(seg[2*v], seg[2*v+1]);\n    }\n    S query(int ql, int qr,\
    \ int v, int l, int r) {\n        if (qr <= l || r <= ql) return bm_e();\n   \
    \     if (ql <= l && r <= qr) return seg[v];\n        int m = (l + r) / 2;\n \
    \       return bm_op(query(ql, qr, 2*v, l, m), query(ql, qr, 2*v+1, m, r));\n\
    \    }\n\n    void set(int i, T x)       { set(i, x, 1, 0, n); }\n    // Returns\
    \ BM candidate for a[l..r). Verify count externally!\n    S query(int l, int r)\
    \      { return query(l, r, 1, 0, n); }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n// Boyer-Moore\
    \ majority voting  (single-pass streaming)\n// After pushing N elements, query()\
    \ returns the majority candidate.\n// IMPORTANT: verify externally that the candidate\
    \ appears > N/2 times.\ntemplate <class T = int>\nstruct majority_vote {\n   \
    \ T cand{};\n    int cnt = 0;\n\n    void push(T x) {\n        if (cnt == 0) {\
    \ cand = x; cnt = 1; }\n        else if (cand == x) ++cnt;\n        else --cnt;\n\
    \    }\n    T   query()          const { return cand; }\n    bool has_candidate()\
    \ const { return cnt > 0; }\n    void clear() { cand = T{}; cnt = 0; }\n};\n\n\
    // Segment-tree-based majority query with point updates\n// S = pair<T, int>:\
    \ {candidate, excess}\n// Use with segtree<S, bm_op<T>, bm_e<T>>\n//\n// After\
    \ query(l, r), the returned candidate MIGHT be the majority.\n// Verify by counting\
    \ occurrences externally (e.g. using map<T, pbds_set>).\n\ntemplate <class T =\
    \ int>\nstruct majority_segtree {\n    using S = pair<T, int>;\n\n    static S\
    \ bm_op(S a, S b) {\n        if (a.second == 0) return b;\n        if (b.second\
    \ == 0) return a;\n        if (a.first == b.first) return {a.first, a.second +\
    \ b.second};\n        if (a.second > b.second) return {a.first, a.second - b.second};\n\
    \        if (a.second < b.second) return {b.first, b.second - a.second};\n   \
    \     return {b.first, 0};\n    }\n    static S bm_e() { return {T{}, 0}; }\n\n\
    \    int n;\n    vector<S> seg;\n\n    majority_segtree() = default;\n    majority_segtree(const\
    \ vector<T>& a) : n(a.size()), seg(4 * a.size()) {\n        build(a, 1, 0, n);\n\
    \    }\n\n    void build(const vector<T>& a, int v, int l, int r) {\n        if\
    \ (r - l == 1) { seg[v] = {a[l], 1}; return; }\n        int m = (l + r) / 2;\n\
    \        build(a, 2*v, l, m); build(a, 2*v+1, m, r);\n        seg[v] = bm_op(seg[2*v],\
    \ seg[2*v+1]);\n    }\n    void set(int i, T x, int v, int l, int r) {\n     \
    \   if (r - l == 1) { seg[v] = {x, 1}; return; }\n        int m = (l + r) / 2;\n\
    \        if (i < m) set(i, x, 2*v, l, m); else set(i, x, 2*v+1, m, r);\n     \
    \   seg[v] = bm_op(seg[2*v], seg[2*v+1]);\n    }\n    S query(int ql, int qr,\
    \ int v, int l, int r) {\n        if (qr <= l || r <= ql) return bm_e();\n   \
    \     if (ql <= l && r <= qr) return seg[v];\n        int m = (l + r) / 2;\n \
    \       return bm_op(query(ql, qr, 2*v, l, m), query(ql, qr, 2*v+1, m, r));\n\
    \    }\n\n    void set(int i, T x)       { set(i, x, 1, 0, n); }\n    // Returns\
    \ BM candidate for a[l..r). Verify count externally!\n    S query(int l, int r)\
    \      { return query(l, r, 1, 0, n); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/majority_vote.hpp
  requiredBy: []
  timestamp: '2026-03-10 02:22:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker_majority_voting.test.cpp
documentation_of: structure/majority_vote.hpp
layout: document
redirect_from:
- /library/structure/majority_vote.hpp
- /library/structure/majority_vote.hpp.html
title: structure/majority_vote.hpp
---
