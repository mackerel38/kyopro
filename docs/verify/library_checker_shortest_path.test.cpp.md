---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/dijkstra.hpp
    title: graph/dijkstra.hpp
  - icon: ':heavy_check_mark:'
    path: graph/graphtemplate.hpp
    title: graph/graphtemplate.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/shortest_path
    links:
    - https://judge.yosupo.jp/problem/shortest_path
  bundledCode: "#line 1 \"verify/library_checker_shortest_path.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n#line 2 \"utility/template.hpp\"\
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
    }\n\nvoid solve();\n\n#line 3 \"graph/graphtemplate.hpp\"\nusing namespace std;\n\
    // \u8FBA\u306E\u69CB\u9020\u4F53 edge(from, to, cost, id)\ntemplate<class T =\
    \ int>\nstruct edge {\n    int from, to;\n    T cost;\n    int id;\n};\n// \u9802\
    \u70B9\u306E\u69CB\u9020\u4F53 vector<edge<T>>\ntemplate<class T = int>\nusing\
    \ edges = vector<edge<T>>;\n// \u30B0\u30E9\u30D5\u306E\u69CB\u9020\u4F53 graph<T,\
    \ directed, weighted>\ntemplate <class T = int, bool directed = false, bool weighted\
    \ = false>\nstruct graph {\n    bool isdirected, isweighted;\n    edges<T> _edges;\n\
    \    vector<edges<T>> data;\n    T sumcost;\n    graph() = default;\n    // \u9802\
    \u70B9\u6570 n \u306E\u30B0\u30E9\u30D5\u3092\u4F5C\u6210\u3059\u308B\n    graph(int\
    \ n) : isdirected(directed), isweighted(weighted), data(n), sumcost(T{}) {}\n\
    \    // from \u304B\u3089 to \u3078\u8FBA\u3092\u8FFD\u52A0\u3059\u308B\n    void\
    \ add_edge(int from, int to, T cost = 1, int id = -1) {\n        if (id == -1)\
    \ id = _edges.size();\n        data[from].push_back(edge<T>{from, to, cost, id});\n\
    \        _edges.push_back(edge<T>{from, to, cost, id});\n        if (!isdirected)\
    \ {\n            data[to].push_back(edge<T>{to, from, cost, id});\n        }\n\
    \        sumcost += cost;\n    }\n    // \u8FBA\u3092\u8FFD\u52A0\u3059\u308B\n\
    \    void add_edge(edge<T> _e) {\n        add_edge(_e.from, _e.to, _e.cost, _e.id);\n\
    \    }\n    // \u6A19\u6E96\u5165\u529B\u304B\u3089\u8FBA\u3092\u8AAD\u307F\u8FBC\
    \u3080\n    void read(int m, int indexed = 1) {\n        for (int i=0; i<m; i++)\
    \ {\n            int from, to;\n            T cost = 1;\n            cin >> from\
    \ >> to;\n            if (isweighted) cin >> cost;\n            add_edge(from\
    \ - indexed, to - indexed, cost);\n        }\n    }\n    // \u9802\u70B9\u6570\
    \u3092\u8FD4\u3059\n    int size() {\n        return data.size();\n    }\n   \
    \ // \u9802\u70B9\u3092\u8FD4\u3059\n    edges<T> operator[](int k) {\n      \
    \  return data[k];\n    }\n    // \u30D1\u30B9\u3092\u9802\u70B9\u306B\u5909\u63DB\
    \u3059\u308B\n    vector<int> path_to_vertex(edges<T>& _e) {\n        vector<int>\
    \ re;\n        if (_e.size() == 0) {\n            return re;\n        }\n    \
    \    if (_e.size() == 1) {\n            re.push_back(_e[0].from);\n          \
    \  re.push_back(_e[0].to);\n            return re;\n        }\n        int x=_e[0].from,y=_e[0].to;\n\
    \        if (x==_e[1].to || x == _e[1].from) swap(x, y);\n        re.push_back(x);\n\
    \        for (int i=1; i<(int)_e.size(); i++) {\n            re.push_back(y);\n\
    \            x = _e[i].to;\n            if (x == y) x = _e[i].from;\n        \
    \    swap(x, y);\n        }\n        return re;\n    }\n    // \u9802\u70B9\u3092\
    \u30D1\u30B9\u306B\u5909\u63DB\u3059\u308B\n    edges<T> vertex_to_path(vector<int>&\
    \ v) {\n        edges<T> re;\n        for (int i=0; i+1<(int)v.size(); i++) {\n\
    \            for (auto& _e : data[v[i]]) {\n                if (_e.to == v[i+1])\
    \ {\n                    re.push_back(_e);\n                    break;\n     \
    \           }\n            }\n        }\n        return re;\n    }\n};\n#line\
    \ 3 \"graph/dijkstra.hpp\"\n\n// Dijkstra: returns shortest distances from src\n\
    // Use: graph<T, directed, true> (weighted=true)\ntemplate <class T, bool directed>\n\
    vector<T> dijkstra(graph<T, directed, true>& g, int src) {\n    int n = g.size();\n\
    \    const T INF = numeric_limits<T>::max() / 2;\n    vector<T> dist(n, INF);\n\
    \    priority_queue<pair<T,int>, vector<pair<T,int>>, greater<pair<T,int>>> pq;\n\
    \    dist[src] = T{};\n    pq.push({T{}, src});\n    while (!pq.empty()) {\n \
    \       auto [d, v] = pq.top(); pq.pop();\n        if (dist[v] < d) continue;\n\
    \        for (auto& e : g[v]) {\n            if (dist[v] + e.cost < dist[e.to])\
    \ {\n                dist[e.to] = dist[v] + e.cost;\n                pq.push({dist[e.to],\
    \ e.to});\n            }\n        }\n    }\n    return dist;\n}\n\n// Dijkstra\
    \ with prev edge for path reconstruction\ntemplate <class T, bool directed>\n\
    pair<vector<T>, vector<int>> dijkstra_prev(graph<T, directed, true>& g, int src)\
    \ {\n    int n = g.size();\n    const T INF = numeric_limits<T>::max() / 2;\n\
    \    vector<T> dist(n, INF);\n    vector<int> prev(n, -1);\n    priority_queue<pair<T,int>,\
    \ vector<pair<T,int>>, greater<pair<T,int>>> pq;\n    dist[src] = T{};\n    pq.push({T{},\
    \ src});\n    while (!pq.empty()) {\n        auto [d, v] = pq.top(); pq.pop();\n\
    \        if (dist[v] < d) continue;\n        for (auto& e : g[v]) {\n        \
    \    if (dist[v] + e.cost < dist[e.to]) {\n                dist[e.to] = dist[v]\
    \ + e.cost;\n                prev[e.to] = v;\n                pq.push({dist[e.to],\
    \ e.to});\n            }\n        }\n    }\n    return {dist, prev};\n}\n\n//\
    \ Restore path from src to dst using prev array\nvector<int> restore_path(const\
    \ vector<int>& prev, int dst) {\n    vector<int> path;\n    for (int v = dst;\
    \ v != -1; v = prev[v]) path.push_back(v);\n    reverse(path.begin(), path.end());\n\
    \    return path;\n}\n#line 4 \"verify/library_checker_shortest_path.test.cpp\"\
    \n\nint main() {\n    IO();\n    int T = 1;\n    while (T--) solve();\n}\n\nvoid\
    \ solve() {\n    int n, m, s, t; cin >> n >> m >> s >> t;\n    graph<ll, true,\
    \ true> g(n);\n    g.read(m, 0);\n    auto [dist, prev] = dijkstra_prev(g, s);\n\
    \    const ll INF = numeric_limits<ll>::max() / 2;\n    if (dist[t] >= INF) {\n\
    \        cout << -1 << nl;\n        return;\n    }\n    auto path = restore_path(prev,\
    \ t);\n    cout << dist[t] << sp << (int)path.size() - 1 << nl;\n    rep(i, (int)path.size()\
    \ - 1) {\n        cout << path[i] << sp << path[i + 1] << nl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n#include\
    \ \"template\"\n#include \"dijkstra\"\n\nint main() {\n    IO();\n    int T =\
    \ 1;\n    while (T--) solve();\n}\n\nvoid solve() {\n    int n, m, s, t; cin >>\
    \ n >> m >> s >> t;\n    graph<ll, true, true> g(n);\n    g.read(m, 0);\n    auto\
    \ [dist, prev] = dijkstra_prev(g, s);\n    const ll INF = numeric_limits<ll>::max()\
    \ / 2;\n    if (dist[t] >= INF) {\n        cout << -1 << nl;\n        return;\n\
    \    }\n    auto path = restore_path(prev, t);\n    cout << dist[t] << sp << (int)path.size()\
    \ - 1 << nl;\n    rep(i, (int)path.size() - 1) {\n        cout << path[i] << sp\
    \ << path[i + 1] << nl;\n    }\n}\n"
  dependsOn:
  - utility/template.hpp
  - graph/dijkstra.hpp
  - graph/graphtemplate.hpp
  isVerificationFile: true
  path: verify/library_checker_shortest_path.test.cpp
  requiredBy: []
  timestamp: '2026-03-09 22:49:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker_shortest_path.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker_shortest_path.test.cpp
- /verify/verify/library_checker_shortest_path.test.cpp.html
title: verify/library_checker_shortest_path.test.cpp
---
