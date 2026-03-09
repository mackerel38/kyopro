---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker_associative_array.test.cpp
    title: verify/library_checker_associative_array.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://nyaannyaan.github.io/library/hashmap/hashmap.hpp
  bundledCode: "#line 2 \"utility/hashmap.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n// HashMap  --  open-addressing hash map with runtime-random hash\n\
    // ~3-4x faster than std::unordered_map\n// Key: any integral type, or pair<integral,\
    \ integral>\n// Reference: https://nyaannyaan.github.io/library/hashmap/hashmap.hpp\n\
    \nnamespace _hm {\nusing u32 = uint32_t;\nusing u64 = uint64_t;\n\ninline u64\
    \ _seed() {\n    static const u64 r = chrono::duration_cast<chrono::nanoseconds>(\n\
    \        chrono::high_resolution_clock::now().time_since_epoch()).count();\n \
    \   return r;\n}\n\ntemplate <class Key, class Data>\nstruct hashmap_base {\n\
    \    using u32 = uint32_t;\n    using u64 = uint64_t;\n    static constexpr u32\
    \ DS = 4; // default size\n\n    u32 cap, s, occ, shift;\n    vector<Data> data;\n\
    \    vector<bool> used, del;\n\n    explicit hashmap_base()\n        : cap(DS),\
    \ s(0), occ(0), shift(64 - __lg(DS)),\n          data(DS), used(DS, false), del(DS,\
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
    \    }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n// HashMap\
    \  --  open-addressing hash map with runtime-random hash\n// ~3-4x faster than\
    \ std::unordered_map\n// Key: any integral type, or pair<integral, integral>\n\
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
    \    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: utility/hashmap.hpp
  requiredBy: []
  timestamp: '2026-03-09 22:49:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker_associative_array.test.cpp
documentation_of: utility/hashmap.hpp
layout: document
redirect_from:
- /library/utility/hashmap.hpp
- /library/utility/hashmap.hpp.html
title: utility/hashmap.hpp
---
