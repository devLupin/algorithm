#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL solution(int n, vector<int> times) {
    LL answer = 0;
    sort(times.begin(), times.end());
    
    LL st = 1, en = 1LL * n * times.back();
    while(st <= en) {
        LL mid = (st + en) / 2;
        LL sum = 0;
        
        for(LL t : times) sum += mid / t;
        
        if(sum >= n) {
            en = mid - 1;
            answer = mid;
        }
        else st = mid + 1;
    }
    
    return answer;
}