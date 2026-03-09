#pragma once
#include <bits/stdc++.h>
using namespace std;

// Binary trie  (non-negative integers, B-bit keys)
// Operations in O(B):
//   insert(x), erase(x)
//   count(x)     -- number of x stored
//   size()       -- total count
//   min_element()  -- minimum stored value
//   max_element()  -- maximum stored value
//   xor_min(x)   -- min(v XOR x) over all stored v  ("set_xor_min" problem)
//   kth(k)       -- k-th (0-indexed) smallest
//   lower_bound(x) -- count of elements < x

template <int B = 30>
struct binary_trie {
    struct Node {
        int ch[2] = {-1, -1};
        int cnt = 0;
    };
    vector<Node> nd;

    binary_trie() { nd.push_back({}); } // root = 0

    int _new() { nd.push_back({}); return nd.size() - 1; }

    void insert(int x, int delta = 1) {
        int v = 0;
        nd[0].cnt += delta;
        for (int i = B - 1; i >= 0; i--) {
            int b = (x >> i) & 1;
            if (nd[v].ch[b] == -1) nd[v].ch[b] = _new();
            v = nd[v].ch[b];
            nd[v].cnt += delta;
        }
    }
    void erase(int x) { insert(x, -1); }

    int count(int x) const {
        int v = 0;
        for (int i = B - 1; i >= 0; i--) {
            int b = (x >> i) & 1;
            if (nd[v].ch[b] == -1) return 0;
            v = nd[v].ch[b];
        }
        return nd[v].cnt;
    }
    int size() const { return nd[0].cnt; }
    bool empty() const { return nd[0].cnt == 0; }

    // k-th (0-indexed) smallest
    int kth(int k) const {
        assert(0 <= k && k < size());
        int v = 0, res = 0;
        for (int i = B - 1; i >= 0; i--) {
            int l = nd[v].ch[0], lc = (l == -1 ? 0 : nd[l].cnt);
            if (k < lc) { v = l; }
            else { k -= lc; res |= (1 << i); v = nd[v].ch[1]; }
        }
        return res;
    }
    int min_element() const { return kth(0); }
    int max_element() const { return kth(size() - 1); }

    // min XOR with x
    int xor_min(int x) const {
        assert(!empty());
        int v = 0, res = 0;
        for (int i = B - 1; i >= 0; i--) {
            int b = (x >> i) & 1;
            int want = b; // prefer same bit => XOR becomes 0
            if (nd[v].ch[want] == -1 || nd[nd[v].ch[want]].cnt == 0) want ^= 1;
            res |= ((want ^ b) << i);
            v = nd[v].ch[want];
        }
        return res;
    }

    // number of elements < x
    int lower_bound(int x) const {
        int v = 0, cnt = 0;
        for (int i = B - 1; i >= 0; i--) {
            int b = (x >> i) & 1;
            if (b == 1) {
                int l = nd[v].ch[0];
                if (l != -1) cnt += nd[l].cnt;
            }
            if (nd[v].ch[b] == -1) break;
            v = nd[v].ch[b];
        }
        return cnt;
    }
};
