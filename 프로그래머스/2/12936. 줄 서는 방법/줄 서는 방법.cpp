#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL fact(int n) {
    LL ret = 1;
    for(int i=2; i<=n; i++) ret *= i;
    return ret;
}

vector<int> solution(int n, LL k) {
    vector<int> ans, tmp;
    for(int i=1; i<=n; i++) tmp.push_back(i);
    
    while(true) {
        LL fac = fact(n-1);
        int div = k / fac;
        LL rem = k % fac;
        
        if(rem == 0) div--;
        
        ans.push_back(tmp[div]);
        tmp.erase(tmp.begin() + div);
        
        if(rem == 1) {
            for(int nxt : tmp) ans.push_back(nxt);
            return ans;
        }
        else if(rem == 0) {
            for(int i=tmp.size()-1; i>=0; i--) ans.push_back(tmp[i]);
            return ans;
        }
        
        else {
            k = rem;
            n--;
        }
    }
    
    return ans;
}