#pragma once
#include <bits/stdc++.h>
using namespace std;

template <long long Mod>
struct ModInt {
    long long val;
    ModInt(long long v = 0) : val(v % Mod) { if (val < 0) val += Mod; }
    ModInt operator+(const ModInt& r) const { return ModInt(val + r.val); }
    ModInt operator-(const ModInt& r) const { return ModInt(val - r.val + Mod); }
    ModInt operator*(const ModInt& r) const { return ModInt(val * r.val % Mod); }
    ModInt operator/(const ModInt& r) const { return *this * r.inv(); }
    ModInt& operator+=(const ModInt& r) { return *this = *this + r; }
    ModInt& operator-=(const ModInt& r) { return *this = *this - r; }
    ModInt& operator*=(const ModInt& r) { return *this = *this * r; }
    ModInt& operator/=(const ModInt& r) { return *this = *this / r; }
    bool operator==(const ModInt& r) const { return val == r.val; }
    bool operator!=(const ModInt& r) const { return val != r.val; }
    ModInt pow(long long n) const {
        ModInt res(1), base(val);
        for (; n > 0; n >>= 1) {
            if (n & 1) res *= base;
            base *= base;
        }
        return res;
    }
    ModInt inv() const { return pow(Mod - 2); } // Mod must be prime
    friend ostream& operator<<(ostream& os, const ModInt& x) { return os << x.val; }
    friend istream& operator>>(istream& is, ModInt& x) {
        long long v; is >> v; x = ModInt(v); return is;
    }
};

using mint  = ModInt<998244353>;
using mint7 = ModInt<1000000007>;
