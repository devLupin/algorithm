#include <bits/stdc++.h>
using namespace std;

const int SZ = 105;
int n, res, flag;
bool vis[SZ][SZ], adj[SZ][SZ], ans;

void dfs(int cur, int src, int dest) {
    if(cur == dest && flag) {
        ans = true;
        return;
    }

    flag = 1;

    for(int i=0; i<n && !ans; i++)
        if(adj[cur][i] && !vis[cur][i]) {
            vis[cur][i] = true;
            dfs(i, src, dest);
        }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> adj[i][j];

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            flag = ans = 0;
            fill_n(&vis[0][0], SZ*SZ, false);

            dfs(i, i, j);
            cout << (ans ? 1 : 0) << ' ';
        }
        cout << '\n';
    }

    return 0;
}