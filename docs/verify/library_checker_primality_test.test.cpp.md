---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/prime.hpp
    title: math/prime.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/primality_test
    links:
    - https://judge.yosupo.jp/problem/primality_test
  bundledCode: "#line 1 \"verify/library_checker_primality_test.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/primality_test\"\n#line 2 \"utility/template.hpp\"\
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
    }\n\nvoid solve();\n\n#line 3 \"math/prime.hpp\"\nusing namespace std;\n\n// ===========================================================\n\
    //  prime.hpp  --  primality, enumeration, factorization\n// ===========================================================\n\
    //\n//  is_prime(n)       : 64bit \u6C7A\u5B9A\u8AD6\u7684 Miller-Rabin \u7D20\
    \u6570\u5224\u5B9A\n//  enumprimes(n)     : n \u4EE5\u4E0B\u306E\u7D20\u6570\u5217\
    \u6319  Wheel Sieve mod 30\n//                      O(n / loglog n)\n//  factorize(n)\
    \      : Pollard's rho + Miller-Rabin \u7D20\u56E0\u6570\u5206\u89E3\n//     \
    \                 \u8FD4\u308A\u5024: \u30BD\u30FC\u30C8\u6E08\u307F\u7D20\u56E0\
    \u6570\u30EA\u30B9\u30C8 (\u91CD\u8907\u3042\u308A)\n// ===========================================================\n\
    \nnamespace _prime_detail {\n    using u64  = unsigned long long;\n    using u128\
    \ = unsigned __int128;\n\n    inline u64 mulmod(u64 a, u64 b, u64 m) {\n     \
    \   return (u128)a * b % m;\n    }\n    inline u64 powmod(u64 a, u64 n, u64 m)\
    \ {\n        u64 r = 1 % m; a %= m;\n        for (; n; n >>= 1, a = mulmod(a,\
    \ a, m))\n            if (n & 1) r = mulmod(r, a, m);\n        return r;\n   \
    \ }\n    // Miller-Rabin: 1 \u56DE\u306E witness \u30C1\u30A7\u30C3\u30AF\n  \
    \  inline bool witness(u64 a, u64 n, u64 d, int s) {\n        u64 x = powmod(a,\
    \ d, n);\n        if (x == 1 || x == n - 1) return true;\n        for (int i =\
    \ 0; i < s - 1; i++) {\n            x = mulmod(x, x, n);\n            if (x ==\
    \ n - 1) return true;\n        }\n        return false;\n    }\n    inline mt19937_64&\
    \ rng() {\n        static mt19937_64 r(chrono::steady_clock::now().time_since_epoch().count());\n\
    \        return r;\n    }\n    // Pollard's rho: n \u306E\u975E\u81EA\u660E\u56E0\
    \u5B50\u3092 1 \u3064\u8FD4\u3059\u3002\u5931\u6557\u6642\u306F 0\n    inline\
    \ u64 rho_step(u64 n) {\n        if (n % 2 == 0) return 2;\n        u64 x = rng()()\
    \ % (n - 2) + 2;\n        u64 y = x;\n        u64 c = rng()() % (n - 1) + 1;\n\
    \        u64 d = 1;\n        while (d == 1) {\n            x = (mulmod(x, x, n)\
    \ + c) % n;\n            y = (mulmod(y, y, n) + c) % n;\n            y = (mulmod(y,\
    \ y, n) + c) % n;\n            d = __gcd(x < y ? y - x : x - y, n);\n        }\n\
    \        return d == n ? 0 : d;\n    }\n} // namespace _prime_detail\n\n// -----------------------------------------------------------\n\
    //  is_prime  --  \u6C7A\u5B9A\u8AD6\u7684 Miller-Rabin\n//  witnesses {2,3,5,...,37}\
    \ \u3067 64bit \u5168\u57DF\u3092\u6B63\u78BA\u306B\u5224\u5B9A\n// -----------------------------------------------------------\n\
    bool is_prime(unsigned long long n) {\n    using namespace _prime_detail;\n  \
    \  if (n < 2) return false;\n    for (u64 p : {2ULL,3ULL,5ULL,7ULL,11ULL,13ULL,17ULL,19ULL,23ULL})\n\
    \        if (n == p) return true;\n        else if (n % p == 0) return false;\n\
    \    u64 d = n - 1; int s = 0;\n    while (d % 2 == 0) { d >>= 1; s++; }\n   \
    \ for (u64 a : {2ULL,3ULL,5ULL,7ULL,11ULL,13ULL,17ULL,19ULL,23ULL,29ULL,31ULL,37ULL})\n\
    \        if (a < n && !witness(a, n, d, s)) return false;\n    return true;\n\
    }\n\n// -----------------------------------------------------------\n//  enumprimes\
    \  --  Wheel Sieve (mod 30)  O(n / loglog n)\n//\n//  mod 30 \u306E wheel: 2\xD7\
    3\xD75 = 30 \u306E\u500D\u6570\u3092\u9664\u3044\u305F 8 \u6B8B\u5DEE\n//  {1,7,11,13,17,19,23,29}\
    \ \u306E\u307F\u3092\u7BA1\u7406\u3057\u5B9A\u6570\u500D\u3092\u524A\u6E1B\n//\
    \ -----------------------------------------------------------\nvector<int> enumprimes(int\
    \ n) {\n    vector<int> primes;\n    for (int p : {2, 3, 5}) if (p <= n) primes.push_back(p);\n\
    \    if (n < 7) return primes;\n\n    // wheel residues & reverse map\n    static\
    \ const int res[8]   = {1, 7, 11, 13, 17, 19, 23, 29};\n    static const int ridx[30]\
    \ = {\n        -1, 0,-1,-1,-1,-1,-1, 1,-1,-1,\n        -1, 2,-1, 3,-1,-1,-1, 4,-1,\
    \ 5,\n        -1,-1,-1, 6,-1,-1,-1,-1,-1, 7\n    };\n    const int W = 30;\n \
    \   int sz = n / W + 2;\n    // comp[k] : \u30D3\u30C3\u30C8 j \u304C\u7ACB\u3064\
    \ \u27FA (30k + res[j]) \u304C\u5408\u6210\u6570\n    vector<uint8_t> comp(sz,\
    \ 0);\n\n    for (int k = 0; (long long)k * W + 1 <= n; k++) {\n        for (int\
    \ j = 0; j < 8; j++) {\n            long long p = (long long)k * W + res[j];\n\
    \            if (p < 7)  continue;\n            if (p > n)  break;\n         \
    \   if ((comp[k] >> j) & 1) continue;   // \u5408\u6210\u6570\u306F\u30B9\u30AD\
    \u30C3\u30D7\n            primes.push_back((int)p);\n            // p \u306E\u500D\
    \u6570 p*m \u3092\u7BE9\u3046 (m >= p, m \u306F 30 \u3068\u4E92\u3044\u306B\u7D20\
    )\n            // p*m \u3082 30 \u3068\u4E92\u3044\u306B\u7D20 \u27F9 ridx \u306F\
    \u5E38\u306B\u6709\u52B9\n            for (int mk = k, mj = j;;) {\n         \
    \       long long pm = p * ((long long)mk * W + res[mj]);\n                if\
    \ (pm > n) break;\n                comp[pm / W] |= (uint8_t)(1u << ridx[(res[j]\
    \ * res[mj]) % W]);\n                if (++mj == 8) { mj = 0; mk++; }\n      \
    \      }\n        }\n    }\n    return primes;\n}\n\n// -----------------------------------------------------------\n\
    //  factorize  --  Pollard's rho + Miller-Rabin\n//  \u8FD4\u308A\u5024: \u30BD\
    \u30FC\u30C8\u6E08\u307F\u7D20\u56E0\u6570\u30EA\u30B9\u30C8 (\u91CD\u8907\u3042\
    \u308A)\n//  \u4F8B: factorize(12) => {2, 2, 3}\n// -----------------------------------------------------------\n\
    vector<long long> factorize(long long n) {\n    using namespace _prime_detail;\n\
    \    using u64 = unsigned long long;\n    if (n <= 1) return {};\n    if (is_prime((u64)n))\
    \ return {n};\n    u64 d = 0;\n    while (!d) d = rho_step((u64)n);\n    auto\
    \ a = factorize((long long)d);\n    auto b = factorize(n / (long long)d);\n  \
    \  for (auto x : b) a.push_back(x);\n    sort(a.begin(), a.end());\n    return\
    \ a;\n}\n#line 4 \"verify/library_checker_primality_test.test.cpp\"\n\nint main()\
    \ {\n    IO();\n    int T = 1;\n    while (T--) solve();\n}\n\nvoid solve() {\n\
    \    int q; cin >> q;\n    rep(q) {\n        ull n; cin >> n;\n        cout <<\
    \ (is_prime(n) ? \"Yes\" : \"No\") << nl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/primality_test\"\n#include\
    \ \"template\"\n#include \"prime\"\n\nint main() {\n    IO();\n    int T = 1;\n\
    \    while (T--) solve();\n}\n\nvoid solve() {\n    int q; cin >> q;\n    rep(q)\
    \ {\n        ull n; cin >> n;\n        cout << (is_prime(n) ? \"Yes\" : \"No\"\
    ) << nl;\n    }\n}\n"
  dependsOn:
  - utility/template.hpp
  - math/prime.hpp
  isVerificationFile: true
  path: verify/library_checker_primality_test.test.cpp
  requiredBy: []
  timestamp: '2026-03-09 22:49:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker_primality_test.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker_primality_test.test.cpp
- /verify/verify/library_checker_primality_test.test.cpp.html
title: verify/library_checker_primality_test.test.cpp
---
