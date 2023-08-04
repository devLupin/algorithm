#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

const int SZ = 55;
bool adj[SZ][SZ], vis[SZ];
vector<int> pres[50];
int n, a, b;

int bfs(int s) {
    int ret = 0;
    queue<pii> q;
    q.push({s, 0});
    vis[s] = true;

    while(!q.empty()) {
        pii cur = q.front();
        q.pop();

        ret = max(ret, cur.second);

        for(int i=1; i<=n; i++) {
            if(vis[i] || !adj[cur.first][i]) continue;
            vis[i] = true;
            q.push({i, cur.second+1});
        }
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    while (true) {
        cin >> a >> b;
        if (a == -1 && b == -1) break;
        adj[a][b] = adj[b][a] = true;
    }

    for (int i = 1; i <= n; i++) {
        fill_n(&vis[0], SZ, false);
        int cur = bfs(i);
        pres[cur].push_back(i);
    }

    for (int i = 1; i <= n; i++) {
        if (pres[i].empty()) continue;

        cout << i << ' ' << pres[i].size() << '\n';
        for (int x : pres[i]) cout << x << ' ';

        break;
    }

    return 0;
}