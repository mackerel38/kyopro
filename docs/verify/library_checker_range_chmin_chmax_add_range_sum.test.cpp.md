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
    \ std;\n\n// Segment Beats (Ji Driver Segmentation)\n// Supports (all queries\
    \ half-open [l, r)):\n//   range_chmin(l, r, x) : a[i] = min(a[i], x)\n//   range_chmax(l,\
    \ r, x) : a[i] = max(a[i], x)\n//   range_add  (l, r, x) : a[i] += x\n//   range_set\
    \  (l, r, x) : a[i] = x\n//   query_max  (l, r)    : max of a[l..r)\n//   query_min\
    \  (l, r)    : min of a[l..r)\n//   query_sum  (l, r)    : sum of a[l..r)\n//\n\
    // Amortized O((n + q) log^2 n).\n// Reference: https://tjkendev.github.io/procon-library/cpp/range_query/segment_tree_beats_2.html\n\
    \nstruct segment_beats {\n    using ll = long long;\n    static constexpr ll LINF\
    \ = 2e18;\n\n    int n, n0;\n    // max_v, smax_v: max value, strict 2nd-max value\
    \ (-LINF if none)\n    // min_v, smin_v: min value, strict 2nd-min value (+LINF\
    \ if none)\n    vector<ll> max_v, smax_v, min_v, smin_v, sm, sz, ladd, lval;\n\
    \    vector<int> max_c, min_c;\n\n    // ---- leaf/node modifiers ----\n    //\
    \ addall: add x to every element of node k\n    void addall(int k, ll x) {\n \
    \       max_v[k] += x;\n        if (smax_v[k] != -LINF) smax_v[k] += x;\n    \
    \    min_v[k] += x;\n        if (smin_v[k] !=  LINF) smin_v[k] += x;\n       \
    \ sm[k] += sz[k] * x;\n        if (lval[k] != LINF) lval[k] += x;\n        else\
    \                 ladd[k] += x;\n    }\n    // setall: set every element of node\
    \ k to x\n    void setall(int k, ll x) {\n        max_v[k] = smax_v[k] = min_v[k]\
    \ = smin_v[k] = x;\n        max_c[k] = min_c[k] = (int)sz[k];\n        sm[k] =\
    \ sz[k] * x;\n        lval[k] = x; ladd[k] = 0;\n    }\n    // push_chmin: apply\
    \ chmin(x) to node k, reducing its current max to x\n    //   precondition: smax_v[k]\
    \ < x < max_v[k]\n    void push_chmin(int k, ll x) {\n        sm[k] -= (max_v[k]\
    \ - x) * max_c[k];\n        if (max_v[k] == min_v[k]) min_v[k] = x;\n        if\
    \ (max_v[k] == smin_v[k]) smin_v[k] = x;\n        max_v[k] = x;\n        if (lval[k]\
    \ != LINF && lval[k] > x) lval[k] = x;\n    }\n    // push_chmax: apply chmax(x)\
    \ to node k, raising its current min to x\n    //   precondition: smin_v[k] >\
    \ x > min_v[k]\n    void push_chmax(int k, ll x) {\n        sm[k] += (x - min_v[k])\
    \ * min_c[k];\n        if (max_v[k] == min_v[k]) max_v[k] = x;\n        if (smax_v[k]\
    \ == min_v[k]) smax_v[k] = x;\n        min_v[k] = x;\n        if (lval[k] != LINF\
    \ && lval[k] < x) lval[k] = x;\n    }\n\n    // pull: recompute node k from its\
    \ children\n    void pull(int k) {\n        int l = 2*k, r = 2*k+1;\n        sm[k]\
    \ = sm[l] + sm[r];\n        // max info\n        if      (max_v[l] < max_v[r])\
    \ { max_v[k]=max_v[r]; max_c[k]=max_c[r]; smax_v[k]=max(max_v[l], smax_v[r]);\
    \ }\n        else if (max_v[l] > max_v[r]) { max_v[k]=max_v[l]; max_c[k]=max_c[l];\
    \ smax_v[k]=max(smax_v[l], max_v[r]); }\n        else                        \
    \  { max_v[k]=max_v[l]; max_c[k]=max_c[l]+max_c[r]; smax_v[k]=max(smax_v[l], smax_v[r]);\
    \ }\n        // min info\n        if      (min_v[l] < min_v[r]) { min_v[k]=min_v[l];\
    \ min_c[k]=min_c[l]; smin_v[k]=min(smin_v[l], min_v[r]); }\n        else if (min_v[l]\
    \ > min_v[r]) { min_v[k]=min_v[r]; min_c[k]=min_c[r]; smin_v[k]=min(min_v[l],\
    \ smin_v[r]); }\n        else                          { min_v[k]=min_v[l]; min_c[k]=min_c[l]+min_c[r];\
    \ smin_v[k]=min(smin_v[l], smin_v[r]); }\n    }\n\n    // push: propagate lazy\
    \ values to children\n    void push(int k) {\n        if (k >= n0) return;  //\
    \ leaf: nothing to push\n        if (lval[k] != LINF) {\n            setall(2*k,\
    \ lval[k]); setall(2*k+1, lval[k]);\n            lval[k] = LINF; ladd[k] = 0;\n\
    \            return;\n        }\n        if (ladd[k] != 0) {\n            addall(2*k,\
    \ ladd[k]); addall(2*k+1, ladd[k]);\n            ladd[k] = 0;\n        }\n   \
    \     // propagate chmin / chmax bounds\n        if (max_v[k] < max_v[2*k])  \
    \ push_chmin(2*k,   max_v[k]);\n        if (min_v[2*k] < min_v[k])   push_chmax(2*k,\
    \   min_v[k]);\n        if (max_v[k] < max_v[2*k+1]) push_chmin(2*k+1, max_v[k]);\n\
    \        if (min_v[2*k+1] < min_v[k]) push_chmax(2*k+1, min_v[k]);\n    }\n\n\
    \    // ---- range operations ----\n    void _chmin(ll x, int a, int b, int k,\
    \ int l, int r) {\n        if (b <= l || r <= a || max_v[k] <= x) return;\n  \
    \      if (a <= l && r <= b && smax_v[k] < x) { push_chmin(k, x); return; }\n\
    \        push(k); int m = (l+r)/2;\n        _chmin(x,a,b,2*k,l,m); _chmin(x,a,b,2*k+1,m,r);\
    \ pull(k);\n    }\n    void _chmax(ll x, int a, int b, int k, int l, int r) {\n\
    \        if (b <= l || r <= a || x <= min_v[k]) return;\n        if (a <= l &&\
    \ r <= b && x < smin_v[k]) { push_chmax(k, x); return; }\n        push(k); int\
    \ m = (l+r)/2;\n        _chmax(x,a,b,2*k,l,m); _chmax(x,a,b,2*k+1,m,r); pull(k);\n\
    \    }\n    void _add(ll x, int a, int b, int k, int l, int r) {\n        if (b\
    \ <= l || r <= a) return;\n        if (a <= l && r <= b) { addall(k, x); return;\
    \ }\n        push(k); int m = (l+r)/2;\n        _add(x,a,b,2*k,l,m); _add(x,a,b,2*k+1,m,r);\
    \ pull(k);\n    }\n    void _set(ll x, int a, int b, int k, int l, int r) {\n\
    \        if (b <= l || r <= a) return;\n        if (a <= l && r <= b) { setall(k,\
    \ x); return; }\n        push(k); int m = (l+r)/2;\n        _set(x,a,b,2*k,l,m);\
    \ _set(x,a,b,2*k+1,m,r); pull(k);\n    }\n    ll _qmax(int a, int b, int k, int\
    \ l, int r) {\n        if (b <= l || r <= a) return -LINF;\n        if (a <= l\
    \ && r <= b) return max_v[k];\n        push(k); int m = (l+r)/2;\n        return\
    \ max(_qmax(a,b,2*k,l,m), _qmax(a,b,2*k+1,m,r));\n    }\n    ll _qmin(int a, int\
    \ b, int k, int l, int r) {\n        if (b <= l || r <= a) return LINF;\n    \
    \    if (a <= l && r <= b) return min_v[k];\n        push(k); int m = (l+r)/2;\n\
    \        return min(_qmin(a,b,2*k,l,m), _qmin(a,b,2*k+1,m,r));\n    }\n    ll\
    \ _qsum(int a, int b, int k, int l, int r) {\n        if (b <= l || r <= a) return\
    \ 0;\n        if (a <= l && r <= b) return sm[k];\n        push(k); int m = (l+r)/2;\n\
    \        return _qsum(a,b,2*k,l,m) + _qsum(a,b,2*k+1,m,r);\n    }\n\n    // ----\
    \ construction ----\n    void _init(int n_, const ll* a) {\n        n = n_; n0\
    \ = 1; while (n0 < n) n0 <<= 1;\n        int sz2 = 2 * n0 + 2;\n        max_v.assign(sz2,\
    \ -LINF); smax_v.assign(sz2, -LINF); max_c.assign(sz2, 0);\n        min_v.assign(sz2,\
    \  LINF); smin_v.assign(sz2,  LINF); min_c.assign(sz2, 0);\n        sm.assign(sz2,\
    \ 0); sz.assign(sz2, 0);\n        ladd.assign(sz2, 0); lval.assign(sz2, LINF);\n\
    \        // set sizes (sz[k] = number of REAL elements covered)\n        // We\
    \ need sz for addall/setall. Use len = 1 for each leaf.\n        // sz at leaves:\
    \ real leaves have sz=1, padding leaves have sz=0.\n        // Propagate up.\n\
    \        for (int i = n0; i < n0 + n; i++) sz[i] = 1;\n        for (int i = n0\
    \ - 1; i >= 1; i--) sz[i] = sz[2*i] + sz[2*i+1];\n        // Note: we also need\
    \ sz for addall/setall at non-leaf nodes.\n        // Actually, for addall we\
    \ use sm[k] += sz[k] * x,\n        // so sz[k] must count only real elements.\n\
    \        // Initialize leaves\n        for (int i = 0; i < n; i++) {\n       \
    \     int k = n0 + i;\n            ll v = (a ? a[i] : 0LL);\n            max_v[k]\
    \ = smax_v[k] = min_v[k] = smin_v[k] = v;\n            max_c[k] = min_c[k] = 1;\n\
    \            sm[k] = v;\n        }\n        // padding leaves: already -LINF /\
    \ LINF / count=0\n        for (int i = n0 - 1; i >= 1; i--) pull(i);\n    }\n\n\
    public:\n    segment_beats() = default;\n    segment_beats(int n, ll init_val\
    \ = 0) {\n        vector<ll> a(n, init_val);\n        _init(n, a.data());\n  \
    \  }\n    segment_beats(const vector<ll>& a) { _init((int)a.size(), a.data());\
    \ }\n\n    // half-open intervals [l, r)\n    void range_chmin(int l, int r, ll\
    \ x) { _chmin(x, l, r, 1, 0, n0); }\n    void range_chmax(int l, int r, ll x)\
    \ { _chmax(x, l, r, 1, 0, n0); }\n    void range_add  (int l, int r, ll x) { _add\
    \  (x, l, r, 1, 0, n0); }\n    void range_set  (int l, int r, ll x) { _set  (x,\
    \ l, r, 1, 0, n0); }\n    ll query_max(int l, int r) { return _qmax(l, r, 1, 0,\
    \ n0); }\n    ll query_min(int l, int r) { return _qmin(l, r, 1, 0, n0); }\n \
    \   ll query_sum(int l, int r) { return _qsum(l, r, 1, 0, n0); }\n};\n#line 4\
    \ \"verify/library_checker_range_chmin_chmax_add_range_sum.test.cpp\"\n\nint main(){\n\
    \    IO();\n    int T = 1;\n    while (T--) solve();\n}\n\nvoid solve(){\n   \
    \ int n, q; cin >> n >> q;\n    vector<ll> a(n);\n    rep(i, n) cin >> a[i];\n\
    \    segment_beats sb(a);\n    rep(q){\n        int t; cin >> t;\n        if (t\
    \ == 0){\n            // range chmin: a[i] = min(a[i], b) for i in [l, r)\n  \
    \          int l, r; ll b; cin >> l >> r >> b;\n            sb.range_chmin(l,\
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
  timestamp: '2026-03-10 02:22:16+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/library_checker_range_chmin_chmax_add_range_sum.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker_range_chmin_chmax_add_range_sum.test.cpp
- /verify/verify/library_checker_range_chmin_chmax_add_range_sum.test.cpp.html
title: verify/library_checker_range_chmin_chmax_add_range_sum.test.cpp
---
