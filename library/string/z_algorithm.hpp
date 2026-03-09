#pragma once
#include <bits/stdc++.h>
using namespace std;

// Z-algorithm: z[i] = length of the longest substring starting at i
//              that matches a prefix of s. z[0] = n by convention.
vector<int> z_algorithm(const string& s) {
    int n = s.size();
    vector<int> z(n, 0);
    z[0] = n;
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i < r) z[i] = min(r - i, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
        if (i + z[i] > r) { l = i; r = i + z[i]; }
    }
    return z;
}

// Find all occurrences of pattern in text using Z-algorithm
vector<int> z_search(const string& text, const string& pattern) {
    string s = pattern + "$" + text;
    auto z = z_algorithm(s);
    int m = pattern.size();
    vector<int> res;
    for (int i = m+1; i < (int)s.size(); i++)
        if (z[i] >= m) res.push_back(i - m - 1);
    return res;
}
