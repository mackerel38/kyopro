---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: utility/mo.hpp
    title: utility/mo.hpp
  - icon: ':heavy_check_mark:'
    path: utility/template.hpp
    title: utility/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_inversions_query
    links:
    - https://judge.yosupo.jp/problem/static_range_inversions_query
  bundledCode: "#line 1 \"verify/library_checker_static_range_inversions_query.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_inversions_query\"\
    \n#line 2 \"utility/template.hpp\"\n#ifdef poe\n#define debug(x) cerr << #x <<\
    \ \": \" << x << '\\n'\n#else\n#define debug(x)\n#endif\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nusing uint = unsigned int;\nusing ll = long long;\nusing\
    \ ull = unsigned long long;\nusing i128 = __int128;\nusing u128 = unsigned __int128;\n\
    using ld = long double;\nusing str = string;\nusing vi = vector<int>;\nusing vvi\
    \ = vector<vector<int>>;\nusing vvvi = vector<vector<vector<int>>>;\nusing pi\
    \ = pair<int, int>;\nusing ppi = pair<int, pair<int, int>>;\nusing pppi = pair<int,\
    \ pair<int, pair<int, int>>>;\nusing vpi = vector<pair<int, int>>;\nusing vvpi\
    \ = vector<vector<pair<int, int>>>;\nusing vvvpi = vector<vector<vector<pair<int,\
    \ int>>>>;\nusing vll = vector<long long>;\nusing vvll = vector<vector<long long>>;\n\
    using vvvll = vector<vector<vector<long long>>>;\nusing pll = pair<long long,\
    \ long long>;\nusing ppll = pair<long long, pair<long long, long long>>;\nusing\
    \ pppll = pair<long long, pair<long long, pair<long long, long long>>>;\nusing\
    \ vpll = vector<pair<long long, long long>>;\nusing vvpll = vector<vector<pair<long\
    \ long, long long>>>;\nusing vvvpll = vector<vector<vector<pair<long long, long\
    \ long>>>>;\ntemplate <class T> using pairs = pair<T, T>;\ntemplate <class T>\
    \ using vec = vector<T>;\ntemplate <class T> using vvec = vec<vec<T>>;\ntemplate\
    \ <class T> using vvvec = vec<vec<vec<T>>>;\ntemplate <class T> using pq = priority_queue<T>;\n\
    template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;\n\n#define\
    \ vv(type, name, x, y, ...) vector<vector<type>> name((x), vector<type>((y), ##__VA_ARGS__))\n\
    #define vvv(type, name, x, y, z, ...) vector<vector<vector<type>>> name((x), vector<vector<type>>((y),\
    \ vector<type>((z), ##__VA_ARGS__)))\n\n#define rep_1(n) for (long long _=0LL;\
    \ _<(long long)(n); ++_)\n#define rep_2(i, n) for (long long i=0LL; i<(long long)(n);\
    \ ++i)\n#define rep_3(i, l, r) for (long long i=(long long)(l); i<(long long)(r);\
    \ ++i)\n#define rep_4(i, l, r, s) for (long long i=(long long)(l); i<(long long)(r);\
    \ i+=(long long)(s))\n#define overload_rep(a, b, c, d, e, ...) e\n#define rep(...)\
    \ overload_rep(__VA_ARGS__, rep_4, rep_3, rep_2, rep_1)(__VA_ARGS__)\n\n#define\
    \ rep1_1(n) for (long long _=1LL; _<=(long long)(n); ++_)\n#define rep1_2(i, n)\
    \ for (long long i=1LL; i<=(long long)(n); ++i)\n#define rep1_3(i, l, r) for (long\
    \ long i=(long long)(l)+1LL; i<=(long long)(r); ++i)\n#define rep1_4(i, l, r,\
    \ s) for (long long i=(long long)(l)+1LL; i<=(long long)(r); i+=(long long)(s))\n\
    #define overload_rep1(a, b, c, d, e, ...) e\n#define rep1(...) overload_rep1(__VA_ARGS__,\
    \ rep1_4, rep1_3, rep1_2, rep1_1)(__VA_ARGS__)\n\n#define per_1(n) for (long long\
    \ _=(long long)(n)-1LL; 0LL<=_; --_)\n#define per_2(i, n) for (long long i=(long\
    \ long)(n)-1LL; 0LL<=i; --i)\n#define per_3(i, l, r) for (long long i=(long long)(r)-1LL;\
    \ (long long)(l)<=i; --i)\n#define per_4(i, l, r, s) for (long long i=(long long)(r)-1LL;\
    \ (long long)(l)<=i; i-=(long long)(s))\n#define overload_per(a, b, c, d, e, ...)\
    \ e\n#define per(...) overload_per(__VA_ARGS__, per_4, per_3, per_2, per_1)(__VA_ARGS__)\n\
    \n#define per1_1(n) for (long long _=(long long)(n); 0LL<_; --_)\n#define per1_2(i,\
    \ n) for (long long i=(long long)(n); 0LL<i; --i)\n#define per1_3(i, l, r) for\
    \ (long long i=(long long)(r); (long long)(l)<i; --i)\n#define per1_4(i, l, r,\
    \ s) for (long long i=(long long)(r); (long long)(l)<i; i-=(long long)(s))\n#define\
    \ overload_per1(a, b, c, d, e, ...) e\n#define per1(...) overload_per1(__VA_ARGS__,\
    \ per1_4, per1_3, per1_2, per1_1)(__VA_ARGS__)\n\n#define range_1(v) for (auto&\
    \ _ : (v))\n#define range_2(i, v) for (auto& i : (v))\n#define range_3(i, j, v)\
    \ for (auto& [i, j] : (v))\n#define overload_range(a, b, c, d, ...) d\n#define\
    \ range(...) overload_range(__VA_ARGS__, range_3, range_2, range_1)(__VA_ARGS__)\n\
    \n#define all(x) (x).begin(), (x).end()\n#define rall(x) (x).rbegin(), (x).rend()\n\
    #define len(x) ssize(x)\n#define elif else if\n#define pb emplace_back\n#define\
    \ db pop_back\n#define pf emplace_front\n#define df pop_front\n#define fi first\n\
    #define se second\n\n#define Sort(v) sort((v).begin(), (v).end())\n#define troS(v)\
    \ sort((v).rbegin(), (v).rend())\n#define Reverse(v) reverse((v).begin(), (v).end())\n\
    #define uniq(v) sort((v).begin(), (v).end()), (v).erase(unique((v).begin(), (v).end()),\
    \ (v).end()), (v).shrink_to_fit()\n#define bit(x, i) (((x)>>i)&1)\n\n#define nextp(v)\
    \ next_permutation((v).begin(), (v).end())\ntemplate <class T>\nbool next_combination(T\
    \ l, T r, int k) {\n    T m = l + k;\n    if (l==r || r==m || m==l) return false;\n\
    \    T t = m;\n    while (l != t) {\n        t--;\n        if (*t < *(r-1)) {\n\
    \            T d = m;\n            while (*d <=*t) d++;\n            iter_swap(t,\
    \ d);\n            rotate(t+1, d+1, r);\n            rotate(m, m+(r-d)-1, r);\n\
    \            return true;\n        }\n    }\n    rotate(l, m, r);\n    return\
    \ false;\n}\n#define nextc(v, k) next_combination((v).begin(), (v).end(), k)\n\
    \n#define Yes cout << \"Yes\\n\"\n#define No cout << \"No\\n\"\n#define YN(x)\
    \ cout << ((x) ? \"Yes\\n\" : \"No\\n\")\n#define O(x) cout << (x) << '\\n'\n\n\
    #define ismid_1(x) true\ntemplate <class T, class U>\nbool inner_ismid_2(T x,\
    \ U r) { return T{}<=x && x<r; }\n#define ismid_2(x, r) inner_ismid_2(x, r)\n\
    template <class T, class U, class V>\nbool inner_ismid_3(T l, U x, V r) { return\
    \ l<=x && x<r; }\n#define ismid_3(l, x, r) inner_ismid_3(l, x, r)\n#define overload_ismid(a,\
    \ b, x, d, ...) d\n#define ismid(...) overload_ismid(__VA_ARGS__, ismid_3, ismid_2,\
    \ ismid_1)(__VA_ARGS__)\n\ninline int popcnt(int x) { return __builtin_popcount((unsigned\
    \ int)x); }\ninline int popcnt(unsigned int x) { return __builtin_popcount(x);\
    \ }\ninline int popcnt(long long x) { return __builtin_popcountll(x); }\ninline\
    \ int popcnt(unsigned long long x) { return __builtin_popcountll(x); }\ninline\
    \ int topbit(int x) { return x==0 ? -1 : 31-__builtin_clz(x); }\ninline int topbit(unsigned\
    \ int x) { return x==0 ? -1 : 31-__builtin_clz(x); }\ninline int topbit(long long\
    \ x) { return x==0 ? -1 : 63-__builtin_clzll(x); }\ninline int topbit(unsigned\
    \ long long x) { return x==0 ? -1 : 63-__builtin_clzll(x); }\n\ntemplate<class\
    \ T>\nbool next_subset(T x, T& s) {\n    if (s == T{}) return false;\n    s =\
    \ (s-1) & x;\n    return true;\n}\n\ntemplate <class T>\nconstexpr vector<T> enum_pow(T\
    \ x, int n) {\n    vector<T> re(n+1);\n    re[0] = T{1};\n    for (int i=1; i<=n;\
    \ ++i) re[i] = re[i-1] * x;\n    return re;\n}\n\ntemplate <class T, class U>\n\
    inline T Pow(T x, U n) {\n    T re = T{1};\n    if (n < U{}) {\n        x = T{1}\
    \ / x;\n        n = -n;\n    }\n    while (U{} < n) {\n        if ((n & U{1})\
    \ == 1) re *= x;\n        x *= x;\n        n >>= 1;\n    }\n    return re;\n}\n\
    \ntemplate <class T, class U>\ninline bool chmin(T& x, U y) {\n    if (x <= y)\
    \ return false;\n    x = y;\n    return true;\n}\ntemplate <class T, class U>\n\
    inline bool chmax(T& x, U y) {\n    if (y <= x) return false;\n    x = y;\n  \
    \  return true;\n}\n\ntemplate <class T>\nT Min(T x, T y) { return min(x, y);\
    \ }\ntemplate<class T, class ...Args>\nT Min(T x, T y, Args... args) { return\
    \ Min(Min(x, y), args...); }\ntemplate <class T>\nT Max(T x, T y) { return max(x,\
    \ y); }\ntemplate<class T, class ...Args>\nT Max(T x, T y, Args... args) { return\
    \ Max(Max(x, y), args...); }\n\ntemplate<typename T> struct is_string : false_type\
    \ {};\ntemplate<typename Char, typename Traits, typename Alloc>\nstruct is_string<basic_string<Char,Traits,Alloc>>\
    \ : true_type {};\ntemplate<typename T, typename = void>\nstruct is_iterable :\
    \ false_type {};\ntemplate<typename T>\nstruct is_iterable<T, void_t<decltype(begin(declval<T>())),\
    \ decltype(end(declval<T>()))>> : conditional_t<is_string<T>::value, false_type,\
    \ true_type> {};\ntemplate<typename T>\nauto Min(const T& x) -> enable_if_t<!is_iterable<T>::value,\
    \ T> { return x; }\ntemplate<typename C>\nauto Min(const C& v) -> enable_if_t<is_iterable<C>::value,\
    \ decay_t<decltype(Min(*v.begin()))>> {\n    using R = decay_t<decltype(Min(*v.begin()))>;\n\
    \    auto it = v.begin();\n    R re = Min(*it);\n    for (++it; it!=v.end(); ++it)\
    \ {\n        R v = Min(*it);\n        if (v < re) re = v;\n    }\n    return re;\n\
    }\ntemplate<typename T>\nauto Max(const T& x) -> enable_if_t<!is_iterable<T>::value,\
    \ T> { return x; }\ntemplate<typename C>\nauto Max(const C& v) -> enable_if_t<is_iterable<C>::value,\
    \ decay_t<decltype(Max(*v.begin()))>> {\n    using R = decay_t<decltype(Max(*v.begin()))>;\n\
    \    auto it = v.begin();\n    R re = Max(*it);\n    for (++it; it != v.end();\
    \ ++it) {\n        R v = Max(*it);\n        if (re < v) re = v;\n    }\n    return\
    \ re;\n}\ntemplate<typename T>\nauto Sum(const T& x) -> enable_if_t<!is_iterable<T>::value,\
    \ T> { return x; }\ntemplate<typename C>\nauto Sum(const C& v) -> enable_if_t<is_iterable<C>::value,\
    \ decay_t<decltype(Sum(*v.begin()))>> {\n    using R = decay_t<decltype(Sum(*v.begin()))>;\n\
    \    R re = R{};\n    for (auto it=v.begin(); it!=v.end(); ++it) re += Sum(*it);\n\
    \    return re;\n}\ntemplate<class A, class B>\nauto Min(const pair<A,B>& p) {\n\
    \    using R1 = decay_t<decltype(Min(p.first))>;\n    using R2 = decay_t<decltype(Min(p.second))>;\n\
    \    using R  = decay_t<common_type_t<R1, R2>>;\n    R a = Min(p.first);\n   \
    \ R b = Min(p.second);\n    return (b < a) ? b : a;\n}\ntemplate<class A, class\
    \ B>\nauto Max(const pair<A,B>& p) {\n    using R1 = decay_t<decltype(Max(p.first))>;\n\
    \    using R2 = decay_t<decltype(Max(p.second))>;\n    using R  = decay_t<common_type_t<R1,\
    \ R2>>;\n    R a = Max(p.first);\n    R b = Max(p.second);\n    return (a < b)\
    \ ? b : a;\n}\ntemplate<class A, class B>\nauto Sum(const pair<A,B>& p) {\n  \
    \  using R1 = decay_t<decltype(Sum(p.first))>;\n    using R2 = decay_t<decltype(Sum(p.second))>;\n\
    \    using R  = decay_t<common_type_t<R1, R2>>;\n    R res{};\n    res += Sum(p.first);\n\
    \    res += Sum(p.second);\n    return res;\n}\n\ntemplate<class T, class U>\n\
    istream& operator>>(istream& s, pair<T, U>& p) {\n    s >> p.first >> p.second;\n\
    \    return s;\n}\ntemplate<class T, class U>\nostream& operator<<(ostream& s,\
    \ pair<T, U>& p) {\n    s <<  p.first <<' ' << p.second << '\\n';\n    return\
    \ s;\n}\ntemplate<class T>\nistream& operator>>(istream& s, vector<T>& v) {\n\
    \    for (auto& i : v) s >> i;\n    return s;\n}\ntemplate<class T>\nostream&\
    \ operator<<(ostream& s, vector<T>& v) {\n    for (int i=0; i<ssize(v); i++) s\
    \ << v[i] << (i==ssize(v)-1 ? '\\n' : ' ');\n    return s;\n}\n\nconst vector<int>\
    \ dxy = {0, 1, 0, -1, 0};\nconst vector<int> dx = {0, 1, 0, -1, 1, 1, -1, -1};\n\
    const vector<int> dy = {1, 0, -1, 0, 1, -1, 1, -1};\nconstexpr char nl = '\\n';\n\
    constexpr char sp = ' ';\nconstexpr long long inf = numeric_limits<long long>::max()/2;\n\
    constexpr int INF = numeric_limits<int>::max()/2;\ntemplate <class T>\nconstexpr\
    \ T infty = numeric_limits<T>::is_integer ? (numeric_limits<T>::max()/2) : numeric_limits<T>::infinity();\n\
    constexpr long double eps = 1e-9;\nconst long double PI = acos(-1);\nconstexpr\
    \ long long mod = 998244353;\nconstexpr long long MOD = 1000000007;\n\ninline\
    \ void IO() {\n    ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    }\n\nvoid solve();\n\n#line 3 \"utility/mo.hpp\"\nusing namespace std;\n\n// Mo's\
    \ algorithm  O((N + Q) sqrt(N)) offline range queries\n//\n// Usage:\n//   mo\
    \ m(n);\n//   m.add(l, r);   // register query [l, r)  (half-open)\n//   m.run(add_l,\
    \ del_l, add_r, del_r, query_fn);\n//\n// Callbacks:\n//   add_l(i)  : extend\
    \  left  boundary to include index i\n//   del_l(i)  : shrink  left  boundary\
    \ to exclude index i\n//   add_r(i)  : extend  right boundary (called with index\
    \ = new r-1)\n//   del_r(i)  : shrink  right boundary (called with index = old\
    \ r-1)\n//   query(qi) : answer query qi  (qi is the order of m.add calls)\n//\n\
    // Current window is always [curL, curR) during execution.\nstruct mo {\n    int\
    \ n;\n    vector<pair<int,int>> qs;\n\n    mo() = default;\n    mo(int n) : n(n)\
    \ {}\n\n    void add(int l, int r) { qs.push_back({l, r}); }\n\n    template <class\
    \ AL, class DL, class AR, class DR, class Q>\n    void run(AL add_l, DL del_l,\
    \ AR add_r, DR del_r, Q query) {\n        int q = qs.size();\n        if (q ==\
    \ 0) return;\n        int block = max(1, (int)sqrt(n));\n        vector<int> ord(q);\n\
    \        iota(ord.begin(), ord.end(), 0);\n        sort(ord.begin(), ord.end(),\
    \ [&](int a, int b) {\n            int ba = qs[a].first / block, bb = qs[b].first\
    \ / block;\n            if (ba != bb) return ba < bb;\n            return (ba\
    \ & 1) ? qs[a].second > qs[b].second\n                            : qs[a].second\
    \ < qs[b].second;\n        });\n        int l = 0, r = 0;\n        for (int i\
    \ : ord) {\n            int ql = qs[i].first, qr = qs[i].second;\n           \
    \ while (r < qr) add_r(r++);\n            while (l > ql) add_l(--l);\n       \
    \     while (r > qr) del_r(--r);\n            while (l < ql) del_l(l++);\n   \
    \         query(i);\n        }\n    }\n};\n#line 4 \"verify/library_checker_static_range_inversions_query.test.cpp\"\
    \n\nint main(){\n    IO();\n    int T = 1;\n    while (T--) solve();\n}\n\nvoid\
    \ solve(){\n    int n, q; cin >> n >> q;\n    vector<int> a(n);\n    rep(i, n)\
    \ cin >> a[i];\n\n    // Coordinate compress\n    vector<int> b = a;\n    sort(b.begin(),\
    \ b.end()); b.erase(unique(b.begin(), b.end()), b.end());\n    int m = (int)b.size();\n\
    \    rep(i, n) a[i] = (int)(lower_bound(b.begin(), b.end(), a[i]) - b.begin());\n\
    \n    // Fenwick tree (rename to fw to avoid conflict with 'bit' macro)\n    vector<ll>\
    \ fw(m + 2, 0);\n    auto fw_add = [&](int i, ll v){ for (i += 1; i <= m; i +=\
    \ i & -i) fw[i] += v; };\n    auto fw_sum = [&](int i) -> ll { ll s = 0; for (;\
    \ i > 0; i -= i & -i) s += fw[i]; return s; };\n\n    mo mo_q(n);\n    rep(i,\
    \ q){ int l, r; cin >> l >> r; mo_q.add(l, r); }\n\n    vector<ll> ans(q);\n \
    \   ll cur = 0;\n    int wsize = 0;\n\n    auto add_r = [&](int i){\n        cur\
    \ += wsize - fw_sum(a[i] + 1);\n        fw_add(a[i], 1); wsize++;\n    };\n  \
    \  auto del_r = [&](int i){\n        cur -= wsize - fw_sum(a[i] + 1);\n      \
    \  fw_add(a[i], -1); wsize--;\n    };\n    auto add_l = [&](int i){\n        cur\
    \ += fw_sum(a[i]);\n        fw_add(a[i], 1); wsize++;\n    };\n    auto del_l\
    \ = [&](int i){\n        fw_add(a[i], -1); wsize--;\n        cur -= fw_sum(a[i]);\n\
    \    };\n\n    mo_q.run(add_l, del_l, add_r, del_r, [&](int qi){ ans[qi] = cur;\
    \ });\n    rep(i, q) cout << ans[i] << nl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_inversions_query\"\
    \n#include \"template\"\n#include \"mo\"\n\nint main(){\n    IO();\n    int T\
    \ = 1;\n    while (T--) solve();\n}\n\nvoid solve(){\n    int n, q; cin >> n >>\
    \ q;\n    vector<int> a(n);\n    rep(i, n) cin >> a[i];\n\n    // Coordinate compress\n\
    \    vector<int> b = a;\n    sort(b.begin(), b.end()); b.erase(unique(b.begin(),\
    \ b.end()), b.end());\n    int m = (int)b.size();\n    rep(i, n) a[i] = (int)(lower_bound(b.begin(),\
    \ b.end(), a[i]) - b.begin());\n\n    // Fenwick tree (rename to fw to avoid conflict\
    \ with 'bit' macro)\n    vector<ll> fw(m + 2, 0);\n    auto fw_add = [&](int i,\
    \ ll v){ for (i += 1; i <= m; i += i & -i) fw[i] += v; };\n    auto fw_sum = [&](int\
    \ i) -> ll { ll s = 0; for (; i > 0; i -= i & -i) s += fw[i]; return s; };\n\n\
    \    mo mo_q(n);\n    rep(i, q){ int l, r; cin >> l >> r; mo_q.add(l, r); }\n\n\
    \    vector<ll> ans(q);\n    ll cur = 0;\n    int wsize = 0;\n\n    auto add_r\
    \ = [&](int i){\n        cur += wsize - fw_sum(a[i] + 1);\n        fw_add(a[i],\
    \ 1); wsize++;\n    };\n    auto del_r = [&](int i){\n        cur -= wsize - fw_sum(a[i]\
    \ + 1);\n        fw_add(a[i], -1); wsize--;\n    };\n    auto add_l = [&](int\
    \ i){\n        cur += fw_sum(a[i]);\n        fw_add(a[i], 1); wsize++;\n    };\n\
    \    auto del_l = [&](int i){\n        fw_add(a[i], -1); wsize--;\n        cur\
    \ -= fw_sum(a[i]);\n    };\n\n    mo_q.run(add_l, del_l, add_r, del_r, [&](int\
    \ qi){ ans[qi] = cur; });\n    rep(i, q) cout << ans[i] << nl;\n}\n"
  dependsOn:
  - utility/template.hpp
  - utility/mo.hpp
  isVerificationFile: true
  path: verify/library_checker_static_range_inversions_query.test.cpp
  requiredBy: []
  timestamp: '2026-03-10 02:22:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker_static_range_inversions_query.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker_static_range_inversions_query.test.cpp
- /verify/verify/library_checker_static_range_inversions_query.test.cpp.html
title: verify/library_checker_static_range_inversions_query.test.cpp
---
