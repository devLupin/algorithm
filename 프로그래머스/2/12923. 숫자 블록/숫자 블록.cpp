#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL _find(LL n) {
    LL ret = 1;
    
    for(LL i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            ret = i;
            
            if(n / i <= 10'000'000) {
                ret = n / i;
                break;
            }
        }
    }
    
    return ret;
}

vector<int> solution(LL begin, LL end) {
    vector<int> ans;
    
    for(LL i = begin; i <= end; i++) {
        if(i == 1) {
            ans.push_back(0);
            continue;
        }
        ans.push_back(_find(i));
    }
    
    return ans;
}