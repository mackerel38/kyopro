#pragma once
#include <bits/stdc++.h>
using namespace std;

// Sliding Window Aggregation (SWAG)
// push_back / pop_front / fold  all amortized O(1)
// (S, op, e) must form a monoid (NOT required to be commutative)
template <class S, auto op, auto e>
struct swag {
    struct node { S val, acc; };
    // front_st.back().acc = op(front elements in queue order)
    // back_st.back().acc  = op(back elements in enqueue order)
    vector<node> front_st, back_st;

    swag() = default;

    bool empty() const { return front_st.empty() && back_st.empty(); }
    int  size()  const { return (int)front_st.size() + (int)back_st.size(); }

    void push_back(S x) {
        S a = back_st.empty() ? x : op(back_st.back().acc, x);
        back_st.push_back({x, a});
    }

    void pop_front() {
        assert(!empty());
        if (front_st.empty()) {
            // move back -> front (reverse order)
            while (!back_st.empty()) {
                S x = back_st.back().val;
                back_st.pop_back();
                S a = front_st.empty() ? x : op(x, front_st.back().acc);
                front_st.push_back({x, a});
            }
        }
        front_st.pop_back();
    }

    // product of all elements in dequeue order (front ... back)
    S fold() const {
        if (front_st.empty() && back_st.empty()) return e();
        if (front_st.empty()) return back_st.back().acc;
        if (back_st.empty())  return front_st.back().acc;
        return op(front_st.back().acc, back_st.back().acc);
    }
};
