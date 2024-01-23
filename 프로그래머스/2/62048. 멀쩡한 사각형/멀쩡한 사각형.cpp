#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int gcd(int a, int b) {
    while(b != 0) {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

long long solution(int w,int h) {
    LL ans = LL(w) * h;
    return ans - (w + h - gcd(w, h));
}