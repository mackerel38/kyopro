#pragma once
#include <bits/stdc++.h>
using namespace std;

// Double-Ended Priority Queue using Interval Heap.
// Each node stores an interval [lo, hi] with lo <= hi.
// Invariants (over parent-child pairs):
//   parent.lo <= child.lo   (min-heap on lo)
//   parent.hi >= child.hi   (max-heap on hi)
// Thus root holds the global minimum (lo) and maximum (hi).
//
// Complexity: push / pop_min / pop_max in O(log n), top_min / top_max in O(1).
// Template parameter Compare: cmp(a, b) == true iff a is strictly less than b.
template <class T, class Compare = less<T>>
struct bipq {
private:
    vector<pair<T, T>> h;  // h[i] = {lo, hi}
    int _sz = 0;
    [[no_unique_address]] Compare cmp;

    // For the partial last node (_sz odd), only h.back().first is valid.
    // hi_ref / hi_val transparently handle this.
    T& hi_ref(int i) noexcept {
        return (i == (int)h.size() - 1 && _sz % 2 == 1) ? h[i].first : h[i].second;
    }
    const T& hi_val(int i) const noexcept {
        return (i == (int)h.size() - 1 && _sz % 2 == 1) ? h[i].first : h[i].second;
    }

    void sift_up_min(int i) {
        while (i > 0) {
            int p = (i - 1) / 2;
            if (cmp(h[i].first, h[p].first)) {
                swap(h[i].first, h[p].first);
                i = p;
            } else break;
        }
    }

    void sift_up_max(int i) {
        while (i > 0) {
            int p = (i - 1) / 2;
            if (cmp(h[p].second, hi_val(i))) {
                swap(hi_ref(i), h[p].second);
                i = p;
            } else break;
        }
    }

    void sift_down_min(int i) {
        int n = (int)h.size();
        while (true) {
            int c = 2 * i + 1;
            if (c >= n) break;
            if (c + 1 < n && cmp(h[c + 1].first, h[c].first)) c++;
            if (cmp(h[c].first, h[i].first)) {
                swap(h[i].first, h[c].first);
                // Restore lo <= hi within node c
                if (cmp(hi_val(c), h[c].first)) swap(h[c].first, hi_ref(c));
                i = c;
            } else break;
        }
    }

    void sift_down_max(int i) {
        int n = (int)h.size();
        while (true) {
            int c = 2 * i + 1;
            if (c >= n) break;
            if (c + 1 < n && cmp(hi_val(c), hi_val(c + 1))) c++;
            if (cmp(h[i].second, hi_val(c))) {
                swap(hi_ref(c), h[i].second);
                // Restore lo <= hi within node c
                if (cmp(hi_val(c), h[c].first)) swap(h[c].first, hi_ref(c));
                i = c;
            } else break;
        }
    }

public:
    bipq() = default;
    explicit bipq(Compare c) : cmp(c) {}
    template <class Iter>
    bipq(Iter first, Iter last) { for (auto it = first; it != last; ++it) push(*it); }
    bipq(initializer_list<T> il) : bipq(il.begin(), il.end()) {}

    int  size()  const noexcept { return _sz; }
    bool empty() const noexcept { return _sz == 0; }

    // Minimum element (undefined if empty)
    const T& top_min() const {
        assert(_sz > 0);
        return h[0].first;
    }

    // Maximum element (undefined if empty)
    const T& top_max() const {
        assert(_sz > 0);
        return hi_val(0);
    }

    void push(const T& x) {
        if (_sz % 2 == 0) {
            // Start a new (partial) leaf node
            h.push_back({x, x});
            _sz++;
            int i = (int)h.size() - 1;
            sift_up_min(i);
            sift_up_max(i);
        } else {
            // Complete the last partial node
            int i = (int)h.size() - 1;
            if (cmp(x, h[i].first)) {
                h[i].second = h[i].first;
                h[i].first  = x;
            } else {
                h[i].second = x;
            }
            _sz++;
            sift_up_min(i);
            sift_up_max(i);
        }
    }

    void pop_min() {
        assert(_sz > 0);
        if (_sz == 1) { h.pop_back(); _sz = 0; return; }
        if (_sz == 2) { h[0].first = h[0].second; _sz = 1; return; }

        int last = (int)h.size() - 1;
        T x;
        if (_sz % 2 == 1) {
            // Last node is partial: take its only element and remove the node
            x = h[last].first;
            h.pop_back();
        } else {
            // Last node is full: take hi, leaving it partial (handled by _sz--)
            x = h[last].second;
        }
        _sz--;

        h[0].first = x;
        // Restore lo <= hi at root if needed
        if (cmp(h[0].second, h[0].first)) swap(h[0].first, h[0].second);
        sift_down_min(0);
    }

    void pop_max() {
        assert(_sz > 0);
        if (_sz == 1) { h.pop_back(); _sz = 0; return; }
        if (_sz == 2) { _sz = 1; return; }  // only h[0].first remains

        int last = (int)h.size() - 1;
        T x;
        if (_sz % 2 == 1) {
            x = h[last].first;
            h.pop_back();
        } else {
            x = h[last].second;
        }
        _sz--;

        h[0].second = x;
        if (cmp(h[0].second, h[0].first)) swap(h[0].first, h[0].second);
        sift_down_max(0);
    }
};
