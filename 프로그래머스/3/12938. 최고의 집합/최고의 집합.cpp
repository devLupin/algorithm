#include <bits/stdc++.h>
using namespace std;

vector<int> solution(int n, int s) {
    vector<int> ans;
    
    if(n > s) {
        ans.push_back(-1);
        return ans;
    }
    
    int tmp = s%n;
    int init = s/n;
    
    ans.assign(n, init);
    for(int i=ans.size()-1; i>=0 && tmp > 0; i--,tmp--) 
        ans[i]++;

    return ans;
}