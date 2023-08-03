#include <bits/stdc++.h>
using namespace std;

int n, m, ans;
vector<int> adj[10005];
bool chk[10005];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int a, b, i=0; i<m; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int src : adj[1]) {
        chk[src] = true;
        for(int dest : adj[src])
            chk[dest] = true;
    }

    for(int i=2; i<=n; i++)
        ans += chk[i];

    cout << ans;
    return 0;
}