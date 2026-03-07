#pragma once
#include<bits/stdc++.h>
using namespace std;

struct unionfind {
    vector<int> data;

    unionfind(int n) : data(n, -1) {}

    int root(int k) { return data[k]<0 ? k : data[k] = root(data[k]); }
    int operator[](int k) { return root(k); }

    bool merge(int x, int y) {
        if ((x = root(x)) == (y = root(y))) return false;
        if (data[x] < data[y]) swap(x, y);
        data[y] += data[x];
        data[x] = y;
        return true;
    }
    template<class F>
    bool merge(int x, int y, const F& f) {
        if ((x = root(x)) == (y = root(y))) return false;
        if (data[y] < data[x]) swap(x, y);
        data[x] += data[y];
        data[y] = x;
        f(x, y);
        return true;
    }

    int size(int k) { return -data[root(k)]; }

    bool same(int x, int y) { return root(x) == root(y); }

    vector<vector<int>> groups() {
        vector<vector<int>> mem(data.size());
        for (int i=0; i<ssize(mem); ++i) mem[root(i)].emplace_back(i);
        vector<vector<int>> re;
        for (int i=0; i<ssize(mem); ++i) if (!mem[i].empty()) re.emplace_back(mem[i]);
        return re;
    }

    int components() const {
        int cnt = 0;
        for (auto& i : data) if (i < 0) cnt++;
        return cnt;
    }
};

