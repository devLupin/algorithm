#include <bits/stdc++.h>

using namespace std;

bool adj[105][105];
bool vis[105];

int bfs(int s, int n) {
    bool vis[105] = {false,};
    queue<int> q;
    int ret = 0;
    
    q.push(s);
    vis[s] = true;
    
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        ret++;
        
        for(int i=1; i<=n; i++) {
            if(!vis[i] && adj[cur][i]) {
                q.push(i);
                vis[i] = true;
            }
        }
    }
    
    return ret;
}

int solution(int n, vector<vector<int>> wires) {
    int ans = 0x3f3f3f3f;
    
    for(auto nxt : wires) {
        int from = nxt[0], to = nxt[1];
        adj[from][to] = adj[to][from] = true;
    }
    
    for(auto nxt : wires) {
        int from = nxt[0], to = nxt[1];
        
        adj[from][to] = adj[to][from] = false;
        
        int a = bfs(from, n);
        int b = bfs(to, n);
        
        ans = min(ans, abs(a-b));
        
        adj[from][to] = adj[to][from] = true;
    }
    
    return ans;
}