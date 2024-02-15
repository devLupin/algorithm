#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL dots(int r) {
    LL cnt = r;
    for(int i=1; i<r; i++)
        cnt += (LL)sqrt(1LL*r*r - 1LL*i*i);
    return cnt*4+1;
}

LL inDots(int r) {
    LL cnt = r-1;
    for(int i=1; i<r; i++) {
        LL tmp = (LL)sqrt(1LL*r*r - 1LL*i*i);
        if(tmp*tmp + 1LL*i*i == 1LL*r*r) cnt += tmp - 1;
        else cnt += tmp;
    }
    return cnt*4+1;
}

LL solution(int r1, int r2) {
    return dots(r2) - inDots(r1);
}