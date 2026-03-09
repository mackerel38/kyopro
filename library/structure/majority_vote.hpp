#pragma once
#include <bits/stdc++.h>
using namespace std;

// Boyer-Moore majority voting  (single-pass streaming)
// After pushing N elements, query() returns the majority candidate.
// IMPORTANT: verify externally that the candidate appears > N/2 times.
template <class T = int>
struct majority_vote {
    T cand{};
    int cnt = 0;

    void push(T x) {
        if (cnt == 0) { cand = x; cnt = 1; }
        else if (cand == x) ++cnt;
        else --cnt;
    }
    T   query()          const { return cand; }
    bool has_candidate() const { return cnt > 0; }
    void clear() { cand = T{}; cnt = 0; }
};

// Segment-tree-based majority query with point updates
// S = pair<T, int>: {candidate, excess}
// Use with segtree<S, bm_op<T>, bm_e<T>>
//
// After query(l, r), the returned candidate MIGHT be the majority.
// Verify by counting occurrences externally (e.g. using map<T, pbds_set>).

template <class T = int>
struct majority_segtree {
    using S = pair<T, int>;

    static S bm_op(S a, S b) {
        if (a.second == 0) return b;
        if (b.second == 0) return a;
        if (a.first == b.first) return {a.first, a.second + b.second};
        if (a.second > b.second) return {a.first, a.second - b.second};
        if (a.second < b.second) return {b.first, b.second - a.second};
        return {b.first, 0};
    }
    static S bm_e() { return {T{}, 0}; }

    int n;
    vector<S> seg;

    majority_segtree() = default;
    majority_segtree(const vector<T>& a) : n(a.size()), seg(4 * a.size()) {
        build(a, 1, 0, n);
    }

    void build(const vector<T>& a, int v, int l, int r) {
        if (r - l == 1) { seg[v] = {a[l], 1}; return; }
        int m = (l + r) / 2;
        build(a, 2*v, l, m); build(a, 2*v+1, m, r);
        seg[v] = bm_op(seg[2*v], seg[2*v+1]);
    }
    void set(int i, T x, int v, int l, int r) {
        if (r - l == 1) { seg[v] = {x, 1}; return; }
        int m = (l + r) / 2;
        if (i < m) set(i, x, 2*v, l, m); else set(i, x, 2*v+1, m, r);
        seg[v] = bm_op(seg[2*v], seg[2*v+1]);
    }
    S query(int ql, int qr, int v, int l, int r) {
        if (qr <= l || r <= ql) return bm_e();
        if (ql <= l && r <= qr) return seg[v];
        int m = (l + r) / 2;
        return bm_op(query(ql, qr, 2*v, l, m), query(ql, qr, 2*v+1, m, r));
    }

    void set(int i, T x)       { set(i, x, 1, 0, n); }
    // Returns BM candidate for a[l..r). Verify count externally!
    S query(int l, int r)      { return query(l, r, 1, 0, n); }
};
