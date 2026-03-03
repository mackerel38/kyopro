#pragma once
#include<bits/stdc++.h>
using namespace std;

struct unionfind {
    vector<int> data;

    unionfind(int n) : data(n, -1) {}

    int find(int k) { return data[k]<0 ? k : data[k] = find(data[k]); }
    int operator[](int k) { return find(k); }

    int merge(int x, int y) {
        if ((x = find(x)) == (y = find(y))) return false;
        if (data[x] < data[y]) swap(x, y);
        data[y] += data[x];
        data[x] = y;
        return true;
    }
    template<class F>
    int merge(int x, int y, const F& f) {
        if ((x = find(x)) == (y = find(y))) return false;
        if (data[y] < data[x]) swap(x, y);
        data[x] += data[y];
        data[y] = x;
        f(x, y);
        return true;
    }

    int size(int k) { return -data[find(k)]; }

    bool same(int x, int y) { return find(x) == find(y); }
};



