---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: structure/BIT2d.hpp
    title: structure/BIT2d.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/point_add_rectangle_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_rectangle_sum
  bundledCode: "#line 1 \"verify/library_checker_point_add_rectangle_sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_rectangle_sum\"\n\
    #line 2 \"utility/template.hpp\"\n#ifdef poe\n#define debug(x) cerr << #x << \"\
    : \" << x << '\\n'\n#else\n#define debug(x)\n#endif\n\n#include <bits/stdc++.h>\n\
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
    }\n\nvoid solve();\n\n#line 3 \"structure/BIT2d.hpp\"\nusing namespace std;\n\n\
    // 2D Fenwick (BIT) tree\n// (1) Dense 2D: O(H*W) space, O(log H * log W) per\
    \ query\n// (2) Compressed 2D (offline): for point_add_rectangle_sum etc.\n\n\
    // --- Dense 2D BIT ---\ntemplate <class T = long long>\nstruct BIT2d {\n    int\
    \ h, w;\n    vector<vector<T>> fw;  // fw = Fenwick\n\n    BIT2d() = default;\n\
    \    BIT2d(int h, int w) : h(h), w(w), fw(h + 1, vector<T>(w + 1, 0)) {}\n\n \
    \   // add v to point (x, y)  1-indexed\n    void add(int x, int y, T v) {\n \
    \       for (int i = x; i <= h; i += i & -i)\n            for (int j = y; j <=\
    \ w; j += j & -j)\n                fw[i][j] += v;\n    }\n\n    // prefix sum\
    \ [1,x] x [1,y]  1-indexed\n    T sum(int x, int y) const {\n        T s = 0;\n\
    \        for (int i = x; i > 0; i -= i & -i)\n            for (int j = y; j >\
    \ 0; j -= j & -j)\n                s += fw[i][j];\n        return s;\n    }\n\n\
    \    // sum [lx,rx] x [ly,ry]  1-indexed inclusive\n    T sum(int lx, int rx,\
    \ int ly, int ry) const {\n        return sum(rx, ry) - sum(lx - 1, ry) - sum(rx,\
    \ ly - 1) + sum(lx - 1, ly - 1);\n    }\n};\n\n// --- Compressed 2D BIT (offline)\
    \ ---\n// For each x-coordinate, maintain a 1D Fenwick over y-coordinates actually\
    \ used.\n// O(Q log Q) time + space.\ntemplate <class T = long long>\nstruct BIT2d_compressed\
    \ {\n    int n;  // x-axis size\n    vector<vector<int>> ys;   // sorted y-coords\
    \ per x BIT node\n    vector<vector<T>>   fw;   // Fenwick values\n    bool built\
    \ = false;\n\n    BIT2d_compressed() = default;\n    BIT2d_compressed(int n) :\
    \ n(n), ys(n + 1), fw(n + 1) {}\n\n    // register point (x, y) before build \
    \ (1-indexed x)\n    void reserve(int x, int y) {\n        for (int i = x; i <=\
    \ n; i += i & -i) ys[i].push_back(y);\n    }\n\n    void build() {\n        for\
    \ (int i = 1; i <= n; i++) {\n            sort(ys[i].begin(), ys[i].end());\n\
    \            ys[i].erase(unique(ys[i].begin(), ys[i].end()), ys[i].end());\n \
    \           fw[i].assign(ys[i].size() + 1, 0);\n        }\n        built = true;\n\
    \    }\n\n    void _fw_add(int x, int y, T v) {\n        int j = (int)(lower_bound(ys[x].begin(),\
    \ ys[x].end(), y) - ys[x].begin()) + 1;\n        for (; j <= (int)ys[x].size();\
    \ j += j & -j) fw[x][j] += v;\n    }\n    T _fw_sum(int x, int y) const {\n  \
    \      int j = (int)(upper_bound(ys[x].begin(), ys[x].end(), y) - ys[x].begin());\n\
    \        T s = 0;\n        for (; j > 0; j -= j & -j) s += fw[x][j];\n       \
    \ return s;\n    }\n\n    void add(int x, int y, T v) {\n        for (int i =\
    \ x; i <= n; i += i & -i) _fw_add(i, y, v);\n    }\n\n    T sum(int x, int y)\
    \ const {\n        T s = 0;\n        for (int i = x; i > 0; i -= i & -i) s +=\
    \ _fw_sum(i, y);\n        return s;\n    }\n\n    T sum(int lx, int rx, int ly,\
    \ int ry) const {\n        return sum(rx, ry) - sum(lx - 1, ry) - sum(rx, ly -\
    \ 1) + sum(lx - 1, ly - 1);\n    }\n};\n#line 4 \"verify/library_checker_point_add_rectangle_sum.test.cpp\"\
    \n\nint main() {\n    IO();\n    int T = 1;\n    // cin >> T;\n    while (T--)\
    \ solve();\n}\n\nvoid solve() {\n    int n, q; cin >> n >> q;\n    struct point\
    \ {\n        int x, y;\n        ll w;\n    };\n    vec<point> ps(n);\n    vi xv;\n\
    \    range(i, ps) {\n        cin >> i.x >> i.y >> i.w;\n        xv.pb(i.x);\n\
    \    }\n    vec<array<int, 5>> queries(q);\n    range(i, queries) {\n        cin\
    \ >> i[0];\n        if (i[0] == 0) {\n            rep1(j, 3) cin >> i[j];\n  \
    \          xv.pb(i[1]);\n        }\n        else rep1(j, 4) cin >> i[j];\n   \
    \ }\n    uniq(xv);\n    int m = xv.size();\n    BIT2d_compressed<ll> seg(m);\n\
    \    rep(i, n) ps[i].x = (lower_bound(all(xv), ps[i].x)-xv.begin())+1;\n    rep(i,\
    \ q) queries[i][1] = (lower_bound(all(xv), queries[i][1]) - xv.begin()) + 1;\n\
    \    rep(i, q) if (queries[i][0] == 1) queries[i][2] = lower_bound(all(xv), queries[i][2])-xv.begin();\n\
    \    rep(i, n) seg.reserve(ps[i].x, ps[i].y);\n    seg.build();\n    range(i,\
    \ ps) seg.add(i.x, i.y, i.w);\n    range(i, queries) {\n        if (i[0] == 0)\
    \ seg.add(i[1], i[2], i[3]);\n        else cout << seg.sum(i[1], i[2], i[3], i[4]-1)\
    \ << nl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_rectangle_sum\"\
    \n#include \"template\"\n#include \"BIT2d\"\n\nint main() {\n    IO();\n    int\
    \ T = 1;\n    // cin >> T;\n    while (T--) solve();\n}\n\nvoid solve() {\n  \
    \  int n, q; cin >> n >> q;\n    struct point {\n        int x, y;\n        ll\
    \ w;\n    };\n    vec<point> ps(n);\n    vi xv;\n    range(i, ps) {\n        cin\
    \ >> i.x >> i.y >> i.w;\n        xv.pb(i.x);\n    }\n    vec<array<int, 5>> queries(q);\n\
    \    range(i, queries) {\n        cin >> i[0];\n        if (i[0] == 0) {\n   \
    \         rep1(j, 3) cin >> i[j];\n            xv.pb(i[1]);\n        }\n     \
    \   else rep1(j, 4) cin >> i[j];\n    }\n    uniq(xv);\n    int m = xv.size();\n\
    \    BIT2d_compressed<ll> seg(m);\n    rep(i, n) ps[i].x = (lower_bound(all(xv),\
    \ ps[i].x)-xv.begin())+1;\n    rep(i, q) queries[i][1] = (lower_bound(all(xv),\
    \ queries[i][1]) - xv.begin()) + 1;\n    rep(i, q) if (queries[i][0] == 1) queries[i][2]\
    \ = lower_bound(all(xv), queries[i][2])-xv.begin();\n    rep(i, n) seg.reserve(ps[i].x,\
    \ ps[i].y);\n    seg.build();\n    range(i, ps) seg.add(i.x, i.y, i.w);\n    range(i,\
    \ queries) {\n        if (i[0] == 0) seg.add(i[1], i[2], i[3]);\n        else\
    \ cout << seg.sum(i[1], i[2], i[3], i[4]-1) << nl;\n    }\n}\n"
  dependsOn:
  - utility/template.hpp
  - structure/BIT2d.hpp
  isVerificationFile: true
  path: verify/library_checker_point_add_rectangle_sum.test.cpp
  requiredBy: []
  timestamp: '2026-03-10 18:36:03+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/library_checker_point_add_rectangle_sum.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker_point_add_rectangle_sum.test.cpp
- /verify/verify/library_checker_point_add_rectangle_sum.test.cpp.html
title: verify/library_checker_point_add_rectangle_sum.test.cpp
---
