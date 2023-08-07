#include <bits/stdc++.h>
using namespace std;

const int SZ = 100'005;
int n, m, u, v;
vector<int> adj[SZ];
int cnt[SZ], P[SZ];

void dfs(int cur) {
    if(P[cur] != -1) cnt[cur] += cnt[P[cur]];
    for(int nxt : adj[cur])
        dfs(nxt);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        cin >> P[i];
        if(P[i] == -1) continue;
        adj[P[i]].push_back(i);
    }

    while(m--) {
        cin >> u >> v;
        cnt[u] += v;
    }

    dfs(1);

    for(int i=1; i<=n; i++) cout << cnt[i] << ' ';

    return 0;
}