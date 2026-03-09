---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker_predecessor_problem.test.cpp
    title: verify/library_checker_predecessor_problem.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"structure/splay_tree.hpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\n// Splay Tree\n// - insert(key)     : O(log n) amortized\n\
    // - erase(key)      : O(log n) amortized\n// - contains(key)   : O(log n) amortized\n\
    // - predecessor(key): max element strictly < key,  O(log n) amortized\n// - successor(key)\
    \  : min element strictly > key,  O(log n) amortized\n// - lower_bound(key): min\
    \ element >= key,           O(log n) amortized\n// - prev_le(key)    : max element\
    \ <= key,           O(log n) amortized\n// - min_element()   : min element in\
    \ set\n// - max_element()   : max element in set\ntemplate <class Key, class Comp\
    \ = less<Key>>\nstruct splay_tree {\nprivate:\n    struct Node {\n        Key\
    \ key;\n        Node *ch[2], *par;\n        Node(const Key& k) : key(k), par(nullptr)\
    \ { ch[0] = ch[1] = nullptr; }\n    };\n\n    Node* root = nullptr;\n    int _size\
    \ = 0;\n    [[no_unique_address]] Comp comp;\n\n    bool eq(const Key& a, const\
    \ Key& b) const {\n        return !comp(a, b) && !comp(b, a);\n    }\n\n    void\
    \ clear_rec(Node* x) {\n        if (!x) return;\n        clear_rec(x->ch[0]);\n\
    \        clear_rec(x->ch[1]);\n        delete x;\n    }\n\n    int dir(Node* x)\
    \ const { return x->par->ch[1] == x ? 1 : 0; }\n\n    void rotate(Node* x) {\n\
    \        Node* p = x->par;\n        Node* g = p->par;\n        int d = dir(x);\n\
    \        p->ch[d] = x->ch[d ^ 1];\n        if (x->ch[d ^ 1]) x->ch[d ^ 1]->par\
    \ = p;\n        x->ch[d ^ 1] = p;\n        p->par = x;\n        x->par = g;\n\
    \        if (g) g->ch[g->ch[1] == p] = x;\n        else root = x;\n    }\n\n \
    \   void splay(Node* x) {\n        while (x->par) {\n            Node* p = x->par;\n\
    \            if (p->par) {\n                if (dir(x) == dir(p)) rotate(p);\n\
    \                else rotate(x);\n            }\n            rotate(x);\n    \
    \    }\n        root = x;\n    }\n\n    // Returns the node equal to key, or the\
    \ last visited node in BST search.\n    Node* find_node(const Key& key) const\
    \ {\n        Node* cur = root;\n        Node* last = nullptr;\n        while (cur)\
    \ {\n            last = cur;\n            if (eq(cur->key, key)) return cur;\n\
    \            cur = cur->ch[comp(cur->key, key)]; // go right if cur->key < key\n\
    \        }\n        return last;\n    }\n\npublic:\n    splay_tree() = default;\n\
    \    splay_tree(const splay_tree&) = delete;\n    splay_tree& operator=(const\
    \ splay_tree&) = delete;\n    ~splay_tree() { clear_rec(root); }\n\n    int size()\
    \ const { return _size; }\n    bool empty() const { return _size == 0; }\n\n \
    \   // O(log n) amortized\n    bool contains(const Key& key) {\n        if (!root)\
    \ return false;\n        Node* x = find_node(key);\n        splay(x);\n      \
    \  return eq(x->key, key);\n    }\n\n    // Returns true if inserted, false if\
    \ already present. O(log n) amortized\n    bool insert(const Key& key) {\n   \
    \     if (!root) {\n            root = new Node(key);\n            _size++;\n\
    \            return true;\n        }\n        Node* x = find_node(key);\n    \
    \    splay(x);\n        if (eq(x->key, key)) return false;\n        Node* nd =\
    \ new Node(key);\n        _size++;\n        if (comp(x->key, key)) { // x->key\
    \ < key: nd splits right\n            nd->ch[0] = x;\n            nd->ch[1] =\
    \ x->ch[1];\n            if (x->ch[1]) x->ch[1]->par = nd;\n            x->ch[1]\
    \ = nullptr;\n            x->par = nd;\n        } else { // x->key > key: nd splits\
    \ left\n            nd->ch[1] = x;\n            nd->ch[0] = x->ch[0];\n      \
    \      if (x->ch[0]) x->ch[0]->par = nd;\n            x->ch[0] = nullptr;\n  \
    \          x->par = nd;\n        }\n        root = nd;\n        return true;\n\
    \    }\n\n    // Returns true if erased, false if not found. O(log n) amortized\n\
    \    bool erase(const Key& key) {\n        if (!root) return false;\n        Node*\
    \ x = find_node(key);\n        splay(x);\n        if (!eq(x->key, key)) return\
    \ false;\n        Node* L = x->ch[0];\n        Node* R = x->ch[1];\n        if\
    \ (L) L->par = nullptr;\n        if (R) R->par = nullptr;\n        delete x;\n\
    \        _size--;\n        if (!L) { root = R; return true; }\n        if (!R)\
    \ { root = L; return true; }\n        // Splay max of L to root, then attach R\n\
    \        root = L;\n        Node* cur = L;\n        while (cur->ch[1]) cur = cur->ch[1];\n\
    \        splay(cur);\n        root->ch[1] = R;\n        R->par = root;\n     \
    \   return true;\n    }\n\n    // Max element strictly less than key, or nullopt.\
    \ O(log n) amortized\n    optional<Key> predecessor(const Key& key) {\n      \
    \  if (!root) return nullopt;\n        Node* x = find_node(key);\n        splay(x);\n\
    \        if (comp(x->key, key)) return x->key; // x->key < key: x is the predecessor\n\
    \        // x->key >= key: predecessor is in left subtree\n        Node* cur =\
    \ x->ch[0];\n        if (!cur) return nullopt;\n        while (cur->ch[1]) cur\
    \ = cur->ch[1];\n        return cur->key;\n    }\n\n    // Min element strictly\
    \ greater than key, or nullopt. O(log n) amortized\n    optional<Key> successor(const\
    \ Key& key) {\n        if (!root) return nullopt;\n        Node* x = find_node(key);\n\
    \        splay(x);\n        if (comp(key, x->key)) return x->key; // x->key >\
    \ key: x is the successor\n        // x->key <= key: successor is in right subtree\n\
    \        Node* cur = x->ch[1];\n        if (!cur) return nullopt;\n        while\
    \ (cur->ch[0]) cur = cur->ch[0];\n        return cur->key;\n    }\n\n    // Min\
    \ element >= key, or nullopt. O(log n) amortized\n    optional<Key> lower_bound(const\
    \ Key& key) {\n        if (!root) return nullopt;\n        Node* x = find_node(key);\n\
    \        splay(x);\n        if (!comp(x->key, key)) {\n            // x->key >=\
    \ key\n            return x->key;\n        }\n        // x->key < key -> look\
    \ in right subtree for min\n        Node* cur = x->ch[1];\n        if (!cur) return\
    \ nullopt;\n        while (cur->ch[0]) cur = cur->ch[0];\n        return cur->key;\n\
    \    }\n\n    // Max element <= key, or nullopt. O(log n) amortized\n    optional<Key>\
    \ prev_le(const Key& key) {\n        if (!root) return nullopt;\n        Node*\
    \ x = find_node(key);\n        splay(x);\n        if (!comp(key, x->key)) {\n\
    \            // x->key <= key\n            return x->key;\n        }\n       \
    \ // x->key > key -> look in left subtree for max\n        Node* cur = x->ch[0];\n\
    \        if (!cur) return nullopt;\n        while (cur->ch[1]) cur = cur->ch[1];\n\
    \        return cur->key;\n    }\n\n    // Min element in the set, or nullopt\n\
    \    optional<Key> min_element() {\n        if (!root) return nullopt;\n     \
    \   Node* cur = root;\n        while (cur->ch[0]) cur = cur->ch[0];\n        splay(cur);\n\
    \        return cur->key;\n    }\n\n    // Max element in the set, or nullopt\n\
    \    optional<Key> max_element() {\n        if (!root) return nullopt;\n     \
    \   Node* cur = root;\n        while (cur->ch[1]) cur = cur->ch[1];\n        splay(cur);\n\
    \        return cur->key;\n    }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n// Splay\
    \ Tree\n// - insert(key)     : O(log n) amortized\n// - erase(key)      : O(log\
    \ n) amortized\n// - contains(key)   : O(log n) amortized\n// - predecessor(key):\
    \ max element strictly < key,  O(log n) amortized\n// - successor(key)  : min\
    \ element strictly > key,  O(log n) amortized\n// - lower_bound(key): min element\
    \ >= key,           O(log n) amortized\n// - prev_le(key)    : max element <=\
    \ key,           O(log n) amortized\n// - min_element()   : min element in set\n\
    // - max_element()   : max element in set\ntemplate <class Key, class Comp = less<Key>>\n\
    struct splay_tree {\nprivate:\n    struct Node {\n        Key key;\n        Node\
    \ *ch[2], *par;\n        Node(const Key& k) : key(k), par(nullptr) { ch[0] = ch[1]\
    \ = nullptr; }\n    };\n\n    Node* root = nullptr;\n    int _size = 0;\n    [[no_unique_address]]\
    \ Comp comp;\n\n    bool eq(const Key& a, const Key& b) const {\n        return\
    \ !comp(a, b) && !comp(b, a);\n    }\n\n    void clear_rec(Node* x) {\n      \
    \  if (!x) return;\n        clear_rec(x->ch[0]);\n        clear_rec(x->ch[1]);\n\
    \        delete x;\n    }\n\n    int dir(Node* x) const { return x->par->ch[1]\
    \ == x ? 1 : 0; }\n\n    void rotate(Node* x) {\n        Node* p = x->par;\n \
    \       Node* g = p->par;\n        int d = dir(x);\n        p->ch[d] = x->ch[d\
    \ ^ 1];\n        if (x->ch[d ^ 1]) x->ch[d ^ 1]->par = p;\n        x->ch[d ^ 1]\
    \ = p;\n        p->par = x;\n        x->par = g;\n        if (g) g->ch[g->ch[1]\
    \ == p] = x;\n        else root = x;\n    }\n\n    void splay(Node* x) {\n   \
    \     while (x->par) {\n            Node* p = x->par;\n            if (p->par)\
    \ {\n                if (dir(x) == dir(p)) rotate(p);\n                else rotate(x);\n\
    \            }\n            rotate(x);\n        }\n        root = x;\n    }\n\n\
    \    // Returns the node equal to key, or the last visited node in BST search.\n\
    \    Node* find_node(const Key& key) const {\n        Node* cur = root;\n    \
    \    Node* last = nullptr;\n        while (cur) {\n            last = cur;\n \
    \           if (eq(cur->key, key)) return cur;\n            cur = cur->ch[comp(cur->key,\
    \ key)]; // go right if cur->key < key\n        }\n        return last;\n    }\n\
    \npublic:\n    splay_tree() = default;\n    splay_tree(const splay_tree&) = delete;\n\
    \    splay_tree& operator=(const splay_tree&) = delete;\n    ~splay_tree() { clear_rec(root);\
    \ }\n\n    int size() const { return _size; }\n    bool empty() const { return\
    \ _size == 0; }\n\n    // O(log n) amortized\n    bool contains(const Key& key)\
    \ {\n        if (!root) return false;\n        Node* x = find_node(key);\n   \
    \     splay(x);\n        return eq(x->key, key);\n    }\n\n    // Returns true\
    \ if inserted, false if already present. O(log n) amortized\n    bool insert(const\
    \ Key& key) {\n        if (!root) {\n            root = new Node(key);\n     \
    \       _size++;\n            return true;\n        }\n        Node* x = find_node(key);\n\
    \        splay(x);\n        if (eq(x->key, key)) return false;\n        Node*\
    \ nd = new Node(key);\n        _size++;\n        if (comp(x->key, key)) { // x->key\
    \ < key: nd splits right\n            nd->ch[0] = x;\n            nd->ch[1] =\
    \ x->ch[1];\n            if (x->ch[1]) x->ch[1]->par = nd;\n            x->ch[1]\
    \ = nullptr;\n            x->par = nd;\n        } else { // x->key > key: nd splits\
    \ left\n            nd->ch[1] = x;\n            nd->ch[0] = x->ch[0];\n      \
    \      if (x->ch[0]) x->ch[0]->par = nd;\n            x->ch[0] = nullptr;\n  \
    \          x->par = nd;\n        }\n        root = nd;\n        return true;\n\
    \    }\n\n    // Returns true if erased, false if not found. O(log n) amortized\n\
    \    bool erase(const Key& key) {\n        if (!root) return false;\n        Node*\
    \ x = find_node(key);\n        splay(x);\n        if (!eq(x->key, key)) return\
    \ false;\n        Node* L = x->ch[0];\n        Node* R = x->ch[1];\n        if\
    \ (L) L->par = nullptr;\n        if (R) R->par = nullptr;\n        delete x;\n\
    \        _size--;\n        if (!L) { root = R; return true; }\n        if (!R)\
    \ { root = L; return true; }\n        // Splay max of L to root, then attach R\n\
    \        root = L;\n        Node* cur = L;\n        while (cur->ch[1]) cur = cur->ch[1];\n\
    \        splay(cur);\n        root->ch[1] = R;\n        R->par = root;\n     \
    \   return true;\n    }\n\n    // Max element strictly less than key, or nullopt.\
    \ O(log n) amortized\n    optional<Key> predecessor(const Key& key) {\n      \
    \  if (!root) return nullopt;\n        Node* x = find_node(key);\n        splay(x);\n\
    \        if (comp(x->key, key)) return x->key; // x->key < key: x is the predecessor\n\
    \        // x->key >= key: predecessor is in left subtree\n        Node* cur =\
    \ x->ch[0];\n        if (!cur) return nullopt;\n        while (cur->ch[1]) cur\
    \ = cur->ch[1];\n        return cur->key;\n    }\n\n    // Min element strictly\
    \ greater than key, or nullopt. O(log n) amortized\n    optional<Key> successor(const\
    \ Key& key) {\n        if (!root) return nullopt;\n        Node* x = find_node(key);\n\
    \        splay(x);\n        if (comp(key, x->key)) return x->key; // x->key >\
    \ key: x is the successor\n        // x->key <= key: successor is in right subtree\n\
    \        Node* cur = x->ch[1];\n        if (!cur) return nullopt;\n        while\
    \ (cur->ch[0]) cur = cur->ch[0];\n        return cur->key;\n    }\n\n    // Min\
    \ element >= key, or nullopt. O(log n) amortized\n    optional<Key> lower_bound(const\
    \ Key& key) {\n        if (!root) return nullopt;\n        Node* x = find_node(key);\n\
    \        splay(x);\n        if (!comp(x->key, key)) {\n            // x->key >=\
    \ key\n            return x->key;\n        }\n        // x->key < key -> look\
    \ in right subtree for min\n        Node* cur = x->ch[1];\n        if (!cur) return\
    \ nullopt;\n        while (cur->ch[0]) cur = cur->ch[0];\n        return cur->key;\n\
    \    }\n\n    // Max element <= key, or nullopt. O(log n) amortized\n    optional<Key>\
    \ prev_le(const Key& key) {\n        if (!root) return nullopt;\n        Node*\
    \ x = find_node(key);\n        splay(x);\n        if (!comp(key, x->key)) {\n\
    \            // x->key <= key\n            return x->key;\n        }\n       \
    \ // x->key > key -> look in left subtree for max\n        Node* cur = x->ch[0];\n\
    \        if (!cur) return nullopt;\n        while (cur->ch[1]) cur = cur->ch[1];\n\
    \        return cur->key;\n    }\n\n    // Min element in the set, or nullopt\n\
    \    optional<Key> min_element() {\n        if (!root) return nullopt;\n     \
    \   Node* cur = root;\n        while (cur->ch[0]) cur = cur->ch[0];\n        splay(cur);\n\
    \        return cur->key;\n    }\n\n    // Max element in the set, or nullopt\n\
    \    optional<Key> max_element() {\n        if (!root) return nullopt;\n     \
    \   Node* cur = root;\n        while (cur->ch[1]) cur = cur->ch[1];\n        splay(cur);\n\
    \        return cur->key;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/splay_tree.hpp
  requiredBy: []
  timestamp: '2026-03-10 08:46:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker_predecessor_problem.test.cpp
documentation_of: structure/splay_tree.hpp
layout: document
redirect_from:
- /library/structure/splay_tree.hpp
- /library/structure/splay_tree.hpp.html
title: structure/splay_tree.hpp
---
