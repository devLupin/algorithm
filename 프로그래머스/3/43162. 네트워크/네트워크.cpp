#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
bool vis[205];
int N, ans;

void dfs(int nxt) {
    for(int i=0; i<adj[nxt].size(); i++) {
        if(!vis[i] && adj[nxt][i] == 1) {
            vis[i] = true;
            dfs(i);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    adj.assign(computers.begin(), computers.end());
    N = n;
    
    for(int i=0; i<n; i++) {
        if(!vis[i]) {
            vis[i] = true;
            dfs(i);
            ans++;
        }
    }
    
    return ans;
}