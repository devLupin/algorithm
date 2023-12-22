#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> topping) {
    int ans = 0;
    map<int,int> cur, cmp;
    
    for(int x : topping) cur[x]++;
    
    for(int x : topping) {
        if(cur.find(x) != cur.end()) {
            cur[x]--;
            cmp[x]++;
            if(cur[x] == 0) cur.erase(x);
        }
        if(cur.size() == cmp.size()) ans++;
    }
    
    return ans;
}