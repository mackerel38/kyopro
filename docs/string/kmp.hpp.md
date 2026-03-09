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
  bundledCode: "#line 2 \"string/kmp.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n// KMP failure function\nvector<int> kmp_failure(const string& pattern)\
    \ {\n    int m = pattern.size();\n    vector<int> fail(m, 0);\n    for (int i\
    \ = 1; i < m; i++) {\n        int j = fail[i-1];\n        while (j > 0 && pattern[i]\
    \ != pattern[j]) j = fail[j-1];\n        if (pattern[i] == pattern[j]) j++;\n\
    \        fail[i] = j;\n    }\n    return fail;\n}\n\n// KMP search: returns all\
    \ starting positions of pattern in text\nvector<int> kmp_search(const string&\
    \ text, const string& pattern) {\n    if (pattern.empty()) return {};\n    auto\
    \ fail = kmp_failure(pattern);\n    int n = text.size(), m = pattern.size();\n\
    \    vector<int> res;\n    int j = 0;\n    for (int i = 0; i < n; i++) {\n   \
    \     while (j > 0 && text[i] != pattern[j]) j = fail[j-1];\n        if (text[i]\
    \ == pattern[j]) j++;\n        if (j == m) {\n            res.push_back(i - m\
    \ + 1);\n            j = fail[j-1];\n        }\n    }\n    return res;\n}\n\n\
    // Period of string: minimum repeating unit length\n// e.g. \"ababab\" -> 2\n\
    int string_period(const string& s) {\n    auto fail = kmp_failure(s);\n    int\
    \ n = s.size();\n    int period = n - fail[n-1];\n    return (n % period == 0)\
    \ ? period : n;\n}\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n// KMP failure\
    \ function\nvector<int> kmp_failure(const string& pattern) {\n    int m = pattern.size();\n\
    \    vector<int> fail(m, 0);\n    for (int i = 1; i < m; i++) {\n        int j\
    \ = fail[i-1];\n        while (j > 0 && pattern[i] != pattern[j]) j = fail[j-1];\n\
    \        if (pattern[i] == pattern[j]) j++;\n        fail[i] = j;\n    }\n   \
    \ return fail;\n}\n\n// KMP search: returns all starting positions of pattern\
    \ in text\nvector<int> kmp_search(const string& text, const string& pattern) {\n\
    \    if (pattern.empty()) return {};\n    auto fail = kmp_failure(pattern);\n\
    \    int n = text.size(), m = pattern.size();\n    vector<int> res;\n    int j\
    \ = 0;\n    for (int i = 0; i < n; i++) {\n        while (j > 0 && text[i] !=\
    \ pattern[j]) j = fail[j-1];\n        if (text[i] == pattern[j]) j++;\n      \
    \  if (j == m) {\n            res.push_back(i - m + 1);\n            j = fail[j-1];\n\
    \        }\n    }\n    return res;\n}\n\n// Period of string: minimum repeating\
    \ unit length\n// e.g. \"ababab\" -> 2\nint string_period(const string& s) {\n\
    \    auto fail = kmp_failure(s);\n    int n = s.size();\n    int period = n -\
    \ fail[n-1];\n    return (n % period == 0) ? period : n;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: string/kmp.hpp
  requiredBy: []
  timestamp: '2026-03-09 22:49:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/kmp.hpp
layout: document
redirect_from:
- /library/string/kmp.hpp
- /library/string/kmp.hpp.html
title: string/kmp.hpp
---
