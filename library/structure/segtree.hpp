#pragma once
#include<bits/stdc++.h>
using namespace std;
template <class T, auto op, auto e>
struct segtree {
    int _n, size;
    vector<T> data;

    segtree() = default;
    segtree(int n) : _n(n) { build(vector<T>(n, e())); }
    segtree(const vector<T>& v) : _n(ssize(v)) { build(v); }
    void build(const vector<T>& v) {
        size = __bit_ceil((unsigned int)_n);
        data.assign(2*size, e());
        for (int i=0; i<_n; ++i) data[size+i] = v[i];
        for (int i=size-1; 0<i; --i) update(i);
    }
    
    void update(int x) { data[x] = op(data[2*x], data[2*x+1]); }

    void set(int x, T y) {
        assert(0<=x && x<_n);
        x += size;
        data[x] = y;
        for (x>>=1; 0<x; x>>=1) update(x);
    }
    void add(int x, T y) { set(x, op(get(x), y)); }

    T get(int x) const {
        assert(0<=x && x<_n);
        return data[size+x];
    }
    T operator[](int x) const { return get(x); }
    T allprod() const { return data[1]; }
    vector<T> values() const {
        vector<T> re;
        re.assign(data.begin()+size, data.begin()+size+_n);
        return re;
    }

    T prod(int x, int y) const {
        assert(0<=x && x<=y && y<=_n);
        x += size;
        y += size;
        T l = e(), r = e();
        while (x < y) {
            if (x & 1) l = op(l, data[x++]);
            if (y & 1) r = op(data[--y], r);
            x >>= 1;
            y >>= 1;
        }
        return op(l, r);
    }

    template<class F>
    int max_right(int x, const F& f) const {
        assert(0<=x && x<=_n);
        assert(f(e()));
        if (x == _n) return _n;
        x += size;
        T l = e();
        do {
            while ((x&1) == 0) x >>= 1;
            if (!f(op(l, data[x]))) {
                while (x < size) {
                    x = x * 2;
                    if (f(op(l, data[x]))) { 
                        l = op(l, data[x]);
                        x++;
                    }
                }
                return x - size;
            }
            l = op(l, data[x]);
            x++;
        } while ((x & -x) != x);
        return _n;
    }
    template<class F>
    int min_left(int x, const F& f) {
        assert(0<=x && x<_n);
        asserr(f(e()));
        if (x == 0) return 0;
        x += size;
        T r = e();
        do {
            x--;
            while (1<x && (x&1)) x >>= 1;
            if (!f(op(data[x], r))) {
                while (x < size) {
                    x = x * 2 + 1;
                    if (f(op(data[x], r))) {
                        r = op(data[x], r);
                        x--;
                    }
                }
                return x + 1 - size;
            }
            r = op(data[x], r);
        } while ((x & -x) != x);
        return 0;
    }
};
