---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: structure/bipq.hpp
    title: structure/bipq.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/double_ended_priority_queue
    links:
    - https://judge.yosupo.jp/problem/double_ended_priority_queue
  bundledCode: "#line 1 \"verify/library_checker_double_ended_priority_queue.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/double_ended_priority_queue\"\
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
    }\n\nvoid solve();\n\n#line 3 \"structure/bipq.hpp\"\nusing namespace std;\n\n\
    // Double-Ended Priority Queue using Interval Heap.\n// Each node stores an interval\
    \ [lo, hi] with lo <= hi.\n// Invariants (over parent-child pairs):\n//   parent.lo\
    \ <= child.lo   (min-heap on lo)\n//   parent.hi >= child.hi   (max-heap on hi)\n\
    // Thus root holds the global minimum (lo) and maximum (hi).\n//\n// Complexity:\
    \ push / pop_min / pop_max in O(log n), top_min / top_max in O(1).\n// Template\
    \ parameter Compare: cmp(a, b) == true iff a is strictly less than b.\ntemplate\
    \ <class T, class Compare = less<T>>\nstruct bipq {\nprivate:\n    vector<pair<T,\
    \ T>> h;  // h[i] = {lo, hi}\n    int _sz = 0;\n    [[no_unique_address]] Compare\
    \ cmp;\n\n    // For the partial last node (_sz odd), only h.back().first is valid.\n\
    \    // hi_ref / hi_val transparently handle this.\n    T& hi_ref(int i) noexcept\
    \ {\n        return (i == (int)h.size() - 1 && _sz % 2 == 1) ? h[i].first : h[i].second;\n\
    \    }\n    const T& hi_val(int i) const noexcept {\n        return (i == (int)h.size()\
    \ - 1 && _sz % 2 == 1) ? h[i].first : h[i].second;\n    }\n\n    void sift_up_min(int\
    \ i) {\n        while (i > 0) {\n            int p = (i - 1) / 2;\n          \
    \  if (cmp(h[i].first, h[p].first)) {\n                swap(h[i].first, h[p].first);\n\
    \                i = p;\n            } else break;\n        }\n    }\n\n    void\
    \ sift_up_max(int i) {\n        while (i > 0) {\n            int p = (i - 1) /\
    \ 2;\n            if (cmp(h[p].second, hi_val(i))) {\n                swap(hi_ref(i),\
    \ h[p].second);\n                i = p;\n            } else break;\n        }\n\
    \    }\n\n    void sift_down_min(int i) {\n        int n = (int)h.size();\n  \
    \      while (true) {\n            int c = 2 * i + 1;\n            if (c >= n)\
    \ break;\n            if (c + 1 < n && cmp(h[c + 1].first, h[c].first)) c++;\n\
    \            if (cmp(h[c].first, h[i].first)) {\n                swap(h[i].first,\
    \ h[c].first);\n                // Restore lo <= hi within node c\n          \
    \      if (cmp(hi_val(c), h[c].first)) swap(h[c].first, hi_ref(c));\n        \
    \        i = c;\n            } else break;\n        }\n    }\n\n    void sift_down_max(int\
    \ i) {\n        int n = (int)h.size();\n        while (true) {\n            int\
    \ c = 2 * i + 1;\n            if (c >= n) break;\n            if (c + 1 < n &&\
    \ cmp(hi_val(c), hi_val(c + 1))) c++;\n            if (cmp(h[i].second, hi_val(c)))\
    \ {\n                swap(hi_ref(c), h[i].second);\n                // Restore\
    \ lo <= hi within node c\n                if (cmp(hi_val(c), h[c].first)) swap(h[c].first,\
    \ hi_ref(c));\n                i = c;\n            } else break;\n        }\n\
    \    }\n\npublic:\n    bipq() = default;\n    explicit bipq(Compare c) : cmp(c)\
    \ {}\n    template <class Iter>\n    bipq(Iter first, Iter last) { for (auto it\
    \ = first; it != last; ++it) push(*it); }\n    bipq(initializer_list<T> il) :\
    \ bipq(il.begin(), il.end()) {}\n\n    int  size()  const noexcept { return _sz;\
    \ }\n    bool empty() const noexcept { return _sz == 0; }\n\n    // Minimum element\
    \ (undefined if empty)\n    const T& top_min() const {\n        assert(_sz > 0);\n\
    \        return h[0].first;\n    }\n\n    // Maximum element (undefined if empty)\n\
    \    const T& top_max() const {\n        assert(_sz > 0);\n        return hi_val(0);\n\
    \    }\n\n    void push(const T& x) {\n        if (_sz % 2 == 0) {\n         \
    \   // Start a new (partial) leaf node\n            h.push_back({x, x});\n   \
    \         _sz++;\n            int i = (int)h.size() - 1;\n            sift_up_min(i);\n\
    \            sift_up_max(i);\n        } else {\n            // Complete the last\
    \ partial node\n            int i = (int)h.size() - 1;\n            if (cmp(x,\
    \ h[i].first)) {\n                h[i].second = h[i].first;\n                h[i].first\
    \  = x;\n            } else {\n                h[i].second = x;\n            }\n\
    \            _sz++;\n            sift_up_min(i);\n            sift_up_max(i);\n\
    \        }\n    }\n\n    void pop_min() {\n        assert(_sz > 0);\n        if\
    \ (_sz == 1) { h.pop_back(); _sz = 0; return; }\n        if (_sz == 2) { h[0].first\
    \ = h[0].second; _sz = 1; return; }\n\n        int last = (int)h.size() - 1;\n\
    \        T x;\n        if (_sz % 2 == 1) {\n            // Last node is partial:\
    \ take its only element and remove the node\n            x = h[last].first;\n\
    \            h.pop_back();\n        } else {\n            // Last node is full:\
    \ take hi, leaving it partial (handled by _sz--)\n            x = h[last].second;\n\
    \        }\n        _sz--;\n\n        h[0].first = x;\n        // Restore lo <=\
    \ hi at root if needed\n        if (cmp(h[0].second, h[0].first)) swap(h[0].first,\
    \ h[0].second);\n        sift_down_min(0);\n    }\n\n    void pop_max() {\n  \
    \      assert(_sz > 0);\n        if (_sz == 1) { h.pop_back(); _sz = 0; return;\
    \ }\n        if (_sz == 2) { _sz = 1; return; }  // only h[0].first remains\n\n\
    \        int last = (int)h.size() - 1;\n        T x;\n        if (_sz % 2 == 1)\
    \ {\n            x = h[last].first;\n            h.pop_back();\n        } else\
    \ {\n            x = h[last].second;\n        }\n        _sz--;\n\n        h[0].second\
    \ = x;\n        if (cmp(h[0].second, h[0].first)) swap(h[0].first, h[0].second);\n\
    \        sift_down_max(0);\n    }\n};\n#line 4 \"verify/library_checker_double_ended_priority_queue.test.cpp\"\
    \n\nvoid solve() {\n    int n, q;\n    cin >> n >> q;\n\n    bipq<int> pq;\n \
    \   rep(n) {\n        int x; cin >> x;\n        pq.push(x);\n    }\n\n    rep(q)\
    \ {\n        int t; cin >> t;\n        if (t == 0) {\n            int x; cin >>\
    \ x;\n            pq.push(x);\n        } else if (t == 1) {\n            cout\
    \ << pq.top_min() << nl;\n            pq.pop_min();\n        } else {\n      \
    \      cout << pq.top_max() << nl;\n            pq.pop_max();\n        }\n   \
    \ }\n}\n\nint main() {\n    IO();\n    int T = 1;\n    while (T--) solve();\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/double_ended_priority_queue\"\
    \n#include \"template\"\n#include \"bipq\"\n\nvoid solve() {\n    int n, q;\n\
    \    cin >> n >> q;\n\n    bipq<int> pq;\n    rep(n) {\n        int x; cin >>\
    \ x;\n        pq.push(x);\n    }\n\n    rep(q) {\n        int t; cin >> t;\n \
    \       if (t == 0) {\n            int x; cin >> x;\n            pq.push(x);\n\
    \        } else if (t == 1) {\n            cout << pq.top_min() << nl;\n     \
    \       pq.pop_min();\n        } else {\n            cout << pq.top_max() << nl;\n\
    \            pq.pop_max();\n        }\n    }\n}\n\nint main() {\n    IO();\n \
    \   int T = 1;\n    while (T--) solve();\n}\n"
  dependsOn:
  - utility/template.hpp
  - structure/bipq.hpp
  isVerificationFile: true
  path: verify/library_checker_double_ended_priority_queue.test.cpp
  requiredBy: []
  timestamp: '2026-03-10 11:48:32+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker_double_ended_priority_queue.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker_double_ended_priority_queue.test.cpp
- /verify/verify/library_checker_double_ended_priority_queue.test.cpp.html
title: verify/library_checker_double_ended_priority_queue.test.cpp
---
