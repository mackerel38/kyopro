---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker_range_kth_smallest.test.cpp
    title: verify/library_checker_range_kth_smallest.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"structure/wavelet_matrix.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n// Wavelet Matrix\n// Operations on a static sequence\
    \ a[0..n)  of non-negative integers.\n// All values must be < (1 << B) after coordinate\
    \ compression.\n//\n// O(n B) build,  O(B) per query  (B = number of bits, default\
    \ 20)\n//\n// Queries:\n//   kth(l, r, k)              k-th (0-indexed) smallest\
    \ in a[l..r)\n//   count(l, r, x)            number of occurrences of x in a[l..r)\n\
    //   count_lt(l, r, x)         number of elements < x in a[l..r)\n//   range_freq(l,\
    \ r, lo, hi)  count of elements in [lo, hi) in a[l..r)\n\ntemplate <int B = 20>\n\
    struct wavelet_matrix {\n    // Succinct bit vector with rank\n    struct bv {\n\
    \        vector<uint32_t> blk;\n        vector<int> cum;\n        int n;\n   \
    \     template <class F>\n        void build(int sz, F get) {\n            n =\
    \ sz;\n            blk.assign((n + 31) >> 5, 0);\n            cum.resize(blk.size()\
    \ + 1, 0);\n            for (int i = 0; i < n; i++) if (get(i)) blk[i >> 5] |=\
    \ 1u << (i & 31);\n            for (int i = 0; i < (int)blk.size(); i++)\n   \
    \             cum[i+1] = cum[i] + __builtin_popcount(blk[i]);\n        }\n   \
    \     // number of 1s in [0, i)\n        int rank1(int i) const {\n          \
    \  if (i <= 0) return 0;\n            return cum[i >> 5] + __builtin_popcount(blk[i\
    \ >> 5] & ((1u << (i & 31)) - 1));\n        }\n        int rank0(int i) const\
    \ { return i - rank1(i); }\n        int total1() const { return cum.back(); }\n\
    \    };\n\n    int n;\n    array<bv, B> bvs;\n    array<int, B> mid; // number\
    \ of 0s at each level\n\n    wavelet_matrix() = default;\n\n    // Build from\
    \ vector. Values must be in [0, 2^B).\n    void build(vector<int> v) {\n     \
    \   n = v.size();\n        for (int d = B - 1; d >= 0; d--) {\n            bvs[d].build(n,\
    \ [&](int i){ return (v[i] >> d) & 1; });\n            mid[d] = bvs[d].rank0(n);\n\
    \            vector<int> a0, a1;\n            for (int x : v) ((x >> d) & 1 ?\
    \ a1 : a0).push_back(x);\n            v = a0; v.insert(v.end(), a1.begin(), a1.end());\n\
    \        }\n    }\n\n    pair<int,int> _down(int d, int l, int r, int bit) const\
    \ {\n        int l0 = bvs[d].rank0(l), r0 = bvs[d].rank0(r);\n        if (bit\
    \ == 0) return {l0, r0};\n        return {mid[d] + l - l0, mid[d] + r - r0};\n\
    \    }\n\n    // k-th (0-indexed) smallest in a[l..r)\n    int kth(int l, int\
    \ r, int k) const {\n        int res = 0;\n        for (int d = B - 1; d >= 0;\
    \ d--) {\n            int cnt0 = bvs[d].rank0(r) - bvs[d].rank0(l);\n        \
    \    if (k < cnt0) { tie(l, r) = _down(d, l, r, 0); }\n            else { k -=\
    \ cnt0; res |= (1 << d); tie(l, r) = _down(d, l, r, 1); }\n        }\n       \
    \ return res;\n    }\n\n    // number of elements < x in a[l..r)\n    int count_lt(int\
    \ l, int r, int x) const {\n        int cnt = 0;\n        for (int d = B - 1;\
    \ d >= 0; d--) {\n            int b = (x >> d) & 1;\n            if (b) cnt +=\
    \ bvs[d].rank0(r) - bvs[d].rank0(l);\n            tie(l, r) = _down(d, l, r, b);\n\
    \        }\n        return cnt;\n    }\n\n    // number of occurrences of x in\
    \ a[l..r)\n    int count(int l, int r, int x) const {\n        for (int d = B\
    \ - 1; d >= 0; d--)\n            tie(l, r) = _down(d, l, r, (x >> d) & 1);\n \
    \       return r - l;\n    }\n\n    // number of elements in [lo, hi) in a[l..r)\n\
    \    int range_freq(int l, int r, int lo, int hi) const {\n        return count_lt(l,\
    \ r, hi) - count_lt(l, r, lo);\n    }\n};\n\n// Wavelet matrix with sum support\
    \  (O(B) sum_lt queries)\n// Stores prefix sums at each level of the wavelet matrix.\n\
    template <int B = 20>\nstruct wavelet_matrix_sum : wavelet_matrix<B> {\n    using\
    \ base = wavelet_matrix<B>;\n    array<vector<long long>, B> lpsum;\n\n    void\
    \ build(vector<int> v) {\n        base::build(v);\n        int n = v.size();\n\
    \        for (int d = B - 1; d >= 0; d--) {\n            lpsum[d].resize(n + 1,\
    \ 0);\n            vector<int> a0, a1;\n            for (int x : v) ((x >> d)\
    \ & 1 ? a1 : a0).push_back(x);\n            for (int i = 0; i < (int)a0.size();\
    \ i++) lpsum[d][i+1] = lpsum[d][i] + a0[i];\n            int off = a0.size();\n\
    \            for (int i = 0; i < (int)a1.size(); i++) lpsum[d][off+i+1] = lpsum[d][off+i]\
    \ + a1[i];\n            v = a0; v.insert(v.end(), a1.begin(), a1.end());\n   \
    \     }\n    }\n\n    // sum of elements < x in a[l..r)  O(B)\n    long long sum_lt(int\
    \ l, int r, int x) const {\n        long long s = 0;\n        int cl = l, cr =\
    \ r;\n        for (int d = B - 1; d >= 0; d--) {\n            int b = (x >> d)\
    \ & 1;\n            int l0 = base::bvs[d].rank0(cl), r0 = base::bvs[d].rank0(cr);\n\
    \            if (b) {\n                s += lpsum[d][r0] - lpsum[d][l0];\n   \
    \             cl = base::mid[d] + (cl - l0);\n                cr = base::mid[d]\
    \ + (cr - r0);\n            } else {\n                cl = l0; cr = r0;\n    \
    \        }\n        }\n        return s;\n    }\n\n    // sum of elements in [lo,\
    \ hi) in a[l..r)\n    long long range_sum(int l, int r, int lo, int hi) const\
    \ {\n        return sum_lt(l, r, hi) - sum_lt(l, r, lo);\n    }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n// Wavelet\
    \ Matrix\n// Operations on a static sequence a[0..n)  of non-negative integers.\n\
    // All values must be < (1 << B) after coordinate compression.\n//\n// O(n B)\
    \ build,  O(B) per query  (B = number of bits, default 20)\n//\n// Queries:\n\
    //   kth(l, r, k)              k-th (0-indexed) smallest in a[l..r)\n//   count(l,\
    \ r, x)            number of occurrences of x in a[l..r)\n//   count_lt(l, r,\
    \ x)         number of elements < x in a[l..r)\n//   range_freq(l, r, lo, hi)\
    \  count of elements in [lo, hi) in a[l..r)\n\ntemplate <int B = 20>\nstruct wavelet_matrix\
    \ {\n    // Succinct bit vector with rank\n    struct bv {\n        vector<uint32_t>\
    \ blk;\n        vector<int> cum;\n        int n;\n        template <class F>\n\
    \        void build(int sz, F get) {\n            n = sz;\n            blk.assign((n\
    \ + 31) >> 5, 0);\n            cum.resize(blk.size() + 1, 0);\n            for\
    \ (int i = 0; i < n; i++) if (get(i)) blk[i >> 5] |= 1u << (i & 31);\n       \
    \     for (int i = 0; i < (int)blk.size(); i++)\n                cum[i+1] = cum[i]\
    \ + __builtin_popcount(blk[i]);\n        }\n        // number of 1s in [0, i)\n\
    \        int rank1(int i) const {\n            if (i <= 0) return 0;\n       \
    \     return cum[i >> 5] + __builtin_popcount(blk[i >> 5] & ((1u << (i & 31))\
    \ - 1));\n        }\n        int rank0(int i) const { return i - rank1(i); }\n\
    \        int total1() const { return cum.back(); }\n    };\n\n    int n;\n   \
    \ array<bv, B> bvs;\n    array<int, B> mid; // number of 0s at each level\n\n\
    \    wavelet_matrix() = default;\n\n    // Build from vector. Values must be in\
    \ [0, 2^B).\n    void build(vector<int> v) {\n        n = v.size();\n        for\
    \ (int d = B - 1; d >= 0; d--) {\n            bvs[d].build(n, [&](int i){ return\
    \ (v[i] >> d) & 1; });\n            mid[d] = bvs[d].rank0(n);\n            vector<int>\
    \ a0, a1;\n            for (int x : v) ((x >> d) & 1 ? a1 : a0).push_back(x);\n\
    \            v = a0; v.insert(v.end(), a1.begin(), a1.end());\n        }\n   \
    \ }\n\n    pair<int,int> _down(int d, int l, int r, int bit) const {\n       \
    \ int l0 = bvs[d].rank0(l), r0 = bvs[d].rank0(r);\n        if (bit == 0) return\
    \ {l0, r0};\n        return {mid[d] + l - l0, mid[d] + r - r0};\n    }\n\n   \
    \ // k-th (0-indexed) smallest in a[l..r)\n    int kth(int l, int r, int k) const\
    \ {\n        int res = 0;\n        for (int d = B - 1; d >= 0; d--) {\n      \
    \      int cnt0 = bvs[d].rank0(r) - bvs[d].rank0(l);\n            if (k < cnt0)\
    \ { tie(l, r) = _down(d, l, r, 0); }\n            else { k -= cnt0; res |= (1\
    \ << d); tie(l, r) = _down(d, l, r, 1); }\n        }\n        return res;\n  \
    \  }\n\n    // number of elements < x in a[l..r)\n    int count_lt(int l, int\
    \ r, int x) const {\n        int cnt = 0;\n        for (int d = B - 1; d >= 0;\
    \ d--) {\n            int b = (x >> d) & 1;\n            if (b) cnt += bvs[d].rank0(r)\
    \ - bvs[d].rank0(l);\n            tie(l, r) = _down(d, l, r, b);\n        }\n\
    \        return cnt;\n    }\n\n    // number of occurrences of x in a[l..r)\n\
    \    int count(int l, int r, int x) const {\n        for (int d = B - 1; d >=\
    \ 0; d--)\n            tie(l, r) = _down(d, l, r, (x >> d) & 1);\n        return\
    \ r - l;\n    }\n\n    // number of elements in [lo, hi) in a[l..r)\n    int range_freq(int\
    \ l, int r, int lo, int hi) const {\n        return count_lt(l, r, hi) - count_lt(l,\
    \ r, lo);\n    }\n};\n\n// Wavelet matrix with sum support  (O(B) sum_lt queries)\n\
    // Stores prefix sums at each level of the wavelet matrix.\ntemplate <int B =\
    \ 20>\nstruct wavelet_matrix_sum : wavelet_matrix<B> {\n    using base = wavelet_matrix<B>;\n\
    \    array<vector<long long>, B> lpsum;\n\n    void build(vector<int> v) {\n \
    \       base::build(v);\n        int n = v.size();\n        for (int d = B - 1;\
    \ d >= 0; d--) {\n            lpsum[d].resize(n + 1, 0);\n            vector<int>\
    \ a0, a1;\n            for (int x : v) ((x >> d) & 1 ? a1 : a0).push_back(x);\n\
    \            for (int i = 0; i < (int)a0.size(); i++) lpsum[d][i+1] = lpsum[d][i]\
    \ + a0[i];\n            int off = a0.size();\n            for (int i = 0; i <\
    \ (int)a1.size(); i++) lpsum[d][off+i+1] = lpsum[d][off+i] + a1[i];\n        \
    \    v = a0; v.insert(v.end(), a1.begin(), a1.end());\n        }\n    }\n\n  \
    \  // sum of elements < x in a[l..r)  O(B)\n    long long sum_lt(int l, int r,\
    \ int x) const {\n        long long s = 0;\n        int cl = l, cr = r;\n    \
    \    for (int d = B - 1; d >= 0; d--) {\n            int b = (x >> d) & 1;\n \
    \           int l0 = base::bvs[d].rank0(cl), r0 = base::bvs[d].rank0(cr);\n  \
    \          if (b) {\n                s += lpsum[d][r0] - lpsum[d][l0];\n     \
    \           cl = base::mid[d] + (cl - l0);\n                cr = base::mid[d]\
    \ + (cr - r0);\n            } else {\n                cl = l0; cr = r0;\n    \
    \        }\n        }\n        return s;\n    }\n\n    // sum of elements in [lo,\
    \ hi) in a[l..r)\n    long long range_sum(int l, int r, int lo, int hi) const\
    \ {\n        return sum_lt(l, r, hi) - sum_lt(l, r, lo);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/wavelet_matrix.hpp
  requiredBy: []
  timestamp: '2026-03-09 22:49:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker_range_kth_smallest.test.cpp
documentation_of: structure/wavelet_matrix.hpp
layout: document
redirect_from:
- /library/structure/wavelet_matrix.hpp
- /library/structure/wavelet_matrix.hpp.html
title: structure/wavelet_matrix.hpp
---
