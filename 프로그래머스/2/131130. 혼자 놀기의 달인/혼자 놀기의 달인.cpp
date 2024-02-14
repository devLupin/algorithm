#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> cards) {
    int sz = cards.size();
    vector<bool> vis(sz+1, false);
    vector<int> res;
    
    for(int& cur : cards) {
        int cnt = 0;
        
        while(!vis[cur]) {
            vis[cur] = true;
            cur = cards[cur-1];
            cnt++;
        }
        
        if(cnt > 0) res.push_back(cnt);
    }
    
    if(res.size() <= 1) return 0;
    else {
        sort(res.begin(), res.end(), greater<>());
        return res[0] * res[1];
    }
}