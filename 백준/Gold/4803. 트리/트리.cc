#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

const int SZ = 501;
int n, m, u, v, cnt;
vector<int> adj[SZ];
bool vis[SZ];

bool bfs(int start) {
    queue<pii> q;
    q.push({start, 0});
    vis[start] = true;

    while(!q.empty()) {
        pii cur = q.front();
        q.pop();

        for(int nxt : adj[cur.first]) {
            if(nxt == cur.second) continue;
            if(vis[nxt]) return false;
            vis[nxt] = true;
            q.push({nxt, cur.first});
        }
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while(++cnt) {
        cin >> n >> m;
        if(n==0 && m==0) break;

        for(int i=1; i<=n; i++) adj[i].clear();

        while(m--) {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int ans = 0;
        fill_n(&vis[0], n+1, false);
        for(int i=1; i<=n; i++) {
            if(vis[i]) continue;
            ans += bfs(i);
        }

        if(ans == 0) cout << "Case " << cnt << ": No trees.\n";
        else if(ans == 1) cout << "Case " << cnt << ": There is one tree.\n";
        else cout << "Case " << cnt << ": A forest of " << ans << " trees.\n";
    }

    return 0;
}