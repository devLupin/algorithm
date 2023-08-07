#include <bits/stdc++.h>
using namespace std;

const int SZ = 100'005;
int n;
vector<int> adj[SZ];
int ans[SZ];

void dfs(int cur) {
    for(int nxt : adj[cur]) {
        if(nxt == ans[cur]) continue;
        ans[nxt] = cur;
        dfs(nxt);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int u, v, i=1; i<n; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);
    for(int i=2; i<=n; i++)
        cout << ans[i] << '\n';

    return 0;
}