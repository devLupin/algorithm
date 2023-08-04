#include <bits/stdc++.h>
using namespace std;

const int SZ = 20005;
int K, V, E, u, v;
vector<int> adj[SZ];
vector<int> color;

bool bfs() {
    color.assign(V+5, 0);

    for(int i=1; i<=V; i++) {
        if(color[i] != 0) continue;

        queue<int> q;
        q.push(i);
        color[i] = 1;

        while(!q.empty()) {
            int cur = q.front();
            q.pop();

            for(int nxt : adj[cur]) {
                if(color[nxt] != 0) {
                    if(color[nxt] == color[cur]) return false;
                    else continue;
                }
                color[nxt] = color[cur] * -1;
                q.push(nxt);
            }
        }
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> K;
    while(K--) {
        cin >> V >> E;
        for(int i=1; i<=V; i++)
            adj[i].clear();

        while(E--) {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cout << (bfs() ? "YES" : "NO") << '\n';
    }

    return 0;
}