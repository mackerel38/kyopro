#pragma once
#include<bits/stdc++.h>
using namespace std;

template <class T>
struct BIT {
    int _n;
    vector<T> data;

    BIT() = default;
    BIT(int n) : _n(n), data(_n, T{}) {}
    BIT(const vector<T>& v) : _n(ssize(v)), data(v) {
        for (int i=1; i<=_n; ++i) {
            int I = i + (i & -i);
            if (I <= _n) data[I-1] += data[i-1];
        }
    }

    void add(int x, T y) {
        assert(0<=x && x<_n);
        x++;
        while (x <= _n) {
            data[x-1] += y;
            x += x & -x;
        }
    }
    void set(int x, T y) { add(x, y-get(x)); }

    void get(int x) const { return sum(x+1) - sum(x); }
    void operator[](int x) const { return get(x); }

    T sum(int x) const {
        assert(0<=x && x<=_n);
        T s = T{};
        while (0 < x) {
            s += data[x-1];
            x -= x & -x;
        }
        return s;
    }
    T sum(int x, int y) const {
        assert(x <= y);
        return sum(y) - sum(x);
    }
};
