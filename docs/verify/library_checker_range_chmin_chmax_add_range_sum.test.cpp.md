---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/home/mackerel38/.local/share/pipx/venvs/online-judge-verify-helper/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/home/mackerel38/.local/share/pipx/venvs/online-judge-verify-helper/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/home/mackerel38/.local/share/pipx/venvs/online-judge-verify-helper/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/home/mackerel38/.local/share/pipx/venvs/online-judge-verify-helper/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: segtree_beats:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum\"\
    \n#include \"template\"\n#include \"segtree_beats\"\n\nint main(){\n    IO();\n\
    \    int T = 1;\n    while (T--) solve();\n}\n\nvoid solve(){\n    int n, q; cin\
    \ >> n >> q;\n    vector<ll> a(n);\n    rep(i, n) cin >> a[i];\n    segtree_beats\
    \ sb(a);\n    rep(q){\n        int t; cin >> t;\n        if (t == 0){\n      \
    \      int l, r; ll b; cin >> l >> r >> b;\n            sb.range_chmin(l, r, b);\n\
    \        } else if (t == 1){\n            int l, r; ll b; cin >> l >> r >> b;\n\
    \            sb.range_chmax(l, r, b);\n        } else if (t == 2){\n         \
    \   int l, r; ll b; cin >> l >> r >> b;\n            sb.range_add(l, r, b);\n\
    \        } else {\n            int l, r; cin >> l >> r;\n            cout << sb.query_sum(l,\
    \ r) << nl;\n        }\n    }\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: verify/library_checker_range_chmin_chmax_add_range_sum.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/library_checker_range_chmin_chmax_add_range_sum.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker_range_chmin_chmax_add_range_sum.test.cpp
- /verify/verify/library_checker_range_chmin_chmax_add_range_sum.test.cpp.html
title: verify/library_checker_range_chmin_chmax_add_range_sum.test.cpp
---
