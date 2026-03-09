#pragma once
#include <bits/stdc++.h>
using namespace std;

// Boyer-Moore majority voting algorithm
// After pushing N elements, query() returns a majority candidate.
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

    T   query()         const { return cand; }
    bool has_candidate() const { return cnt > 0; }
    void clear() { cand = T{}; cnt = 0; }
};
