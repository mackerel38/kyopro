#pragma once
#include <bits/stdc++.h>
using namespace std;

// KMP failure function
vector<int> kmp_failure(const string& pattern) {
    int m = pattern.size();
    vector<int> fail(m, 0);
    for (int i = 1; i < m; i++) {
        int j = fail[i-1];
        while (j > 0 && pattern[i] != pattern[j]) j = fail[j-1];
        if (pattern[i] == pattern[j]) j++;
        fail[i] = j;
    }
    return fail;
}

// KMP search: returns all starting positions of pattern in text
vector<int> kmp_search(const string& text, const string& pattern) {
    if (pattern.empty()) return {};
    auto fail = kmp_failure(pattern);
    int n = text.size(), m = pattern.size();
    vector<int> res;
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j > 0 && text[i] != pattern[j]) j = fail[j-1];
        if (text[i] == pattern[j]) j++;
        if (j == m) {
            res.push_back(i - m + 1);
            j = fail[j-1];
        }
    }
    return res;
}

// Period of string: minimum repeating unit length
// e.g. "ababab" -> 2
int string_period(const string& s) {
    auto fail = kmp_failure(s);
    int n = s.size();
    int period = n - fail[n-1];
    return (n % period == 0) ? period : n;
}
