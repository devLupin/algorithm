#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    vector<vector<bool>> adj(n+1, vector<bool>(n+1, false));
    
    for(auto nxt : results) {
        int from = nxt[0];
        int to = nxt[1];    
        adj[from][to] = true;
    }
    
    for(int k=1; k<=n; k++)
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                if(adj[i][k] && adj[k][j]) adj[i][j] = true;
    
    for(int i=1; i<=n; i++) {
        int cnt = 0;
        for(int j=1; j<=n; j++)
            if(adj[i][j] || adj[j][i]) cnt++;
        answer += (cnt == n - 1);
    }
    
    return answer;
}