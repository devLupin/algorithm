#include <bits/stdc++.h>
using namespace std;

const int SZ = 20'005;
vector<int> adj[SZ];

int bfs(int n) {
    int ret = 0;
    queue<int> q;
    vector<bool> vis(n+1, false);
    vector<int> ans(n+1, SZ);
    ans[0] = 0, ans[1] = 0;
    
    q.push(1);
    vis[1] = true;
    
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        
        for(auto nxt : adj[cur]) {
            if(vis[nxt]) continue;
            else {
                ans[nxt] = min(ans[cur] + 1, ans[nxt]);
                q.push(nxt);
                vis[nxt] = true;
            }
        }
    }
    
    sort(ans.begin(), ans.end(), greater<>());
    
    int cmp = ans[0];
    for(auto nxt : ans)
        if(cmp == nxt) ret++;
        
    return ret;
}

int solution(int n, vector<vector<int>> edge) {
    for(auto nxt : edge) {
        int s = nxt[0], d = nxt[1];
        adj[s].push_back(d);
        adj[d].push_back(s);
    }
    
    return bfs(n);
}