---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker_zalgorithm.test.cpp
    title: verify/library_checker_zalgorithm.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/z_algorithm.hpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\n// Z-algorithm: z[i] = length of the longest substring starting\
    \ at i\n//              that matches a prefix of s. z[0] = n by convention.\n\
    vector<int> z_algorithm(const string& s) {\n    int n = s.size();\n    vector<int>\
    \ z(n, 0);\n    z[0] = n;\n    int l = 0, r = 0;\n    for (int i = 1; i < n; i++)\
    \ {\n        if (i < r) z[i] = min(r - i, z[i - l]);\n        while (i + z[i]\
    \ < n && s[z[i]] == s[i + z[i]]) z[i]++;\n        if (i + z[i] > r) { l = i; r\
    \ = i + z[i]; }\n    }\n    return z;\n}\n\n// Find all occurrences of pattern\
    \ in text using Z-algorithm\nvector<int> z_search(const string& text, const string&\
    \ pattern) {\n    string s = pattern + \"$\" + text;\n    auto z = z_algorithm(s);\n\
    \    int m = pattern.size();\n    vector<int> res;\n    for (int i = m+1; i <\
    \ (int)s.size(); i++)\n        if (z[i] >= m) res.push_back(i - m - 1);\n    return\
    \ res;\n}\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n// Z-algorithm:\
    \ z[i] = length of the longest substring starting at i\n//              that matches\
    \ a prefix of s. z[0] = n by convention.\nvector<int> z_algorithm(const string&\
    \ s) {\n    int n = s.size();\n    vector<int> z(n, 0);\n    z[0] = n;\n    int\
    \ l = 0, r = 0;\n    for (int i = 1; i < n; i++) {\n        if (i < r) z[i] =\
    \ min(r - i, z[i - l]);\n        while (i + z[i] < n && s[z[i]] == s[i + z[i]])\
    \ z[i]++;\n        if (i + z[i] > r) { l = i; r = i + z[i]; }\n    }\n    return\
    \ z;\n}\n\n// Find all occurrences of pattern in text using Z-algorithm\nvector<int>\
    \ z_search(const string& text, const string& pattern) {\n    string s = pattern\
    \ + \"$\" + text;\n    auto z = z_algorithm(s);\n    int m = pattern.size();\n\
    \    vector<int> res;\n    for (int i = m+1; i < (int)s.size(); i++)\n       \
    \ if (z[i] >= m) res.push_back(i - m - 1);\n    return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: string/z_algorithm.hpp
  requiredBy: []
  timestamp: '2026-03-09 22:49:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker_zalgorithm.test.cpp
documentation_of: string/z_algorithm.hpp
layout: document
redirect_from:
- /library/string/z_algorithm.hpp
- /library/string/z_algorithm.hpp.html
title: string/z_algorithm.hpp
---
