---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: structure/segment_beats.hpp
    title: structure/segment_beats.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum
  bundledCode: "#line 1 \"verify/library_checker_range_chmin_chmax_add_range_sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum\"\
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
    }\n\nvoid solve();\n\n#line 3 \"structure/segment_beats.hpp\"\nusing namespace\
    \ std;\n\n// Segment Beats (Ji Driver Segmentation)\n// Supports:\n//   range\
    \ chmin   : for i in [l,r), a[i] = min(a[i], v)\n//   range chmax   : for i in\
    \ [l,r), a[i] = max(a[i], v)\n//   range add     : for i in [l,r), a[i] += v\n\
    //   range sum     : sum of a[l..r)\n//   range min/max : min/max of a[l..r)\n\
    //\n// Amortized O((n + q) log^2 n) time.\n//\n// Reference: Ji (2016), \"Chtholly\
    \ Tree\" style lazy propagation.\n\nstruct segment_beats {\n    struct Node {\n\
    \        long long sum;\n        long long mx, mx2; int mxc;  // max, 2nd max,\
    \ count of max\n        long long mn, mn2; int mnc;  // min, 2nd min, count of\
    \ min\n        long long lazy_add;\n        long long lazy_chmin, lazy_chmax;\
    \ // pending clamp targets\n    };\n\n    int n;\n    vector<Node> t;\n\n    void\
    \ _init(Node& nd, long long v) {\n        nd.sum = v; nd.mx = v; nd.mx2 = LLONG_MIN;\
    \ nd.mxc = 1;\n        nd.mn = v; nd.mn2 = LLONG_MAX; nd.mnc = 1;\n        nd.lazy_add\
    \ = 0; nd.lazy_chmin = LLONG_MAX; nd.lazy_chmax = LLONG_MIN;\n    }\n\n    void\
    \ _pull(int v) {\n        auto &L = t[2*v], &R = t[2*v+1], &N = t[v];\n      \
    \  N.sum = L.sum + R.sum;\n        // max\n        if (L.mx == R.mx) { N.mx =\
    \ L.mx; N.mxc = L.mxc + R.mxc; N.mx2 = max(L.mx2, R.mx2); }\n        else if (L.mx\
    \ > R.mx) { N.mx = L.mx; N.mxc = L.mxc; N.mx2 = max(L.mx2, R.mx); }\n        else\
    \ { N.mx = R.mx; N.mxc = R.mxc; N.mx2 = max(L.mx, R.mx2); }\n        // min\n\
    \        if (L.mn == R.mn) { N.mn = L.mn; N.mnc = L.mnc + R.mnc; N.mn2 = min(L.mn2,\
    \ R.mn2); }\n        else if (L.mn < R.mn) { N.mn = L.mn; N.mnc = L.mnc; N.mn2\
    \ = min(L.mn2, R.mn); }\n        else { N.mn = R.mn; N.mnc = R.mnc; N.mn2 = min(L.mn,\
    \ R.mn2); }\n        N.lazy_add = 0; N.lazy_chmin = LLONG_MAX; N.lazy_chmax =\
    \ LLONG_MIN;\n    }\n\n    void _apply_add(int v, long long val) {\n        t[v].sum\
    \ += val * (/* node size */ 1); // corrected in _push\n        t[v].mx += val;\
    \ if (t[v].mx2 != LLONG_MIN) t[v].mx2 += val;\n        t[v].mn += val; if (t[v].mn2\
    \ != LLONG_MAX) t[v].mn2 += val;\n        if (t[v].lazy_chmin != LLONG_MAX) t[v].lazy_chmin\
    \ += val;\n        if (t[v].lazy_chmax != LLONG_MIN) t[v].lazy_chmax += val;\n\
    \        t[v].lazy_add += val;\n    }\n    void _apply_chmin(int v, long long\
    \ val) {\n        if (val >= t[v].mx) return;\n        t[v].sum -= (long long)(t[v].mx\
    \ - val) * t[v].mxc;\n        if (t[v].lazy_chmin != LLONG_MAX) t[v].lazy_chmin\
    \ = min(t[v].lazy_chmin, val);\n        else t[v].lazy_chmin = val;\n        t[v].mx\
    \ = val;\n    }\n    void _apply_chmax(int v, long long val) {\n        if (val\
    \ <= t[v].mn) return;\n        t[v].sum += (long long)(val - t[v].mn) * t[v].mnc;\n\
    \        if (t[v].lazy_chmax != LLONG_MIN) t[v].lazy_chmax = max(t[v].lazy_chmax,\
    \ val);\n        else t[v].lazy_chmax = val;\n        t[v].mn = val;\n    }\n\n\
    \    void _push(int v, int sz) {\n        int lsz = sz - sz / 2, rsz = sz / 2;\
    \ // left child size, right child size\n        // correct lazy_add to account\
    \ for node sizes\n        // Actually, we maintain sum correctly in apply; just\
    \ propagate lazy\n        if (t[v].lazy_add) {\n            t[2*v].sum   += t[v].lazy_add\
    \ * lsz;\n            t[2*v+1].sum += t[v].lazy_add * rsz;\n            _apply_add(2*v,\
    \   t[v].lazy_add); t[2*v].sum   -= t[v].lazy_add * lsz;   // undo overcounting\n\
    \            _apply_add(2*v+1, t[v].lazy_add); t[2*v+1].sum -= t[v].lazy_add *\
    \ rsz;\n            // Actually rewrite with proper size-aware apply\n       \
    \ }\n        // This simple approach has issues with sum tracking. Use size-aware\
    \ nodes:\n        // See the rewritten version below.\n        (void)v; (void)sz;\n\
    \    }\n\n    // --- Proper implementation with explicit size ---\n    // Rewrite\
    \ using sz stored in node.\n\n    struct Node2 {\n        long long sum, add;\n\
    \        long long mx, mx2, chmin; int mxcnt;\n        long long mn, mn2, chmax;\
    \ int mncnt;\n        int sz;\n    };\n    vector<Node2> nd;\n\n    void _build(int\
    \ v, int l, int r, const vector<long long>& a) {\n        nd[v].sz = r - l;\n\
    \        nd[v].add = 0; nd[v].chmin = LLONG_MAX; nd[v].chmax = LLONG_MIN;\n  \
    \      if (r - l == 1) {\n            nd[v].sum = a[l];\n            nd[v].mx\
    \ = nd[v].mn = a[l];\n            nd[v].mx2 = LLONG_MIN; nd[v].mxcnt = 1;\n  \
    \          nd[v].mn2 = LLONG_MAX; nd[v].mncnt = 1;\n            return;\n    \
    \    }\n        int m = (l + r) / 2;\n        _build(2*v, l, m, a); _build(2*v+1,\
    \ m, r, a);\n        _up(v);\n    }\n\n    void _up(int v) {\n        auto &L\
    \ = nd[2*v], &R = nd[2*v+1], &N = nd[v];\n        N.sum = L.sum + R.sum;\n   \
    \     if (L.mx == R.mx) { N.mx = L.mx; N.mxcnt = L.mxcnt + R.mxcnt; N.mx2 = max(L.mx2,\
    \ R.mx2); }\n        else if (L.mx > R.mx) { N.mx = L.mx; N.mxcnt = L.mxcnt; N.mx2\
    \ = max(L.mx2, R.mx); }\n        else { N.mx = R.mx; N.mxcnt = R.mxcnt; N.mx2\
    \ = max(L.mx, R.mx2); }\n        if (L.mn == R.mn) { N.mn = L.mn; N.mncnt = L.mncnt\
    \ + R.mncnt; N.mn2 = min(L.mn2, R.mn2); }\n        else if (L.mn < R.mn) { N.mn\
    \ = L.mn; N.mncnt = L.mncnt; N.mn2 = min(L.mn2, R.mn); }\n        else { N.mn\
    \ = R.mn; N.mncnt = R.mncnt; N.mn2 = min(L.mn, R.mn2); }\n    }\n\n    void _push_add(int\
    \ v, long long val) {\n        nd[v].sum += val * nd[v].sz;\n        nd[v].mx\
    \ += val; nd[v].mn += val;\n        if (nd[v].mx2 != LLONG_MIN) nd[v].mx2 += val;\n\
    \        if (nd[v].mn2 != LLONG_MAX) nd[v].mn2 += val;\n        if (nd[v].chmin\
    \ != LLONG_MAX) nd[v].chmin += val;\n        if (nd[v].chmax != LLONG_MIN) nd[v].chmax\
    \ += val;\n        nd[v].add += val;\n    }\n    void _push_chmin(int v, long\
    \ long val) {\n        if (val >= nd[v].mx) return;\n        nd[v].sum -= (nd[v].mx\
    \ - val) * nd[v].mxcnt;\n        nd[v].chmin = (nd[v].chmin != LLONG_MAX) ? min(nd[v].chmin,\
    \ val) : val;\n        nd[v].mx = val;\n    }\n    void _push_chmax(int v, long\
    \ long val) {\n        if (val <= nd[v].mn) return;\n        nd[v].sum += (val\
    \ - nd[v].mn) * nd[v].mncnt;\n        nd[v].chmax = (nd[v].chmax != LLONG_MIN)\
    \ ? max(nd[v].chmax, val) : val;\n        nd[v].mn = val;\n    }\n    void _pushdown(int\
    \ v) {\n        if (nd[v].add != 0) {\n            _push_add(2*v, nd[v].add);\
    \ _push_add(2*v+1, nd[v].add);\n            nd[v].add = 0;\n        }\n      \
    \  if (nd[v].chmin != LLONG_MAX) {\n            _push_chmin(2*v, nd[v].chmin);\
    \ _push_chmin(2*v+1, nd[v].chmin);\n            nd[v].chmin = LLONG_MAX;\n   \
    \     }\n        if (nd[v].chmax != LLONG_MIN) {\n            _push_chmax(2*v,\
    \ nd[v].chmax); _push_chmax(2*v+1, nd[v].chmax);\n            nd[v].chmax = LLONG_MIN;\n\
    \        }\n    }\n\n    // apply range add [l,r) += val, current node [nl,nr)\n\
    \    void _add(int v, int nl, int nr, int l, int r, long long val) {\n       \
    \ if (r <= nl || nr <= l) return;\n        if (l <= nl && nr <= r) { _push_add(v,\
    \ val); return; }\n        _pushdown(v); int m = (nl + nr) / 2;\n        _add(2*v,\
    \ nl, m, l, r, val); _add(2*v+1, m, nr, l, r, val); _up(v);\n    }\n    void _chmin(int\
    \ v, int nl, int nr, int l, int r, long long val) {\n        if (r <= nl || nr\
    \ <= l || val >= nd[v].mx) return;\n        if (l <= nl && nr <= r && val > nd[v].mx2)\
    \ { _push_chmin(v, val); return; }\n        _pushdown(v); int m = (nl + nr) /\
    \ 2;\n        _chmin(2*v, nl, m, l, r, val); _chmin(2*v+1, m, nr, l, r, val);\
    \ _up(v);\n    }\n    void _chmax(int v, int nl, int nr, int l, int r, long long\
    \ val) {\n        if (r <= nl || nr <= l || val <= nd[v].mn) return;\n       \
    \ if (l <= nl && nr <= r && val < nd[v].mn2) { _push_chmax(v, val); return; }\n\
    \        _pushdown(v); int m = (nl + nr) / 2;\n        _chmax(2*v, nl, m, l, r,\
    \ val); _chmax(2*v+1, m, nr, l, r, val); _up(v);\n    }\n    long long _query_sum(int\
    \ v, int nl, int nr, int l, int r) {\n        if (r <= nl || nr <= l) return 0;\n\
    \        if (l <= nl && nr <= r) return nd[v].sum;\n        _pushdown(v); int\
    \ m = (nl + nr) / 2;\n        return _query_sum(2*v, nl, m, l, r) + _query_sum(2*v+1,\
    \ m, nr, l, r);\n    }\n    long long _query_min(int v, int nl, int nr, int l,\
    \ int r) {\n        if (r <= nl || nr <= l) return LLONG_MAX;\n        if (l <=\
    \ nl && nr <= r) return nd[v].mn;\n        _pushdown(v); int m = (nl + nr) / 2;\n\
    \        return min(_query_min(2*v, nl, m, l, r), _query_min(2*v+1, m, nr, l,\
    \ r));\n    }\n    long long _query_max(int v, int nl, int nr, int l, int r) {\n\
    \        if (r <= nl || nr <= l) return LLONG_MIN;\n        if (l <= nl && nr\
    \ <= r) return nd[v].mx;\n        _pushdown(v); int m = (nl + nr) / 2;\n     \
    \   return max(_query_max(2*v, nl, m, l, r), _query_max(2*v+1, m, nr, l, r));\n\
    \    }\n\npublic:\n    segment_beats() = default;\n    segment_beats(int n, long\
    \ long init_val = 0)\n        : n(n), nd(4 * n) {\n        vector<long long> a(n,\
    \ init_val);\n        _build(1, 0, n, a);\n    }\n    segment_beats(const vector<long\
    \ long>& a)\n        : n(a.size()), nd(4 * a.size()) {\n        _build(1, 0, n,\
    \ a);\n    }\n\n    void range_add  (int l, int r, long long v) { _add  (1, 0,\
    \ n, l, r, v); }\n    void range_chmin(int l, int r, long long v) { _chmin(1,\
    \ 0, n, l, r, v); }\n    void range_chmax(int l, int r, long long v) { _chmax(1,\
    \ 0, n, l, r, v); }\n\n    long long query_sum(int l, int r) { return _query_sum(1,\
    \ 0, n, l, r); }\n    long long query_min(int l, int r) { return _query_min(1,\
    \ 0, n, l, r); }\n    long long query_max(int l, int r) { return _query_max(1,\
    \ 0, n, l, r); }\n};\n#line 4 \"verify/library_checker_range_chmin_chmax_add_range_sum.test.cpp\"\
    \n\nint main(){\n    IO();\n    int T = 1;\n    while (T--) solve();\n}\n\nvoid\
    \ solve(){\n    int n, q; cin >> n >> q;\n    vector<ll> a(n);\n    rep(i, n)\
    \ cin >> a[i];\n    segment_beats sb(a);\n    rep(q){\n        int t; cin >> t;\n\
    \        if (t == 0){\n            // range chmin: a[i] = min(a[i], b) for i in\
    \ [l, r)\n            int l, r; ll b; cin >> l >> r >> b;\n            sb.range_chmin(l,\
    \ r, b);\n        } else if (t == 1){\n            // range chmax: a[i] = max(a[i],\
    \ b) for i in [l, r)\n            int l, r; ll b; cin >> l >> r >> b;\n      \
    \      sb.range_chmax(l, r, b);\n        } else if (t == 2){\n            // range\
    \ add: a[i] += b for i in [l, r)\n            int l, r; ll b; cin >> l >> r >>\
    \ b;\n            sb.range_add(l, r, b);\n        } else {\n            // range\
    \ sum query\n            int l, r; cin >> l >> r;\n            cout << sb.query_sum(l,\
    \ r) << nl;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum\"\
    \n#include \"template\"\n#include \"segment_beats\"\n\nint main(){\n    IO();\n\
    \    int T = 1;\n    while (T--) solve();\n}\n\nvoid solve(){\n    int n, q; cin\
    \ >> n >> q;\n    vector<ll> a(n);\n    rep(i, n) cin >> a[i];\n    segment_beats\
    \ sb(a);\n    rep(q){\n        int t; cin >> t;\n        if (t == 0){\n      \
    \      // range chmin: a[i] = min(a[i], b) for i in [l, r)\n            int l,\
    \ r; ll b; cin >> l >> r >> b;\n            sb.range_chmin(l, r, b);\n       \
    \ } else if (t == 1){\n            // range chmax: a[i] = max(a[i], b) for i in\
    \ [l, r)\n            int l, r; ll b; cin >> l >> r >> b;\n            sb.range_chmax(l,\
    \ r, b);\n        } else if (t == 2){\n            // range add: a[i] += b for\
    \ i in [l, r)\n            int l, r; ll b; cin >> l >> r >> b;\n            sb.range_add(l,\
    \ r, b);\n        } else {\n            // range sum query\n            int l,\
    \ r; cin >> l >> r;\n            cout << sb.query_sum(l, r) << nl;\n        }\n\
    \    }\n}\n"
  dependsOn:
  - utility/template.hpp
  - structure/segment_beats.hpp
  isVerificationFile: true
  path: verify/library_checker_range_chmin_chmax_add_range_sum.test.cpp
  requiredBy: []
  timestamp: '2026-03-09 22:49:24+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/library_checker_range_chmin_chmax_add_range_sum.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker_range_chmin_chmax_add_range_sum.test.cpp
- /verify/verify/library_checker_range_chmin_chmax_add_range_sum.test.cpp.html
title: verify/library_checker_range_chmin_chmax_add_range_sum.test.cpp
---
