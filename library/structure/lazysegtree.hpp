#pragma once
#include <bits/stdc++.h>
using namespace std;

// Lazy Segment Tree
// S: value monoid type, op: S*S->S, e: identity of S
// F: lazy type, mapping: F*S->S, composition: F*F->F, id: identity of F
template <class S, auto op, auto e, class F, auto mapping, auto composition, auto id>
struct LazySegTree {
    int n, size;
    vector<S> data;
    vector<F> lazy;

    LazySegTree(int n) : n(n) {
        size = 1;
        while (size < n) size <<= 1;
        data.assign(2*size, e());
        lazy.assign(2*size, id());
    }
    LazySegTree(const vector<S>& v) : LazySegTree(v.size()) {
        for (int i = 0; i < (int)v.size(); i++) data[size+i] = v[i];
        for (int i = size-1; i >= 1; i--) data[i] = op(data[2*i], data[2*i+1]);
    }

    void apply_node(int k, const F& f) {
        data[k] = mapping(f, data[k]);
        lazy[k] = composition(f, lazy[k]);
    }
    void push_down(int k) {
        if (lazy[k] == id()) return;
        apply_node(2*k, lazy[k]);
        apply_node(2*k+1, lazy[k]);
        lazy[k] = id();
    }

    // Range apply f to [l, r)
    void apply(int l, int r, const F& f, int k, int lo, int hi) {
        if (r <= lo || hi <= l) return;
        if (l <= lo && hi <= r) { apply_node(k, f); return; }
        push_down(k);
        int mid = (lo + hi) / 2;
        apply(l, r, f, 2*k, lo, mid);
        apply(l, r, f, 2*k+1, mid, hi);
        data[k] = op(data[2*k], data[2*k+1]);
    }
    void apply(int l, int r, const F& f) { apply(l, r, f, 1, 0, size); }
    void apply(int i, const F& f) { apply(i, i+1, f); }

    // Range query on [l, r)
    S query(int l, int r, int k, int lo, int hi) {
        if (r <= lo || hi <= l) return e();
        if (l <= lo && hi <= r) return data[k];
        push_down(k);
        int mid = (lo + hi) / 2;
        return op(query(l, r, 2*k, lo, mid), query(l, r, 2*k+1, mid, hi));
    }
    S query(int l, int r) { return query(l, r, 1, 0, size); }
    S query(int i) { return query(i, i+1); }

    void set(int i, const S& v) {
        i += size;
        for (int k = __lg(size); k >= 1; k--) push_down(i >> k);
        data[i] = v;
        for (int k = 1; k <= __lg(size); k++) {
            int p = i >> k;
            data[p] = op(data[2*p], data[2*p+1]);
        }
    }
};

// Example instantiation (range add, range min query):
// auto op = [](long long a, long long b){ return min(a, b); };
// auto e  = []{ return numeric_limits<long long>::max()/2; };
// auto mapping = [](long long f, long long s){ return f + s; };
// auto composition = [](long long f, long long g){ return f + g; };
// auto id = []{ return 0LL; };
// LazySegTree<long long, op, e, long long, mapping, composition, id> seg(n);
