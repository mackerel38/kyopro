---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: structure/wavelet_matrix.hpp
    title: structure/wavelet_matrix.hpp
  - icon: ':question:'
    path: utility/template.hpp
    title: utility/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_kth_smallest
    links:
    - https://judge.yosupo.jp/problem/range_kth_smallest
  bundledCode: "#line 1 \"verify/library_checker_range_kth_smallest.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/range_kth_smallest\"\n#line 2 \"utility/template.hpp\"\
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
    }\n\nvoid solve();\n\n#line 3 \"structure/wavelet_matrix.hpp\"\nusing namespace\
    \ std;\n\n// Wavelet Matrix\n// Operations on a static sequence a[0..n)  of non-negative\
    \ integers.\n// All values must be < (1 << B) after coordinate compression.\n\
    //\n// O(n B) build,  O(B) per query  (B = number of bits, default 20)\n//\n//\
    \ Queries:\n//   kth(l, r, k)              k-th (0-indexed) smallest in a[l..r)\n\
    //   count(l, r, x)            number of occurrences of x in a[l..r)\n//   count_lt(l,\
    \ r, x)         number of elements < x in a[l..r)\n//   range_freq(l, r, lo, hi)\
    \  count of elements in [lo, hi) in a[l..r)\n\ntemplate <int B = 20>\nstruct wavelet_matrix\
    \ {\n    // Succinct bit vector with rank\n    struct bv {\n        vector<uint32_t>\
    \ blk;\n        vector<int> cum;\n        int n;\n        template <class F>\n\
    \        void build(int sz, F get) {\n            n = sz;\n            blk.assign((n\
    \ + 31) >> 5, 0);\n            cum.resize(blk.size() + 1, 0);\n            for\
    \ (int i = 0; i < n; i++) if (get(i)) blk[i >> 5] |= 1u << (i & 31);\n       \
    \     for (int i = 0; i < (int)blk.size(); i++)\n                cum[i+1] = cum[i]\
    \ + __builtin_popcount(blk[i]);\n        }\n        // number of 1s in [0, i)\n\
    \        int rank1(int i) const {\n            if (i <= 0) return 0;\n       \
    \     return cum[i >> 5] + __builtin_popcount(blk[i >> 5] & ((1u << (i & 31))\
    \ - 1));\n        }\n        int rank0(int i) const { return i - rank1(i); }\n\
    \        int total1() const { return cum.back(); }\n    };\n\n    int n;\n   \
    \ array<bv, B> bvs;\n    array<int, B> mid; // number of 0s at each level\n\n\
    \    wavelet_matrix() = default;\n\n    // Build from vector. Values must be in\
    \ [0, 2^B).\n    void build(vector<int> v) {\n        n = v.size();\n        for\
    \ (int d = B - 1; d >= 0; d--) {\n            bvs[d].build(n, [&](int i){ return\
    \ (v[i] >> d) & 1; });\n            mid[d] = bvs[d].rank0(n);\n            vector<int>\
    \ a0, a1;\n            for (int x : v) ((x >> d) & 1 ? a1 : a0).push_back(x);\n\
    \            v = a0; v.insert(v.end(), a1.begin(), a1.end());\n        }\n   \
    \ }\n\n    pair<int,int> _down(int d, int l, int r, int bit) const {\n       \
    \ int l0 = bvs[d].rank0(l), r0 = bvs[d].rank0(r);\n        if (bit == 0) return\
    \ {l0, r0};\n        return {mid[d] + l - l0, mid[d] + r - r0};\n    }\n\n   \
    \ // k-th (0-indexed) smallest in a[l..r)\n    int kth(int l, int r, int k) const\
    \ {\n        int res = 0;\n        for (int d = B - 1; d >= 0; d--) {\n      \
    \      int cnt0 = bvs[d].rank0(r) - bvs[d].rank0(l);\n            if (k < cnt0)\
    \ { tie(l, r) = _down(d, l, r, 0); }\n            else { k -= cnt0; res |= (1\
    \ << d); tie(l, r) = _down(d, l, r, 1); }\n        }\n        return res;\n  \
    \  }\n\n    // number of elements < x in a[l..r)\n    int count_lt(int l, int\
    \ r, int x) const {\n        int cnt = 0;\n        for (int d = B - 1; d >= 0;\
    \ d--) {\n            int b = (x >> d) & 1;\n            if (b) cnt += bvs[d].rank0(r)\
    \ - bvs[d].rank0(l);\n            tie(l, r) = _down(d, l, r, b);\n        }\n\
    \        return cnt;\n    }\n\n    // number of occurrences of x in a[l..r)\n\
    \    int count(int l, int r, int x) const {\n        for (int d = B - 1; d >=\
    \ 0; d--)\n            tie(l, r) = _down(d, l, r, (x >> d) & 1);\n        return\
    \ r - l;\n    }\n\n    // number of elements in [lo, hi) in a[l..r)\n    int range_freq(int\
    \ l, int r, int lo, int hi) const {\n        return count_lt(l, r, hi) - count_lt(l,\
    \ r, lo);\n    }\n};\n\n// Wavelet matrix with sum support  (O(B) sum_lt queries)\n\
    // Stores prefix sums at each level of the wavelet matrix.\ntemplate <int B =\
    \ 20>\nstruct wavelet_matrix_sum : wavelet_matrix<B> {\n    using base = wavelet_matrix<B>;\n\
    \    array<vector<long long>, B> lpsum;\n\n    void build(vector<int> v) {\n \
    \       base::build(v);\n        int n = v.size();\n        for (int d = B - 1;\
    \ d >= 0; d--) {\n            lpsum[d].resize(n + 1, 0);\n            vector<int>\
    \ a0, a1;\n            for (int x : v) ((x >> d) & 1 ? a1 : a0).push_back(x);\n\
    \            for (int i = 0; i < (int)a0.size(); i++) lpsum[d][i+1] = lpsum[d][i]\
    \ + a0[i];\n            int off = a0.size();\n            for (int i = 0; i <\
    \ (int)a1.size(); i++) lpsum[d][off+i+1] = lpsum[d][off+i] + a1[i];\n        \
    \    v = a0; v.insert(v.end(), a1.begin(), a1.end());\n        }\n    }\n\n  \
    \  // sum of elements < x in a[l..r)  O(B)\n    long long sum_lt(int l, int r,\
    \ int x) const {\n        long long s = 0;\n        int cl = l, cr = r;\n    \
    \    for (int d = B - 1; d >= 0; d--) {\n            int b = (x >> d) & 1;\n \
    \           int l0 = base::bvs[d].rank0(cl), r0 = base::bvs[d].rank0(cr);\n  \
    \          if (b) {\n                s += lpsum[d][r0] - lpsum[d][l0];\n     \
    \           cl = base::mid[d] + (cl - l0);\n                cr = base::mid[d]\
    \ + (cr - r0);\n            } else {\n                cl = l0; cr = r0;\n    \
    \        }\n        }\n        return s;\n    }\n\n    // sum of elements in [lo,\
    \ hi) in a[l..r)\n    long long range_sum(int l, int r, int lo, int hi) const\
    \ {\n        return sum_lt(l, r, hi) - sum_lt(l, r, lo);\n    }\n};\n#line 4 \"\
    verify/library_checker_range_kth_smallest.test.cpp\"\n\nint main(){\n    IO();\n\
    \    int T = 1;\n    while (T--) solve();\n}\n\nvoid solve(){\n    int n, q; cin\
    \ >> n >> q;\n    vector<int> a(n);\n    rep(i, n) cin >> a[i];\n\n    // Coordinate\
    \ compress (values up to ~10^9)\n    vector<int> vals = a;\n    sort(vals.begin(),\
    \ vals.end()); vals.erase(unique(vals.begin(), vals.end()), vals.end());\n   \
    \ vector<int> ca(n);\n    rep(i, n) ca[i] = (int)(lower_bound(vals.begin(), vals.end(),\
    \ a[i]) - vals.begin());\n\n    // Compressed values fit in [0, n) \u2282 [0,\
    \ 2^20), so B=20 is sufficient for n<=10^6\n    wavelet_matrix<20> wm;\n    wm.build(ca);\n\
    \n    rep(q){\n        int l, r, k; cin >> l >> r >> k;\n        cout << vals[wm.kth(l,\
    \ r, k)] << nl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_kth_smallest\"\n\
    #include \"template\"\n#include \"wavelet_matrix\"\n\nint main(){\n    IO();\n\
    \    int T = 1;\n    while (T--) solve();\n}\n\nvoid solve(){\n    int n, q; cin\
    \ >> n >> q;\n    vector<int> a(n);\n    rep(i, n) cin >> a[i];\n\n    // Coordinate\
    \ compress (values up to ~10^9)\n    vector<int> vals = a;\n    sort(vals.begin(),\
    \ vals.end()); vals.erase(unique(vals.begin(), vals.end()), vals.end());\n   \
    \ vector<int> ca(n);\n    rep(i, n) ca[i] = (int)(lower_bound(vals.begin(), vals.end(),\
    \ a[i]) - vals.begin());\n\n    // Compressed values fit in [0, n) \u2282 [0,\
    \ 2^20), so B=20 is sufficient for n<=10^6\n    wavelet_matrix<20> wm;\n    wm.build(ca);\n\
    \n    rep(q){\n        int l, r, k; cin >> l >> r >> k;\n        cout << vals[wm.kth(l,\
    \ r, k)] << nl;\n    }\n}\n"
  dependsOn:
  - utility/template.hpp
  - structure/wavelet_matrix.hpp
  isVerificationFile: true
  path: verify/library_checker_range_kth_smallest.test.cpp
  requiredBy: []
  timestamp: '2026-03-09 22:49:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker_range_kth_smallest.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker_range_kth_smallest.test.cpp
- /verify/verify/library_checker_range_kth_smallest.test.cpp.html
title: verify/library_checker_range_kth_smallest.test.cpp
---
