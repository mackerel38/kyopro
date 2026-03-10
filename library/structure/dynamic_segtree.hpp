#pragma once
#include <bits/stdc++.h>
using namespace std;

// Dynamic Segment Tree
// Template parameters:
//   T   : value type
//   op  : binary operation  T op(T, T)  (associative)
//   e   : identity element  T e()
//   Idx : index type (default: long long)
//
// Range: [lo, hi)  (specified at construction)
// Nodes are allocated on demand, so only O(q log(range)) memory is used.
//
// Operations:
//   get(pos)        : value at pos
//   set(pos, val)   : a[pos] = val
//   apply(pos, val) : a[pos] = op(a[pos], val)
//   prod(ql, qr)    : op-product of [ql, qr)
//   all_prod()      : op-product of [lo, hi)
//   max_right(ql,f) : max r in [ql,hi] s.t. f(prod(ql,r))==true  (*)
//   min_left(qr, f) : min l in [lo,qr] s.t. f(prod(l,qr))==true  (*)
//     (*) f must be monotone and f(e()) must be true.

template <class T, auto op, auto e, class Idx = long long>
struct dynamic_segtree {
private:
    struct Node {
        T   val;
        int left, right;
    };

    vector<Node> pool;
    int  root;
    Idx  lo, hi;

    int new_node() {
        pool.push_back({e(), -1, -1});
        return (int)pool.size() - 1;
    }

    T node_val(int v) const noexcept {
        return v == -1 ? e() : pool[v].val;
    }

    void push_up(int v) noexcept {
        pool[v].val = op(node_val(pool[v].left), node_val(pool[v].right));
    }

    // ---- prod ----
    T _prod(int v, Idx l, Idx r, Idx ql, Idx qr) const {
        if (v == -1 || qr <= l || r <= ql) return e();
        if (ql <= l && r <= qr) return pool[v].val;
        Idx m = l + (r - l) / 2;
        return op(_prod(pool[v].left,  l, m, ql, qr),
                  _prod(pool[v].right, m, r, ql, qr));
    }

    // ---- set ----
    void _set(int& v, Idx l, Idx r, Idx pos, T val) {
        if (v == -1) v = new_node();
        if (r - l == 1) { pool[v].val = val; return; }
        Idx m = l + (r - l) / 2;
        if (pos < m) _set(pool[v].left,  l, m, pos, val);
        else         _set(pool[v].right, m, r, pos, val);
        push_up(v);
    }

    // ---- apply ----
    void _apply(int& v, Idx l, Idx r, Idx pos, T val) {
        if (v == -1) v = new_node();
        if (r - l == 1) { pool[v].val = op(pool[v].val, val); return; }
        Idx m = l + (r - l) / 2;
        if (pos < m) _apply(pool[v].left,  l, m, pos, val);
        else         _apply(pool[v].right, m, r, pos, val);
        push_up(v);
    }

    // ---- max_right ----
    // Returns the leftmost position where the running product (from ql) first
    // fails f.  Returns hi if f holds throughout.
    // acc : product accumulated so far (left of current subtree)
    template <class F>
    Idx _max_right(int v, Idx l, Idx r, Idx ql, T& acc, const F& f) const {
        if (r <= ql || v == -1) return hi;   // out of range or null (contributes e())
        if (ql <= l) {
            // fully in range
            T nxt = op(acc, pool[v].val);
            if (f(nxt)) { acc = nxt; return hi; }  // whole node ok, keep going right
            if (r - l == 1) return l;              // leaf fails: boundary is here
        }
        Idx m = l + (r - l) / 2;
        Idx res = _max_right(pool[v].left,  l, m, ql, acc, f);
        if (res != hi) return res;
        return  _max_right(pool[v].right, m, r, ql, acc, f);
    }

    // ---- min_left ----
    // Returns the rightmost position where the running product (up to qr) first
    // fails f when we extend leftward.  Returns lo if f holds throughout.
    // acc : product accumulated so far (right of current subtree)
    template <class F>
    Idx _min_left(int v, Idx l, Idx r, Idx qr, T& acc, const F& f) const {
        if (qr <= l || v == -1) return lo;   // out of range or null (contributes e())
        if (r <= qr) {
            // fully in range
            T nxt = op(pool[v].val, acc);
            if (f(nxt)) { acc = nxt; return lo; }  // whole node ok, keep going left
            if (r - l == 1) return r;              // leaf fails: boundary is r (= l+1)
        }
        Idx m = l + (r - l) / 2;
        Idx res = _min_left(pool[v].right, m, r, qr, acc, f);
        if (res != lo) return res;
        return   _min_left(pool[v].left,  l, m, qr, acc, f);
    }

public:
    dynamic_segtree() = default;
    // reserve_size: pre-allocated node pool capacity
    dynamic_segtree(Idx lo, Idx hi, int reserve_size = 1 << 22)
        : lo(lo), hi(hi), root(-1) {
        pool.reserve(reserve_size);
    }

    // prod(ql, qr): op-product of [ql, qr)
    T prod(Idx ql, Idx qr) const {
        assert(lo <= ql && qr <= hi);
        return _prod(root, lo, hi, ql, qr);
    }

    T all_prod() const { return node_val(root); }

    // get(pos): value at pos
    T get(Idx pos) const {
        assert(lo <= pos && pos < hi);
        return _prod(root, lo, hi, pos, pos + 1);
    }

    // set(pos, val): a[pos] = val
    void set(Idx pos, T val) {
        assert(lo <= pos && pos < hi);
        _set(root, lo, hi, pos, val);
    }

    // apply(pos, val): a[pos] = op(a[pos], val)
    void apply(Idx pos, T val) {
        assert(lo <= pos && pos < hi);
        _apply(root, lo, hi, pos, val);
    }

    // max_right(ql, f):
    //   Returns r in [ql, hi] s.t. f(prod(ql, r)) == true
    //   and (r == hi  or  f(prod(ql, r+1)) == false).
    //   Precondition: f(e()) == true, f must be monotone.
    template <class F>
    Idx max_right(Idx ql, const F& f) const {
        assert(lo <= ql && ql <= hi);
        assert(f(e()));
        T acc = e();
        return _max_right(root, lo, hi, ql, acc, f);
    }

    // min_left(qr, f):
    //   Returns l in [lo, qr] s.t. f(prod(l, qr)) == true
    //   and (l == lo  or  f(prod(l-1, qr)) == false).
    //   Precondition: f(e()) == true, f must be monotone.
    template <class F>
    Idx min_left(Idx qr, const F& f) const {
        assert(lo <= qr && qr <= hi);
        assert(f(e()));
        T acc = e();
        return _min_left(root, lo, hi, qr, acc, f);
    }
};
