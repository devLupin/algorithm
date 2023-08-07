#include <bits/stdc++.h>
using namespace std;

const int SZ = 100'005;
int n, m, u, v, cnt;
vector<int> adj[SZ];
bool vis[SZ];

void dfs(int cur) {
    if(vis[cur]) return;
    vis[cur] = true;
    for(int nxt : adj[cur])
        dfs(nxt);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i=0; i<m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=1; i<=n; i++) {
        if(vis[i]) continue;
        dfs(i);
        cnt++;
    }

    cout << (cnt-1) + (m+cnt-1)-(n-1);

    return 0;
}