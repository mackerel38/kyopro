#pragma once
#include <bits/stdc++.h>
using namespace std;

// Extended Euclidean: finds x, y s.t. a*x + b*y = gcd(a, b)
// Returns gcd(a, b)
template <class T>
T extgcd(T a, T b, T& x, T& y) {
    if (b == 0) { x = 1; y = 0; return a; }
    T x1, y1;
    T g = extgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

// Modular inverse using extgcd (works for non-prime mod)
// Requires gcd(a, mod) == 1
template <class T>
T modinv(T a, T mod) {
    T x, y;
    extgcd(a, mod, x, y);
    return (x % mod + mod) % mod;
}

// Chinese Remainder Theorem
// Finds x s.t. x ≡ r1 (mod m1) and x ≡ r2 (mod m2)
// Returns {r, lcm(m1,m2)}, or {0, 0} if no solution exists
pair<long long, long long> crt(long long r1, long long m1, long long r2, long long m2) {
    long long x, y;
    long long g = extgcd(m1, m2, x, y);
    if ((r2 - r1) % g != 0) return {0, 0};
    long long m = m1 / g * m2;
    long long r = (r1 + m1 * ((r2 - r1) / g % (m2/g) * (x % (m2/g)) % (m2/g))) % m;
    if (r < 0) r += m;
    return {r, m};
}
