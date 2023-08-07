#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

const int SZ = 1'005;
int n, m, u, v, d;
vector<pii> adj[SZ];
bool vis[SZ];

int bfs(int src, int dest) {
    queue<pii> q;
    q.push({src, 0});
    vis[src] = true;

    while(!q.empty()) {
        pii cur = q.front();
        q.pop();

        if(cur.first == dest) return cur.second;

        for(pii tmp : adj[cur.first]) {
            int nxt = tmp.first;
            int d = tmp.second;

            if(vis[nxt]) continue;

            q.push({nxt, cur.second+d});
            vis[nxt] = true;
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    while(--n) {
        cin >> u >> v >> d;
        adj[u].push_back({v, d});
        adj[v].push_back({u, d});
    }

    while(m--) {
        cin >> u >> v;
        cout << bfs(u, v) << '\n';
        fill(vis, vis+SZ, false);
    }

    return 0;
}