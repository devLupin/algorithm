#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int INF = 987654321;
LL adj[205][205];

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            adj[i][j] = INF;
    
    for(auto& nxt : fares) {
        int u = nxt[0], v = nxt[1], c = nxt[2];
        adj[u][v] = adj[v][u] = c;
    }
    
    for(int k=1; k<=n; k++)
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++) {
                if(i == INF || j == INF || k == INF) continue;
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
    
    LL ans = min(adj[s][a] + adj[a][b], adj[s][b] + adj[b][a]);
    ans = min(ans, adj[s][a] + adj[s][b]);
    
    for(int i=1; i<=n; i++) {
        if(i == s || i == a || i == b) continue;
        ans = min(ans, adj[s][i] + adj[i][a] + adj[i][b]);
    }
    
    return ans;
}