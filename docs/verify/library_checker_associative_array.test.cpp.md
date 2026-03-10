---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: utility/hashmap.hpp
    title: utility/hashmap.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/associative_array
    links:
    - https://judge.yosupo.jp/problem/associative_array
  bundledCode: "#line 1 \"verify/library_checker_associative_array.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/associative_array\"\n#line 2 \"utility/template.hpp\"\
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
    }\n\nvoid solve();\n\n#line 3 \"utility/hashmap.hpp\"\nusing namespace std;\n\n\
    // HashMap  --  open-addressing hash map with runtime-random hash\n// ~3-4x faster\
    \ than std::unordered_map\n// Key: any integral type, or pair<integral, integral>\n\
    // Reference: https://nyaannyaan.github.io/library/hashmap/hashmap.hpp\n\nnamespace\
    \ _hm {\nusing u32 = uint32_t;\nusing u64 = uint64_t;\n\ninline u64 _seed() {\n\
    \    static const u64 r = chrono::duration_cast<chrono::nanoseconds>(\n      \
    \  chrono::high_resolution_clock::now().time_since_epoch()).count();\n    return\
    \ r;\n}\n\ntemplate <class Key, class Data>\nstruct hashmap_base {\n    using\
    \ u32 = uint32_t;\n    using u64 = uint64_t;\n    static constexpr u32 DS = 4;\
    \ // default size\n\n    u32 cap, s, occ, shift;\n    vector<Data> data;\n   \
    \ vector<bool> used, del;\n\n    explicit hashmap_base()\n        : cap(DS), s(0),\
    \ occ(0), shift(64 - __lg(DS)),\n          data(DS), used(DS, false), del(DS,\
    \ false) {}\n\n    // --- hash ---\n    template <class K>\n    enable_if_t<is_integral_v<K>,\
    \ u32> inner_hash(K k) const {\n        return (u64(k) ^ _seed()) * 11995408973635179863ULL\
    \ >> shift;\n    }\n    template <class K>\n    auto inner_hash(K k) const\n \
    \       -> enable_if_t<is_integral_v<decltype(k.first)>, u32> {\n        u64 a\
    \ = (u64(k.first)  ^ _seed()) * 11995408973635179863ULL;\n        u64 b = (u64(k.second)\
    \ ^ _seed()) * 10150724397891781847ULL;\n        return (a + b) >> shift;\n  \
    \  }\n    template <class D = Data>\n    enable_if_t<is_same_v<D, Key>, u32> hash_d(const\
    \ D& d) const {\n        return inner_hash(d);\n    }\n    template <class D =\
    \ Data>\n    enable_if_t<!is_same_v<D, Key>, u32> hash_d(const D& d) const {\n\
    \        return inner_hash(d.first);\n    }\n    template <class D = Data>\n \
    \   enable_if_t<is_same_v<D, Key>, Key> key_of(const D& d) const { return d; }\n\
    \    template <class D = Data>\n    enable_if_t<!is_same_v<D, Key>, Key> key_of(const\
    \ D& d) const { return d.first; }\n\n    // --- iterator ---\n    struct iterator\
    \ {\n        u32 i; hashmap_base* p;\n        Data& operator*()  const { return\
    \ p->data[i]; }\n        Data* operator->() const { return &p->data[i]; }\n  \
    \      bool operator==(const iterator& o) const { return i == o.i; }\n       \
    \ bool operator!=(const iterator& o) const { return i != o.i; }\n        iterator&\
    \ operator++() {\n            do { ++i; } while (i < p->cap && !(p->used[i] &&\
    \ !p->del[i]));\n            return *this;\n        }\n    };\n    iterator begin()\
    \ {\n        u32 h = 0;\n        while (h < cap && !(used[h] && !del[h])) ++h;\n\
    \        return {h, this};\n    }\n    iterator end() { return {cap, this}; }\n\
    \n    // --- resize ---\n    bool _ext(u32 x) const { return x * 2 >= cap; }\n\
    \    bool _shr(u32 x) const { return DS < cap && x * 10 <= cap; }\n    void reallocate(u32\
    \ nc) {\n        shift = 64 - __lg(nc);\n        vector<Data> nd(nc); vector<bool>\
    \ nf(nc);\n        for (u32 i = 0; i < cap; i++) {\n            if (used[i] &&\
    \ !del[i]) {\n                u32 h = hash_d(data[i]);\n                while\
    \ (nf[h]) h = (h + 1) & (nc - 1);\n                nd[h] = move(data[i]); nf[h]\
    \ = true;\n            }\n        }\n        data.swap(nd); used.swap(nf);\n \
    \       cap = nc; occ = s;\n        del.assign(cap, false);\n    }\n    void extend()\
    \ { reallocate(cap << 1); }\n    void shrink() { reallocate(cap >> 1); }\n\n \
    \   // --- public ---\n    iterator find(const Key& k) {\n        u32 h = inner_hash(k);\n\
    \        while (true) {\n            if (!used[h]) return end();\n           \
    \ if (key_of(data[h]) == k && !del[h]) return {h, this};\n            h = (h +\
    \ 1) & (cap - 1);\n        }\n    }\n    bool contains(const Key& k) { return\
    \ find(k) != end(); }\n\n    iterator insert(const Data& d) {\n        u32 h =\
    \ hash_d(d);\n        while (true) {\n            if (!used[h]) {\n          \
    \      if (_ext(occ + 1)) { extend(); h = hash_d(d); continue; }\n           \
    \     data[h] = d; used[h] = true; ++occ; ++s;\n                return {h, this};\n\
    \            }\n            if (key_of(data[h]) == key_of(d)) {\n            \
    \    if (del[h]) { data[h] = d; del[h] = false; ++s; }\n                return\
    \ {h, this};\n            }\n            h = (h + 1) & (cap - 1);\n        }\n\
    \    }\n    iterator erase(iterator it) {\n        if (it == end()) return end();\n\
    \        del[it.i] = true; --s;\n        iterator nxt = it; ++nxt;\n        if\
    \ (_shr(s)) { Data d = data[nxt.i]; shrink(); nxt = find(key_of(d)); }\n     \
    \   return nxt;\n    }\n    iterator erase(const Key& k) { return erase(find(k));\
    \ }\n    bool  empty() const { return s == 0; }\n    int   size()  const { return\
    \ (int)s; }\n    void  clear() {\n        fill(used.begin(), used.end(), false);\n\
    \        fill(del.begin(),  del.end(),  false);\n        s = occ = 0;\n    }\n\
    \    void reserve(int n) {\n        if (n <= 0) return;\n        u32 nc = DS;\n\
    \        while ((int)nc < n * 2) nc <<= 1;\n        if (cap < nc) reallocate(nc);\n\
    \    }\n    friend iterator begin(hashmap_base& h) { return h.begin(); }\n   \
    \ friend iterator end  (hashmap_base& h) { return h.end(); }\n};\n} // namespace\
    \ _hm\n\n// hashmap<Key, Val>  --  unordered_map equivalent\ntemplate <class Key,\
    \ class Val>\nstruct hashmap : _hm::hashmap_base<Key, pair<Key, Val>> {\n    using\
    \ base = _hm::hashmap_base<Key, pair<Key, Val>>;\n    using base::base;\n    Val&\
    \ operator[](const Key& k) {\n        typename base::u32 h = base::inner_hash(k);\n\
    \        while (true) {\n            if (!base::used[h]) {\n                if\
    \ (base::_ext(base::occ + 1)) { base::extend(); h = base::inner_hash(k); continue;\
    \ }\n                base::data[h] = {k, Val{}};\n                base::used[h]\
    \ = true; ++base::occ; ++base::s;\n                return base::data[h].second;\n\
    \            }\n            if (base::data[h].first == k) {\n                if\
    \ (base::del[h]) { base::data[h].second = Val{}; base::del[h] = false; ++base::s;\
    \ }\n                return base::data[h].second;\n            }\n           \
    \ h = (h + 1) & (base::cap - 1);\n        }\n    }\n    typename base::iterator\
    \ emplace(const Key& k, const Val& v) {\n        return base::insert({k, v});\n\
    \    }\n};\n#line 4 \"verify/library_checker_associative_array.test.cpp\"\n\n\
    int main() {\n    IO();\n    int T = 1;\n    // cin >> T;\n    while (T--) solve();\n\
    }\n\nvoid solve() {\n    hashmap<ll, ll> hm;\n    int q; cin >> q;\n    rep(q)\
    \ {\n        int t; cin >> t;\n        if (t == 0) {\n            ll k, v; cin\
    \ >> k >> v;\n            hm[k] = v;\n        } else {\n            ll k; cin\
    \ >> k;\n            cout << hm[k] << nl;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/associative_array\"\n#include\
    \ \"template\"\n#include \"hashmap\"\n\nint main() {\n    IO();\n    int T = 1;\n\
    \    // cin >> T;\n    while (T--) solve();\n}\n\nvoid solve() {\n    hashmap<ll,\
    \ ll> hm;\n    int q; cin >> q;\n    rep(q) {\n        int t; cin >> t;\n    \
    \    if (t == 0) {\n            ll k, v; cin >> k >> v;\n            hm[k] = v;\n\
    \        } else {\n            ll k; cin >> k;\n            cout << hm[k] << nl;\n\
    \        }\n    }\n}\n"
  dependsOn:
  - utility/template.hpp
  - utility/hashmap.hpp
  isVerificationFile: true
  path: verify/library_checker_associative_array.test.cpp
  requiredBy: []
  timestamp: '2026-03-10 18:35:47+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker_associative_array.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker_associative_array.test.cpp
- /verify/verify/library_checker_associative_array.test.cpp.html
title: verify/library_checker_associative_array.test.cpp
---
