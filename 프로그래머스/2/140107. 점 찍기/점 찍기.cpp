#include <bits/stdc++.h>
using namespace std;
using LL = long long;

long long solution(int k, int d) {
    LL answer = 0;
    for(int i=0;i<=d;i+=k){
        LL dist = (LL)d*d-(LL)i*i;
        answer += floor(sqrt(dist) / k) + 1;
    }
    return answer;
}