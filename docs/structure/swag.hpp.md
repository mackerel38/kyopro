---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker_queue_operate_all_composite.test.cpp
    title: verify/library_checker_queue_operate_all_composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"structure/swag.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n// Sliding Window Aggregation (SWAG)\n// push_back / pop_front / fold\
    \  all amortized O(1)\n// (S, op, e) must form a monoid (NOT required to be commutative)\n\
    template <class S, auto op, auto e>\nstruct swag {\n    struct node { S val, acc;\
    \ };\n    // front_st.back().acc = op(front elements in queue order)\n    // back_st.back().acc\
    \  = op(back elements in enqueue order)\n    vector<node> front_st, back_st;\n\
    \n    swag() = default;\n\n    bool empty() const { return front_st.empty() &&\
    \ back_st.empty(); }\n    int  size()  const { return (int)front_st.size() + (int)back_st.size();\
    \ }\n\n    void push_back(S x) {\n        S a = back_st.empty() ? x : op(back_st.back().acc,\
    \ x);\n        back_st.push_back({x, a});\n    }\n\n    void pop_front() {\n \
    \       assert(!empty());\n        if (front_st.empty()) {\n            // move\
    \ back -> front (reverse order)\n            while (!back_st.empty()) {\n    \
    \            S x = back_st.back().val;\n                back_st.pop_back();\n\
    \                S a = front_st.empty() ? x : op(x, front_st.back().acc);\n  \
    \              front_st.push_back({x, a});\n            }\n        }\n       \
    \ front_st.pop_back();\n    }\n\n    // product of all elements in dequeue order\
    \ (front ... back)\n    S fold() const {\n        if (front_st.empty() && back_st.empty())\
    \ return e();\n        if (front_st.empty()) return back_st.back().acc;\n    \
    \    if (back_st.empty())  return front_st.back().acc;\n        return op(front_st.back().acc,\
    \ back_st.back().acc);\n    }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n// Sliding\
    \ Window Aggregation (SWAG)\n// push_back / pop_front / fold  all amortized O(1)\n\
    // (S, op, e) must form a monoid (NOT required to be commutative)\ntemplate <class\
    \ S, auto op, auto e>\nstruct swag {\n    struct node { S val, acc; };\n    //\
    \ front_st.back().acc = op(front elements in queue order)\n    // back_st.back().acc\
    \  = op(back elements in enqueue order)\n    vector<node> front_st, back_st;\n\
    \n    swag() = default;\n\n    bool empty() const { return front_st.empty() &&\
    \ back_st.empty(); }\n    int  size()  const { return (int)front_st.size() + (int)back_st.size();\
    \ }\n\n    void push_back(S x) {\n        S a = back_st.empty() ? x : op(back_st.back().acc,\
    \ x);\n        back_st.push_back({x, a});\n    }\n\n    void pop_front() {\n \
    \       assert(!empty());\n        if (front_st.empty()) {\n            // move\
    \ back -> front (reverse order)\n            while (!back_st.empty()) {\n    \
    \            S x = back_st.back().val;\n                back_st.pop_back();\n\
    \                S a = front_st.empty() ? x : op(x, front_st.back().acc);\n  \
    \              front_st.push_back({x, a});\n            }\n        }\n       \
    \ front_st.pop_back();\n    }\n\n    // product of all elements in dequeue order\
    \ (front ... back)\n    S fold() const {\n        if (front_st.empty() && back_st.empty())\
    \ return e();\n        if (front_st.empty()) return back_st.back().acc;\n    \
    \    if (back_st.empty())  return front_st.back().acc;\n        return op(front_st.back().acc,\
    \ back_st.back().acc);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/swag.hpp
  requiredBy: []
  timestamp: '2026-03-09 22:49:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker_queue_operate_all_composite.test.cpp
documentation_of: structure/swag.hpp
layout: document
redirect_from:
- /library/structure/swag.hpp
- /library/structure/swag.hpp.html
title: structure/swag.hpp
---
