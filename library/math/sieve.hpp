#pragma once
#include <bits/stdc++.h>
using namespace std;

// Linear sieve: O(N) precomputation
// Provides: is_prime, factorize, divisors, primes list
struct sieve {
    int n;
    vector<int> smallest_prime;
    vector<bool> is_prime_arr;
    vector<int> primes;

    sieve(int n) : n(n), smallest_prime(n+1, 0), is_prime_arr(n+1, true) {
        is_prime_arr[0] = is_prime_arr[1] = false;
        for (int i = 2; i <= n; i++) {
            if (is_prime_arr[i]) {
                primes.push_back(i);
                smallest_prime[i] = i;
            }
            for (int p : primes) {
                if ((long long)i * p > n) break;
                is_prime_arr[i * p] = false;
                smallest_prime[i * p] = p;
                if (i % p == 0) break;
            }
        }
    }

    bool is_prime(int x) const { return is_prime_arr[x]; }

    // Prime factorization using smallest prime factor: O(log x)
    vector<pair<int,int>> factorize(int x) const {
        vector<pair<int,int>> res;
        while (x > 1) {
            int p = smallest_prime[x], cnt = 0;
            while (x % p == 0) { x /= p; cnt++; }
            res.emplace_back(p, cnt);
        }
        return res;
    }

    // All divisors of x (sorted)
    vector<int> divisors(int x) const {
        auto fac = factorize(x);
        vector<int> divs = {1};
        for (auto [p, e] : fac) {
            int sz = divs.size();
            long long pe = 1;
            for (int i = 0; i < e; i++) {
                pe *= p;
                for (int j = 0; j < sz; j++) divs.push_back(divs[j] * (int)pe);
            }
        }
        sort(divs.begin(), divs.end());
        return divs;
    }
};

// Primality test for large numbers: O(sqrt(n))
bool is_prime_large(long long n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (long long i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i+2) == 0) return false;
    return true;
}
