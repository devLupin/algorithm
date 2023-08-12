#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

const int INF = 987654321;
int V, E, K, u, v, w;
vector<pii> adj[20'002];
int vis[20'002];

struct comp {
    int v, w;
    comp(int _v, int _w) {v = _v, w = _w;}
    bool operator<(const comp &other) const {
        return w > other.w;
    }
};

void bfs() {
    priority_queue<comp> pq;
    pq.push({K, 0});
    vis[K] = 0;

    while(!pq.empty()) {
        auto cur = pq.top();
        pq.pop();

        for(auto nxt : adj[cur.v])
            if(vis[nxt.first] > cur.w + nxt.second) {
                pq.push({nxt.first, cur.w + nxt.second});
                vis[nxt.first] = cur.w + nxt.second;
            }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> V >> E >> K;
    while(E--) {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    fill(vis, vis+V+1, INF);
    bfs();

    for(int i=1; i<=V; i++) {
        if(vis[i] == INF) cout << "INF\n";
        else cout << vis[i] << '\n';
    }

    return 0;
}