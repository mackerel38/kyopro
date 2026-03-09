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
  bundledCode: "#line 2 \"structure/majority_vote.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n// Boyer-Moore majority voting algorithm\n// After pushing\
    \ N elements, query() returns a majority candidate.\n// IMPORTANT: verify externally\
    \ that the candidate appears > N/2 times.\ntemplate <class T = int>\nstruct majority_vote\
    \ {\n    T cand{};\n    int cnt = 0;\n\n    void push(T x) {\n        if (cnt\
    \ == 0) { cand = x; cnt = 1; }\n        else if (cand == x) ++cnt;\n        else\
    \ --cnt;\n    }\n\n    T   query()         const { return cand; }\n    bool has_candidate()\
    \ const { return cnt > 0; }\n    void clear() { cand = T{}; cnt = 0; }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n// Boyer-Moore\
    \ majority voting algorithm\n// After pushing N elements, query() returns a majority\
    \ candidate.\n// IMPORTANT: verify externally that the candidate appears > N/2\
    \ times.\ntemplate <class T = int>\nstruct majority_vote {\n    T cand{};\n  \
    \  int cnt = 0;\n\n    void push(T x) {\n        if (cnt == 0) { cand = x; cnt\
    \ = 1; }\n        else if (cand == x) ++cnt;\n        else --cnt;\n    }\n\n \
    \   T   query()         const { return cand; }\n    bool has_candidate() const\
    \ { return cnt > 0; }\n    void clear() { cand = T{}; cnt = 0; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/majority_vote.hpp
  requiredBy: []
  timestamp: '2026-03-09 22:49:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/majority_vote.hpp
layout: document
redirect_from:
- /library/structure/majority_vote.hpp
- /library/structure/majority_vote.hpp.html
title: structure/majority_vote.hpp
---
