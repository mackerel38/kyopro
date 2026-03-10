---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker_double_ended_priority_queue.test.cpp
    title: verify/library_checker_double_ended_priority_queue.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"structure/bipq.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n// Double-Ended Priority Queue using Interval Heap.\n// Each node stores\
    \ an interval [lo, hi] with lo <= hi.\n// Invariants (over parent-child pairs):\n\
    //   parent.lo <= child.lo   (min-heap on lo)\n//   parent.hi >= child.hi   (max-heap\
    \ on hi)\n// Thus root holds the global minimum (lo) and maximum (hi).\n//\n//\
    \ Complexity: push / pop_min / pop_max in O(log n), top_min / top_max in O(1).\n\
    // Template parameter Compare: cmp(a, b) == true iff a is strictly less than b.\n\
    template <class T, class Compare = less<T>>\nstruct bipq {\nprivate:\n    vector<pair<T,\
    \ T>> h;  // h[i] = {lo, hi}\n    int _sz = 0;\n    [[no_unique_address]] Compare\
    \ cmp;\n\n    // For the partial last node (_sz odd), only h.back().first is valid.\n\
    \    // hi_ref / hi_val transparently handle this.\n    T& hi_ref(int i) noexcept\
    \ {\n        return (i == (int)h.size() - 1 && _sz % 2 == 1) ? h[i].first : h[i].second;\n\
    \    }\n    const T& hi_val(int i) const noexcept {\n        return (i == (int)h.size()\
    \ - 1 && _sz % 2 == 1) ? h[i].first : h[i].second;\n    }\n\n    void sift_up_min(int\
    \ i) {\n        while (i > 0) {\n            int p = (i - 1) / 2;\n          \
    \  if (cmp(h[i].first, h[p].first)) {\n                swap(h[i].first, h[p].first);\n\
    \                i = p;\n            } else break;\n        }\n    }\n\n    void\
    \ sift_up_max(int i) {\n        while (i > 0) {\n            int p = (i - 1) /\
    \ 2;\n            if (cmp(h[p].second, hi_val(i))) {\n                swap(hi_ref(i),\
    \ h[p].second);\n                i = p;\n            } else break;\n        }\n\
    \    }\n\n    void sift_down_min(int i) {\n        int n = (int)h.size();\n  \
    \      while (true) {\n            int c = 2 * i + 1;\n            if (c >= n)\
    \ break;\n            if (c + 1 < n && cmp(h[c + 1].first, h[c].first)) c++;\n\
    \            if (cmp(h[c].first, h[i].first)) {\n                swap(h[i].first,\
    \ h[c].first);\n                // Restore lo <= hi within node c\n          \
    \      if (cmp(hi_val(c), h[c].first)) swap(h[c].first, hi_ref(c));\n        \
    \        i = c;\n            } else break;\n        }\n    }\n\n    void sift_down_max(int\
    \ i) {\n        int n = (int)h.size();\n        while (true) {\n            int\
    \ c = 2 * i + 1;\n            if (c >= n) break;\n            if (c + 1 < n &&\
    \ cmp(hi_val(c), hi_val(c + 1))) c++;\n            if (cmp(h[i].second, hi_val(c)))\
    \ {\n                swap(hi_ref(c), h[i].second);\n                // Restore\
    \ lo <= hi within node c\n                if (cmp(hi_val(c), h[c].first)) swap(h[c].first,\
    \ hi_ref(c));\n                i = c;\n            } else break;\n        }\n\
    \    }\n\npublic:\n    bipq() = default;\n    explicit bipq(Compare c) : cmp(c)\
    \ {}\n    template <class Iter>\n    bipq(Iter first, Iter last) { for (auto it\
    \ = first; it != last; ++it) push(*it); }\n    bipq(initializer_list<T> il) :\
    \ bipq(il.begin(), il.end()) {}\n\n    int  size()  const noexcept { return _sz;\
    \ }\n    bool empty() const noexcept { return _sz == 0; }\n\n    // Minimum element\
    \ (undefined if empty)\n    const T& top_min() const {\n        assert(_sz > 0);\n\
    \        return h[0].first;\n    }\n\n    // Maximum element (undefined if empty)\n\
    \    const T& top_max() const {\n        assert(_sz > 0);\n        return hi_val(0);\n\
    \    }\n\n    void push(const T& x) {\n        if (_sz % 2 == 0) {\n         \
    \   // Start a new (partial) leaf node\n            h.push_back({x, x});\n   \
    \         _sz++;\n            int i = (int)h.size() - 1;\n            sift_up_min(i);\n\
    \            sift_up_max(i);\n        } else {\n            // Complete the last\
    \ partial node\n            int i = (int)h.size() - 1;\n            if (cmp(x,\
    \ h[i].first)) {\n                h[i].second = h[i].first;\n                h[i].first\
    \  = x;\n            } else {\n                h[i].second = x;\n            }\n\
    \            _sz++;\n            sift_up_min(i);\n            sift_up_max(i);\n\
    \        }\n    }\n\n    void pop_min() {\n        assert(_sz > 0);\n        if\
    \ (_sz == 1) { h.pop_back(); _sz = 0; return; }\n        if (_sz == 2) { h[0].first\
    \ = h[0].second; _sz = 1; return; }\n\n        int last = (int)h.size() - 1;\n\
    \        T x;\n        if (_sz % 2 == 1) {\n            // Last node is partial:\
    \ take its only element and remove the node\n            x = h[last].first;\n\
    \            h.pop_back();\n        } else {\n            // Last node is full:\
    \ take hi, leaving it partial (handled by _sz--)\n            x = h[last].second;\n\
    \        }\n        _sz--;\n\n        h[0].first = x;\n        // Restore lo <=\
    \ hi at root if needed\n        if (cmp(h[0].second, h[0].first)) swap(h[0].first,\
    \ h[0].second);\n        sift_down_min(0);\n    }\n\n    void pop_max() {\n  \
    \      assert(_sz > 0);\n        if (_sz == 1) { h.pop_back(); _sz = 0; return;\
    \ }\n        if (_sz == 2) { _sz = 1; return; }  // only h[0].first remains\n\n\
    \        int last = (int)h.size() - 1;\n        T x;\n        if (_sz % 2 == 1)\
    \ {\n            x = h[last].first;\n            h.pop_back();\n        } else\
    \ {\n            x = h[last].second;\n        }\n        _sz--;\n\n        h[0].second\
    \ = x;\n        if (cmp(h[0].second, h[0].first)) swap(h[0].first, h[0].second);\n\
    \        sift_down_max(0);\n    }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n// Double-Ended\
    \ Priority Queue using Interval Heap.\n// Each node stores an interval [lo, hi]\
    \ with lo <= hi.\n// Invariants (over parent-child pairs):\n//   parent.lo <=\
    \ child.lo   (min-heap on lo)\n//   parent.hi >= child.hi   (max-heap on hi)\n\
    // Thus root holds the global minimum (lo) and maximum (hi).\n//\n// Complexity:\
    \ push / pop_min / pop_max in O(log n), top_min / top_max in O(1).\n// Template\
    \ parameter Compare: cmp(a, b) == true iff a is strictly less than b.\ntemplate\
    \ <class T, class Compare = less<T>>\nstruct bipq {\nprivate:\n    vector<pair<T,\
    \ T>> h;  // h[i] = {lo, hi}\n    int _sz = 0;\n    [[no_unique_address]] Compare\
    \ cmp;\n\n    // For the partial last node (_sz odd), only h.back().first is valid.\n\
    \    // hi_ref / hi_val transparently handle this.\n    T& hi_ref(int i) noexcept\
    \ {\n        return (i == (int)h.size() - 1 && _sz % 2 == 1) ? h[i].first : h[i].second;\n\
    \    }\n    const T& hi_val(int i) const noexcept {\n        return (i == (int)h.size()\
    \ - 1 && _sz % 2 == 1) ? h[i].first : h[i].second;\n    }\n\n    void sift_up_min(int\
    \ i) {\n        while (i > 0) {\n            int p = (i - 1) / 2;\n          \
    \  if (cmp(h[i].first, h[p].first)) {\n                swap(h[i].first, h[p].first);\n\
    \                i = p;\n            } else break;\n        }\n    }\n\n    void\
    \ sift_up_max(int i) {\n        while (i > 0) {\n            int p = (i - 1) /\
    \ 2;\n            if (cmp(h[p].second, hi_val(i))) {\n                swap(hi_ref(i),\
    \ h[p].second);\n                i = p;\n            } else break;\n        }\n\
    \    }\n\n    void sift_down_min(int i) {\n        int n = (int)h.size();\n  \
    \      while (true) {\n            int c = 2 * i + 1;\n            if (c >= n)\
    \ break;\n            if (c + 1 < n && cmp(h[c + 1].first, h[c].first)) c++;\n\
    \            if (cmp(h[c].first, h[i].first)) {\n                swap(h[i].first,\
    \ h[c].first);\n                // Restore lo <= hi within node c\n          \
    \      if (cmp(hi_val(c), h[c].first)) swap(h[c].first, hi_ref(c));\n        \
    \        i = c;\n            } else break;\n        }\n    }\n\n    void sift_down_max(int\
    \ i) {\n        int n = (int)h.size();\n        while (true) {\n            int\
    \ c = 2 * i + 1;\n            if (c >= n) break;\n            if (c + 1 < n &&\
    \ cmp(hi_val(c), hi_val(c + 1))) c++;\n            if (cmp(h[i].second, hi_val(c)))\
    \ {\n                swap(hi_ref(c), h[i].second);\n                // Restore\
    \ lo <= hi within node c\n                if (cmp(hi_val(c), h[c].first)) swap(h[c].first,\
    \ hi_ref(c));\n                i = c;\n            } else break;\n        }\n\
    \    }\n\npublic:\n    bipq() = default;\n    explicit bipq(Compare c) : cmp(c)\
    \ {}\n    template <class Iter>\n    bipq(Iter first, Iter last) { for (auto it\
    \ = first; it != last; ++it) push(*it); }\n    bipq(initializer_list<T> il) :\
    \ bipq(il.begin(), il.end()) {}\n\n    int  size()  const noexcept { return _sz;\
    \ }\n    bool empty() const noexcept { return _sz == 0; }\n\n    // Minimum element\
    \ (undefined if empty)\n    const T& top_min() const {\n        assert(_sz > 0);\n\
    \        return h[0].first;\n    }\n\n    // Maximum element (undefined if empty)\n\
    \    const T& top_max() const {\n        assert(_sz > 0);\n        return hi_val(0);\n\
    \    }\n\n    void push(const T& x) {\n        if (_sz % 2 == 0) {\n         \
    \   // Start a new (partial) leaf node\n            h.push_back({x, x});\n   \
    \         _sz++;\n            int i = (int)h.size() - 1;\n            sift_up_min(i);\n\
    \            sift_up_max(i);\n        } else {\n            // Complete the last\
    \ partial node\n            int i = (int)h.size() - 1;\n            if (cmp(x,\
    \ h[i].first)) {\n                h[i].second = h[i].first;\n                h[i].first\
    \  = x;\n            } else {\n                h[i].second = x;\n            }\n\
    \            _sz++;\n            sift_up_min(i);\n            sift_up_max(i);\n\
    \        }\n    }\n\n    void pop_min() {\n        assert(_sz > 0);\n        if\
    \ (_sz == 1) { h.pop_back(); _sz = 0; return; }\n        if (_sz == 2) { h[0].first\
    \ = h[0].second; _sz = 1; return; }\n\n        int last = (int)h.size() - 1;\n\
    \        T x;\n        if (_sz % 2 == 1) {\n            // Last node is partial:\
    \ take its only element and remove the node\n            x = h[last].first;\n\
    \            h.pop_back();\n        } else {\n            // Last node is full:\
    \ take hi, leaving it partial (handled by _sz--)\n            x = h[last].second;\n\
    \        }\n        _sz--;\n\n        h[0].first = x;\n        // Restore lo <=\
    \ hi at root if needed\n        if (cmp(h[0].second, h[0].first)) swap(h[0].first,\
    \ h[0].second);\n        sift_down_min(0);\n    }\n\n    void pop_max() {\n  \
    \      assert(_sz > 0);\n        if (_sz == 1) { h.pop_back(); _sz = 0; return;\
    \ }\n        if (_sz == 2) { _sz = 1; return; }  // only h[0].first remains\n\n\
    \        int last = (int)h.size() - 1;\n        T x;\n        if (_sz % 2 == 1)\
    \ {\n            x = h[last].first;\n            h.pop_back();\n        } else\
    \ {\n            x = h[last].second;\n        }\n        _sz--;\n\n        h[0].second\
    \ = x;\n        if (cmp(h[0].second, h[0].first)) swap(h[0].first, h[0].second);\n\
    \        sift_down_max(0);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/bipq.hpp
  requiredBy: []
  timestamp: '2026-03-10 11:48:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker_double_ended_priority_queue.test.cpp
documentation_of: structure/bipq.hpp
layout: document
redirect_from:
- /library/structure/bipq.hpp
- /library/structure/bipq.hpp.html
title: structure/bipq.hpp
---
