#include <bits/stdc++.h>
using namespace std;

long long solution(long long n) {
    long long cmp = sqrt(n);
    double tmp = sqrt(n);
    long long ans = (cmp == tmp * 1LL) ? (cmp + 1 * 1LL) * (cmp + 1 * 1LL) : -1 * 1LL;
    return ans;
}