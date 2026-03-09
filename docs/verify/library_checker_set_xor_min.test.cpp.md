---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: structure/binary_trie.hpp
    title: structure/binary_trie.hpp
  - icon: ':question:'
    path: utility/template.hpp
    title: utility/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/set_xor_min
    links:
    - https://judge.yosupo.jp/problem/set_xor_min
  bundledCode: "#line 1 \"verify/library_checker_set_xor_min.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/set_xor_min\"\n#line 2 \"utility/template.hpp\"\
    \n#ifdef poe\n#define debug(x) cerr << #x << \": \" << x << '\\n'\n#else\n#define\
    \ debug(x)\n#endif\n\n#include <bits/stdc++.h>\nusing namespace std;\n\nusing\
    \ uint = unsigned int;\nusing ll = long long;\nusing ull = unsigned long long;\n\
    using i128 = __int128;\nusing u128 = unsigned __int128;\nusing ld = long double;\n\
    using str = string;\nusing vi = vector<int>;\nusing vvi = vector<vector<int>>;\n\
    using vvvi = vector<vector<vector<int>>>;\nusing pi = pair<int, int>;\nusing ppi\
    \ = pair<int, pair<int, int>>;\nusing pppi = pair<int, pair<int, pair<int, int>>>;\n\
    using vpi = vector<pair<int, int>>;\nusing vvpi = vector<vector<pair<int, int>>>;\n\
    using vvvpi = vector<vector<vector<pair<int, int>>>>;\nusing vll = vector<long\
    \ long>;\nusing vvll = vector<vector<long long>>;\nusing vvvll = vector<vector<vector<long\
    \ long>>>;\nusing pll = pair<long long, long long>;\nusing ppll = pair<long long,\
    \ pair<long long, long long>>;\nusing pppll = pair<long long, pair<long long,\
    \ pair<long long, long long>>>;\nusing vpll = vector<pair<long long, long long>>;\n\
    using vvpll = vector<vector<pair<long long, long long>>>;\nusing vvvpll = vector<vector<vector<pair<long\
    \ long, long long>>>>;\ntemplate <class T> using pairs = pair<T, T>;\ntemplate\
    \ <class T> using vec = vector<T>;\ntemplate <class T> using vvec = vec<vec<T>>;\n\
    template <class T> using vvvec = vec<vec<vec<T>>>;\ntemplate <class T> using pq\
    \ = priority_queue<T>;\ntemplate <class T> using pqg = priority_queue<T, vector<T>,\
    \ greater<T>>;\n\n#define vv(type, name, x, y, ...) vector<vector<type>> name((x),\
    \ vector<type>((y), ##__VA_ARGS__))\n#define vvv(type, name, x, y, z, ...) vector<vector<vector<type>>>\
    \ name((x), vector<vector<type>>((y), vector<type>((z), ##__VA_ARGS__)))\n\n#define\
    \ rep_1(n) for (long long _=0LL; _<(long long)(n); ++_)\n#define rep_2(i, n) for\
    \ (long long i=0LL; i<(long long)(n); ++i)\n#define rep_3(i, l, r) for (long long\
    \ i=(long long)(l); i<(long long)(r); ++i)\n#define rep_4(i, l, r, s) for (long\
    \ long i=(long long)(l); i<(long long)(r); i+=(long long)(s))\n#define overload_rep(a,\
    \ b, c, d, e, ...) e\n#define rep(...) overload_rep(__VA_ARGS__, rep_4, rep_3,\
    \ rep_2, rep_1)(__VA_ARGS__)\n\n#define rep1_1(n) for (long long _=1LL; _<=(long\
    \ long)(n); ++_)\n#define rep1_2(i, n) for (long long i=1LL; i<=(long long)(n);\
    \ ++i)\n#define rep1_3(i, l, r) for (long long i=(long long)(l)+1LL; i<=(long\
    \ long)(r); ++i)\n#define rep1_4(i, l, r, s) for (long long i=(long long)(l)+1LL;\
    \ i<=(long long)(r); i+=(long long)(s))\n#define overload_rep1(a, b, c, d, e,\
    \ ...) e\n#define rep1(...) overload_rep1(__VA_ARGS__, rep1_4, rep1_3, rep1_2,\
    \ rep1_1)(__VA_ARGS__)\n\n#define per_1(n) for (long long _=(long long)(n)-1LL;\
    \ 0LL<=_; --_)\n#define per_2(i, n) for (long long i=(long long)(n)-1LL; 0LL<=i;\
    \ --i)\n#define per_3(i, l, r) for (long long i=(long long)(r)-1LL; (long long)(l)<=i;\
    \ --i)\n#define per_4(i, l, r, s) for (long long i=(long long)(r)-1LL; (long long)(l)<=i;\
    \ i-=(long long)(s))\n#define overload_per(a, b, c, d, e, ...) e\n#define per(...)\
    \ overload_per(__VA_ARGS__, per_4, per_3, per_2, per_1)(__VA_ARGS__)\n\n#define\
    \ per1_1(n) for (long long _=(long long)(n); 0LL<_; --_)\n#define per1_2(i, n)\
    \ for (long long i=(long long)(n); 0LL<i; --i)\n#define per1_3(i, l, r) for (long\
    \ long i=(long long)(r); (long long)(l)<i; --i)\n#define per1_4(i, l, r, s) for\
    \ (long long i=(long long)(r); (long long)(l)<i; i-=(long long)(s))\n#define overload_per1(a,\
    \ b, c, d, e, ...) e\n#define per1(...) overload_per1(__VA_ARGS__, per1_4, per1_3,\
    \ per1_2, per1_1)(__VA_ARGS__)\n\n#define range_1(v) for (auto& _ : (v))\n#define\
    \ range_2(i, v) for (auto& i : (v))\n#define range_3(i, j, v) for (auto& [i, j]\
    \ : (v))\n#define overload_range(a, b, c, d, ...) d\n#define range(...) overload_range(__VA_ARGS__,\
    \ range_3, range_2, range_1)(__VA_ARGS__)\n\n#define all(x) (x).begin(), (x).end()\n\
    #define rall(x) (x).rbegin(), (x).rend()\n#define len(x) ssize(x)\n#define elif\
    \ else if\n#define pb emplace_back\n#define db pop_back\n#define pf emplace_front\n\
    #define df pop_front\n#define fi first\n#define se second\n\n#define Sort(v) sort((v).begin(),\
    \ (v).end())\n#define troS(v) sort((v).rbegin(), (v).rend())\n#define Reverse(v)\
    \ reverse((v).begin(), (v).end())\n#define uniq(v) sort((v).begin(), (v).end()),\
    \ (v).erase(unique((v).begin(), (v).end()), (v).end()), (v).shrink_to_fit()\n\
    #define bit(x, i) (((x)>>i)&1)\n\n#define nextp(v) next_permutation((v).begin(),\
    \ (v).end())\ntemplate <class T>\nbool next_combination(T l, T r, int k) {\n \
    \   T m = l + k;\n    if (l==r || r==m || m==l) return false;\n    T t = m;\n\
    \    while (l != t) {\n        t--;\n        if (*t < *(r-1)) {\n            T\
    \ d = m;\n            while (*d <=*t) d++;\n            iter_swap(t, d);\n   \
    \         rotate(t+1, d+1, r);\n            rotate(m, m+(r-d)-1, r);\n       \
    \     return true;\n        }\n    }\n    rotate(l, m, r);\n    return false;\n\
    }\n#define nextc(v, k) next_combination((v).begin(), (v).end(), k)\n\n#define\
    \ Yes cout << \"Yes\\n\"\n#define No cout << \"No\\n\"\n#define YN(x) cout <<\
    \ ((x) ? \"Yes\\n\" : \"No\\n\")\n#define O(x) cout << (x) << '\\n'\n\n#define\
    \ ismid_1(x) true\ntemplate <class T, class U>\nbool inner_ismid_2(T x, U r) {\
    \ return T{}<=x && x<r; }\n#define ismid_2(x, r) inner_ismid_2(x, r)\ntemplate\
    \ <class T, class U, class V>\nbool inner_ismid_3(T l, U x, V r) { return l<=x\
    \ && x<r; }\n#define ismid_3(l, x, r) inner_ismid_3(l, x, r)\n#define overload_ismid(a,\
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
    }\n\nvoid solve();\n\n#line 3 \"structure/binary_trie.hpp\"\nusing namespace std;\n\
    \n// Binary trie  (non-negative integers, B-bit keys)\n// Operations in O(B):\n\
    //   insert(x), erase(x)\n//   count(x)     -- number of x stored\n//   size()\
    \       -- total count\n//   min_element()  -- minimum stored value\n//   max_element()\
    \  -- maximum stored value\n//   xor_min(x)   -- min(v XOR x) over all stored\
    \ v  (\"set_xor_min\" problem)\n//   kth(k)       -- k-th (0-indexed) smallest\n\
    //   lower_bound(x) -- count of elements < x\n\ntemplate <int B = 30>\nstruct\
    \ binary_trie {\n    struct Node {\n        int ch[2] = {-1, -1};\n        int\
    \ cnt = 0;\n    };\n    vector<Node> nd;\n\n    binary_trie() { nd.push_back({});\
    \ } // root = 0\n\n    int _new() { nd.push_back({}); return nd.size() - 1; }\n\
    \n    void insert(int x, int delta = 1) {\n        int v = 0;\n        nd[0].cnt\
    \ += delta;\n        for (int i = B - 1; i >= 0; i--) {\n            int b = (x\
    \ >> i) & 1;\n            if (nd[v].ch[b] == -1) nd[v].ch[b] = _new();\n     \
    \       v = nd[v].ch[b];\n            nd[v].cnt += delta;\n        }\n    }\n\
    \    void erase(int x) { insert(x, -1); }\n\n    int count(int x) const {\n  \
    \      int v = 0;\n        for (int i = B - 1; i >= 0; i--) {\n            int\
    \ b = (x >> i) & 1;\n            if (nd[v].ch[b] == -1) return 0;\n          \
    \  v = nd[v].ch[b];\n        }\n        return nd[v].cnt;\n    }\n    int size()\
    \ const { return nd[0].cnt; }\n    bool empty() const { return nd[0].cnt == 0;\
    \ }\n\n    // k-th (0-indexed) smallest\n    int kth(int k) const {\n        assert(0\
    \ <= k && k < size());\n        int v = 0, res = 0;\n        for (int i = B -\
    \ 1; i >= 0; i--) {\n            int l = nd[v].ch[0], lc = (l == -1 ? 0 : nd[l].cnt);\n\
    \            if (k < lc) { v = l; }\n            else { k -= lc; res |= (1 <<\
    \ i); v = nd[v].ch[1]; }\n        }\n        return res;\n    }\n    int min_element()\
    \ const { return kth(0); }\n    int max_element() const { return kth(size() -\
    \ 1); }\n\n    // min XOR with x\n    int xor_min(int x) const {\n        assert(!empty());\n\
    \        int v = 0, res = 0;\n        for (int i = B - 1; i >= 0; i--) {\n   \
    \         int b = (x >> i) & 1;\n            int want = b; // prefer same bit\
    \ => XOR becomes 0\n            if (nd[v].ch[want] == -1 || nd[nd[v].ch[want]].cnt\
    \ == 0) want ^= 1;\n            res |= ((want ^ b) << i);\n            v = nd[v].ch[want];\n\
    \        }\n        return res;\n    }\n\n    // number of elements < x\n    int\
    \ lower_bound(int x) const {\n        int v = 0, cnt = 0;\n        for (int i\
    \ = B - 1; i >= 0; i--) {\n            int b = (x >> i) & 1;\n            if (b\
    \ == 1) {\n                int l = nd[v].ch[0];\n                if (l != -1)\
    \ cnt += nd[l].cnt;\n            }\n            if (nd[v].ch[b] == -1) break;\n\
    \            v = nd[v].ch[b];\n        }\n        return cnt;\n    }\n};\n#line\
    \ 4 \"verify/library_checker_set_xor_min.test.cpp\"\n\nint main(){\n    IO();\n\
    \    int T = 1;\n    while (T--) solve();\n}\n\nvoid solve(){\n    int q; cin\
    \ >> q;\n    binary_trie<30> bt;\n    rep(q){\n        int t, x; cin >> t >> x;\n\
    \        if (t == 0)      bt.insert(x);\n        else if (t == 1) bt.erase(x);\n\
    \        else             cout << bt.xor_min(x) << nl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/set_xor_min\"\n#include\
    \ \"template\"\n#include \"binary_trie\"\n\nint main(){\n    IO();\n    int T\
    \ = 1;\n    while (T--) solve();\n}\n\nvoid solve(){\n    int q; cin >> q;\n \
    \   binary_trie<30> bt;\n    rep(q){\n        int t, x; cin >> t >> x;\n     \
    \   if (t == 0)      bt.insert(x);\n        else if (t == 1) bt.erase(x);\n  \
    \      else             cout << bt.xor_min(x) << nl;\n    }\n}\n"
  dependsOn:
  - utility/template.hpp
  - structure/binary_trie.hpp
  isVerificationFile: true
  path: verify/library_checker_set_xor_min.test.cpp
  requiredBy: []
  timestamp: '2026-03-09 22:49:24+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/library_checker_set_xor_min.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker_set_xor_min.test.cpp
- /verify/verify/library_checker_set_xor_min.test.cpp.html
title: verify/library_checker_set_xor_min.test.cpp
---
