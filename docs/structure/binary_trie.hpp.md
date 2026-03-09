---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/library_checker_set_xor_min.test.cpp
    title: verify/library_checker_set_xor_min.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"structure/binary_trie.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n// Binary trie  (non-negative integers, B-bit keys)\n\
    // Operations in O(B):\n//   insert(x), erase(x)\n//   count(x)     -- number\
    \ of x stored\n//   size()       -- total count\n//   min_element()  -- minimum\
    \ stored value\n//   max_element()  -- maximum stored value\n//   xor_min(x) \
    \  -- min(v XOR x) over all stored v  (\"set_xor_min\" problem)\n//   kth(k) \
    \      -- k-th (0-indexed) smallest\n//   lower_bound(x) -- count of elements\
    \ < x\n\ntemplate <int B = 30>\nstruct binary_trie {\n    struct Node {\n    \
    \    int ch[2] = {-1, -1};\n        int cnt = 0;\n    };\n    vector<Node> nd;\n\
    \n    binary_trie() { nd.push_back({}); } // root = 0\n\n    int _new() { nd.push_back({});\
    \ return nd.size() - 1; }\n\n    void insert(int x, int delta = 1) {\n       \
    \ int v = 0;\n        nd[0].cnt += delta;\n        for (int i = B - 1; i >= 0;\
    \ i--) {\n            int b = (x >> i) & 1;\n            if (nd[v].ch[b] == -1)\
    \ nd[v].ch[b] = _new();\n            v = nd[v].ch[b];\n            nd[v].cnt +=\
    \ delta;\n        }\n    }\n    void erase(int x) { insert(x, -1); }\n\n    int\
    \ count(int x) const {\n        int v = 0;\n        for (int i = B - 1; i >= 0;\
    \ i--) {\n            int b = (x >> i) & 1;\n            if (nd[v].ch[b] == -1)\
    \ return 0;\n            v = nd[v].ch[b];\n        }\n        return nd[v].cnt;\n\
    \    }\n    int size() const { return nd[0].cnt; }\n    bool empty() const { return\
    \ nd[0].cnt == 0; }\n\n    // k-th (0-indexed) smallest\n    int kth(int k) const\
    \ {\n        assert(0 <= k && k < size());\n        int v = 0, res = 0;\n    \
    \    for (int i = B - 1; i >= 0; i--) {\n            int l = nd[v].ch[0], lc =\
    \ (l == -1 ? 0 : nd[l].cnt);\n            if (k < lc) { v = l; }\n           \
    \ else { k -= lc; res |= (1 << i); v = nd[v].ch[1]; }\n        }\n        return\
    \ res;\n    }\n    int min_element() const { return kth(0); }\n    int max_element()\
    \ const { return kth(size() - 1); }\n\n    // min XOR with x\n    int xor_min(int\
    \ x) const {\n        assert(!empty());\n        int v = 0, res = 0;\n       \
    \ for (int i = B - 1; i >= 0; i--) {\n            int b = (x >> i) & 1;\n    \
    \        int want = b; // prefer same bit => XOR becomes 0\n            if (nd[v].ch[want]\
    \ == -1 || nd[nd[v].ch[want]].cnt == 0) want ^= 1;\n            res |= ((want\
    \ ^ b) << i);\n            v = nd[v].ch[want];\n        }\n        return res;\n\
    \    }\n\n    // number of elements < x\n    int lower_bound(int x) const {\n\
    \        int v = 0, cnt = 0;\n        for (int i = B - 1; i >= 0; i--) {\n   \
    \         int b = (x >> i) & 1;\n            if (b == 1) {\n                int\
    \ l = nd[v].ch[0];\n                if (l != -1) cnt += nd[l].cnt;\n         \
    \   }\n            if (nd[v].ch[b] == -1) break;\n            v = nd[v].ch[b];\n\
    \        }\n        return cnt;\n    }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n// Binary\
    \ trie  (non-negative integers, B-bit keys)\n// Operations in O(B):\n//   insert(x),\
    \ erase(x)\n//   count(x)     -- number of x stored\n//   size()       -- total\
    \ count\n//   min_element()  -- minimum stored value\n//   max_element()  -- maximum\
    \ stored value\n//   xor_min(x)   -- min(v XOR x) over all stored v  (\"set_xor_min\"\
    \ problem)\n//   kth(k)       -- k-th (0-indexed) smallest\n//   lower_bound(x)\
    \ -- count of elements < x\n\ntemplate <int B = 30>\nstruct binary_trie {\n  \
    \  struct Node {\n        int ch[2] = {-1, -1};\n        int cnt = 0;\n    };\n\
    \    vector<Node> nd;\n\n    binary_trie() { nd.push_back({}); } // root = 0\n\
    \n    int _new() { nd.push_back({}); return nd.size() - 1; }\n\n    void insert(int\
    \ x, int delta = 1) {\n        int v = 0;\n        nd[0].cnt += delta;\n     \
    \   for (int i = B - 1; i >= 0; i--) {\n            int b = (x >> i) & 1;\n  \
    \          if (nd[v].ch[b] == -1) nd[v].ch[b] = _new();\n            v = nd[v].ch[b];\n\
    \            nd[v].cnt += delta;\n        }\n    }\n    void erase(int x) { insert(x,\
    \ -1); }\n\n    int count(int x) const {\n        int v = 0;\n        for (int\
    \ i = B - 1; i >= 0; i--) {\n            int b = (x >> i) & 1;\n            if\
    \ (nd[v].ch[b] == -1) return 0;\n            v = nd[v].ch[b];\n        }\n   \
    \     return nd[v].cnt;\n    }\n    int size() const { return nd[0].cnt; }\n \
    \   bool empty() const { return nd[0].cnt == 0; }\n\n    // k-th (0-indexed) smallest\n\
    \    int kth(int k) const {\n        assert(0 <= k && k < size());\n        int\
    \ v = 0, res = 0;\n        for (int i = B - 1; i >= 0; i--) {\n            int\
    \ l = nd[v].ch[0], lc = (l == -1 ? 0 : nd[l].cnt);\n            if (k < lc) {\
    \ v = l; }\n            else { k -= lc; res |= (1 << i); v = nd[v].ch[1]; }\n\
    \        }\n        return res;\n    }\n    int min_element() const { return kth(0);\
    \ }\n    int max_element() const { return kth(size() - 1); }\n\n    // min XOR\
    \ with x\n    int xor_min(int x) const {\n        assert(!empty());\n        int\
    \ v = 0, res = 0;\n        for (int i = B - 1; i >= 0; i--) {\n            int\
    \ b = (x >> i) & 1;\n            int want = b; // prefer same bit => XOR becomes\
    \ 0\n            if (nd[v].ch[want] == -1 || nd[nd[v].ch[want]].cnt == 0) want\
    \ ^= 1;\n            res |= ((want ^ b) << i);\n            v = nd[v].ch[want];\n\
    \        }\n        return res;\n    }\n\n    // number of elements < x\n    int\
    \ lower_bound(int x) const {\n        int v = 0, cnt = 0;\n        for (int i\
    \ = B - 1; i >= 0; i--) {\n            int b = (x >> i) & 1;\n            if (b\
    \ == 1) {\n                int l = nd[v].ch[0];\n                if (l != -1)\
    \ cnt += nd[l].cnt;\n            }\n            if (nd[v].ch[b] == -1) break;\n\
    \            v = nd[v].ch[b];\n        }\n        return cnt;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/binary_trie.hpp
  requiredBy: []
  timestamp: '2026-03-09 22:49:24+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/library_checker_set_xor_min.test.cpp
documentation_of: structure/binary_trie.hpp
layout: document
redirect_from:
- /library/structure/binary_trie.hpp
- /library/structure/binary_trie.hpp.html
title: structure/binary_trie.hpp
---
