#pragma once
#include <bits/stdc++.h>
using namespace std;

// HashMap  --  open-addressing hash map with runtime-random hash
// ~3-4x faster than std::unordered_map
// Key: any integral type, or pair<integral, integral>
// Reference: https://nyaannyaan.github.io/library/hashmap/hashmap.hpp

namespace _hm {
using u32 = uint32_t;
using u64 = uint64_t;

inline u64 _seed() {
    static const u64 r = chrono::duration_cast<chrono::nanoseconds>(
        chrono::high_resolution_clock::now().time_since_epoch()).count();
    return r;
}

template <class Key, class Data>
struct hashmap_base {
    using u32 = uint32_t;
    using u64 = uint64_t;
    static constexpr u32 DS = 4; // default size

    u32 cap, s, occ, shift;
    vector<Data> data;
    vector<bool> used, del;

    explicit hashmap_base()
        : cap(DS), s(0), occ(0), shift(64 - __lg(DS)),
          data(DS), used(DS, false), del(DS, false) {}

    // --- hash ---
    template <class K>
    enable_if_t<is_integral_v<K>, u32> inner_hash(K k) const {
        return (u64(k) ^ _seed()) * 11995408973635179863ULL >> shift;
    }
    template <class K>
    auto inner_hash(K k) const
        -> enable_if_t<is_integral_v<decltype(k.first)>, u32> {
        u64 a = (u64(k.first)  ^ _seed()) * 11995408973635179863ULL;
        u64 b = (u64(k.second) ^ _seed()) * 10150724397891781847ULL;
        return (a + b) >> shift;
    }
    template <class D = Data>
    enable_if_t<is_same_v<D, Key>, u32> hash_d(const D& d) const {
        return inner_hash(d);
    }
    template <class D = Data>
    enable_if_t<!is_same_v<D, Key>, u32> hash_d(const D& d) const {
        return inner_hash(d.first);
    }
    template <class D = Data>
    enable_if_t<is_same_v<D, Key>, Key> key_of(const D& d) const { return d; }
    template <class D = Data>
    enable_if_t<!is_same_v<D, Key>, Key> key_of(const D& d) const { return d.first; }

    // --- iterator ---
    struct iterator {
        u32 i; hashmap_base* p;
        Data& operator*()  const { return p->data[i]; }
        Data* operator->() const { return &p->data[i]; }
        bool operator==(const iterator& o) const { return i == o.i; }
        bool operator!=(const iterator& o) const { return i != o.i; }
        iterator& operator++() {
            do { ++i; } while (i < p->cap && !(p->used[i] && !p->del[i]));
            return *this;
        }
    };
    iterator begin() {
        u32 h = 0;
        while (h < cap && !(used[h] && !del[h])) ++h;
        return {h, this};
    }
    iterator end() { return {cap, this}; }

    // --- resize ---
    bool _ext(u32 x) const { return x * 2 >= cap; }
    bool _shr(u32 x) const { return DS < cap && x * 10 <= cap; }
    void reallocate(u32 nc) {
        shift = 64 - __lg(nc);
        vector<Data> nd(nc); vector<bool> nf(nc);
        for (u32 i = 0; i < cap; i++) {
            if (used[i] && !del[i]) {
                u32 h = hash_d(data[i]);
                while (nf[h]) h = (h + 1) & (nc - 1);
                nd[h] = move(data[i]); nf[h] = true;
            }
        }
        data.swap(nd); used.swap(nf);
        cap = nc; occ = s;
        del.assign(cap, false);
    }
    void extend() { reallocate(cap << 1); }
    void shrink() { reallocate(cap >> 1); }

    // --- public ---
    iterator find(const Key& k) {
        u32 h = inner_hash(k);
        while (true) {
            if (!used[h]) return end();
            if (key_of(data[h]) == k && !del[h]) return {h, this};
            h = (h + 1) & (cap - 1);
        }
    }
    bool contains(const Key& k) { return find(k) != end(); }

    iterator insert(const Data& d) {
        u32 h = hash_d(d);
        while (true) {
            if (!used[h]) {
                if (_ext(occ + 1)) { extend(); h = hash_d(d); continue; }
                data[h] = d; used[h] = true; ++occ; ++s;
                return {h, this};
            }
            if (key_of(data[h]) == key_of(d)) {
                if (del[h]) { data[h] = d; del[h] = false; ++s; }
                return {h, this};
            }
            h = (h + 1) & (cap - 1);
        }
    }
    iterator erase(iterator it) {
        if (it == end()) return end();
        del[it.i] = true; --s;
        iterator nxt = it; ++nxt;
        if (_shr(s)) { Data d = data[nxt.i]; shrink(); nxt = find(key_of(d)); }
        return nxt;
    }
    iterator erase(const Key& k) { return erase(find(k)); }
    bool  empty() const { return s == 0; }
    int   size()  const { return (int)s; }
    void  clear() {
        fill(used.begin(), used.end(), false);
        fill(del.begin(),  del.end(),  false);
        s = occ = 0;
    }
    void reserve(int n) {
        if (n <= 0) return;
        u32 nc = DS;
        while ((int)nc < n * 2) nc <<= 1;
        if (cap < nc) reallocate(nc);
    }
    friend iterator begin(hashmap_base& h) { return h.begin(); }
    friend iterator end  (hashmap_base& h) { return h.end(); }
};
} // namespace _hm

// hashmap<Key, Val>  --  unordered_map equivalent
template <class Key, class Val>
struct hashmap : _hm::hashmap_base<Key, pair<Key, Val>> {
    using base = _hm::hashmap_base<Key, pair<Key, Val>>;
    using base::base;
    Val& operator[](const Key& k) {
        typename base::u32 h = base::inner_hash(k);
        while (true) {
            if (!base::used[h]) {
                if (base::_ext(base::occ + 1)) { base::extend(); h = base::inner_hash(k); continue; }
                base::data[h] = {k, Val{}};
                base::used[h] = true; ++base::occ; ++base::s;
                return base::data[h].second;
            }
            if (base::data[h].first == k) {
                if (base::del[h]) { base::data[h].second = Val{}; base::del[h] = false; ++base::s; }
                return base::data[h].second;
            }
            h = (h + 1) & (base::cap - 1);
        }
    }
    typename base::iterator emplace(const Key& k, const Val& v) {
        return base::insert({k, v});
    }
};
