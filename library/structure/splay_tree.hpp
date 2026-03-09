#pragma once
#include <bits/stdc++.h>
using namespace std;

// Splay Tree
// - insert(key)     : O(log n) amortized
// - erase(key)      : O(log n) amortized
// - contains(key)   : O(log n) amortized
// - predecessor(key): max element strictly < key,  O(log n) amortized
// - successor(key)  : min element strictly > key,  O(log n) amortized
// - lower_bound(key): min element >= key,           O(log n) amortized
// - prev_le(key)    : max element <= key,           O(log n) amortized
// - min_element()   : min element in set
// - max_element()   : max element in set
template <class Key, class Comp = less<Key>>
struct splay_tree {
private:
    struct Node {
        Key key;
        Node *ch[2], *par;
        Node(const Key& k) : key(k), par(nullptr) { ch[0] = ch[1] = nullptr; }
    };

    Node* root = nullptr;
    int _size = 0;
    [[no_unique_address]] Comp comp;

    bool eq(const Key& a, const Key& b) const {
        return !comp(a, b) && !comp(b, a);
    }

    void clear_rec(Node* x) {
        if (!x) return;
        clear_rec(x->ch[0]);
        clear_rec(x->ch[1]);
        delete x;
    }

    int dir(Node* x) const { return x->par->ch[1] == x ? 1 : 0; }

    void rotate(Node* x) {
        Node* p = x->par;
        Node* g = p->par;
        int d = dir(x);
        p->ch[d] = x->ch[d ^ 1];
        if (x->ch[d ^ 1]) x->ch[d ^ 1]->par = p;
        x->ch[d ^ 1] = p;
        p->par = x;
        x->par = g;
        if (g) g->ch[g->ch[1] == p] = x;
        else root = x;
    }

    void splay(Node* x) {
        while (x->par) {
            Node* p = x->par;
            if (p->par) {
                if (dir(x) == dir(p)) rotate(p);
                else rotate(x);
            }
            rotate(x);
        }
        root = x;
    }

    // Returns the node equal to key, or the last visited node in BST search.
    Node* find_node(const Key& key) const {
        Node* cur = root;
        Node* last = nullptr;
        while (cur) {
            last = cur;
            if (eq(cur->key, key)) return cur;
            cur = cur->ch[comp(cur->key, key)]; // go right if cur->key < key
        }
        return last;
    }

public:
    splay_tree() = default;
    splay_tree(const splay_tree&) = delete;
    splay_tree& operator=(const splay_tree&) = delete;
    ~splay_tree() { clear_rec(root); }

    int size() const { return _size; }
    bool empty() const { return _size == 0; }

    // O(log n) amortized
    bool contains(const Key& key) {
        if (!root) return false;
        Node* x = find_node(key);
        splay(x);
        return eq(x->key, key);
    }

    // Returns true if inserted, false if already present. O(log n) amortized
    bool insert(const Key& key) {
        if (!root) {
            root = new Node(key);
            _size++;
            return true;
        }
        Node* x = find_node(key);
        splay(x);
        if (eq(x->key, key)) return false;
        Node* nd = new Node(key);
        _size++;
        if (comp(x->key, key)) { // x->key < key: nd splits right
            nd->ch[0] = x;
            nd->ch[1] = x->ch[1];
            if (x->ch[1]) x->ch[1]->par = nd;
            x->ch[1] = nullptr;
            x->par = nd;
        } else { // x->key > key: nd splits left
            nd->ch[1] = x;
            nd->ch[0] = x->ch[0];
            if (x->ch[0]) x->ch[0]->par = nd;
            x->ch[0] = nullptr;
            x->par = nd;
        }
        root = nd;
        return true;
    }

    // Returns true if erased, false if not found. O(log n) amortized
    bool erase(const Key& key) {
        if (!root) return false;
        Node* x = find_node(key);
        splay(x);
        if (!eq(x->key, key)) return false;
        Node* L = x->ch[0];
        Node* R = x->ch[1];
        if (L) L->par = nullptr;
        if (R) R->par = nullptr;
        delete x;
        _size--;
        if (!L) { root = R; return true; }
        if (!R) { root = L; return true; }
        // Splay max of L to root, then attach R
        root = L;
        Node* cur = L;
        while (cur->ch[1]) cur = cur->ch[1];
        splay(cur);
        root->ch[1] = R;
        R->par = root;
        return true;
    }

    // Max element strictly less than key, or nullopt. O(log n) amortized
    optional<Key> predecessor(const Key& key) {
        if (!root) return nullopt;
        Node* x = find_node(key);
        splay(x);
        if (comp(x->key, key)) return x->key; // x->key < key: x is the predecessor
        // x->key >= key: predecessor is in left subtree
        Node* cur = x->ch[0];
        if (!cur) return nullopt;
        while (cur->ch[1]) cur = cur->ch[1];
        return cur->key;
    }

    // Min element strictly greater than key, or nullopt. O(log n) amortized
    optional<Key> successor(const Key& key) {
        if (!root) return nullopt;
        Node* x = find_node(key);
        splay(x);
        if (comp(key, x->key)) return x->key; // x->key > key: x is the successor
        // x->key <= key: successor is in right subtree
        Node* cur = x->ch[1];
        if (!cur) return nullopt;
        while (cur->ch[0]) cur = cur->ch[0];
        return cur->key;
    }

    // Min element >= key, or nullopt. O(log n) amortized
    optional<Key> lower_bound(const Key& key) {
        if (!root) return nullopt;
        Node* x = find_node(key);
        splay(x);
        if (!comp(x->key, key)) {
            // x->key >= key
            return x->key;
        }
        // x->key < key -> look in right subtree for min
        Node* cur = x->ch[1];
        if (!cur) return nullopt;
        while (cur->ch[0]) cur = cur->ch[0];
        return cur->key;
    }

    // Max element <= key, or nullopt. O(log n) amortized
    optional<Key> prev_le(const Key& key) {
        if (!root) return nullopt;
        Node* x = find_node(key);
        splay(x);
        if (!comp(key, x->key)) {
            // x->key <= key
            return x->key;
        }
        // x->key > key -> look in left subtree for max
        Node* cur = x->ch[0];
        if (!cur) return nullopt;
        while (cur->ch[1]) cur = cur->ch[1];
        return cur->key;
    }

    // Min element in the set, or nullopt
    optional<Key> min_element() {
        if (!root) return nullopt;
        Node* cur = root;
        while (cur->ch[0]) cur = cur->ch[0];
        splay(cur);
        return cur->key;
    }

    // Max element in the set, or nullopt
    optional<Key> max_element() {
        if (!root) return nullopt;
        Node* cur = root;
        while (cur->ch[1]) cur = cur->ch[1];
        splay(cur);
        return cur->key;
    }
};
