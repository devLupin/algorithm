#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

const int INF = 987654321, SZ = 1002;
int n, m, src, dest;
vector<pii> adj[SZ];
int dist[SZ], route[SZ];

void dijkstra() {
    priority_queue<pii> pq;
    pq.push({ 0, src });
    dist[src] = 0;

    while (!pq.empty()) {
        pii cur = pq.top();
        pq.pop();

        if(cur.first > dist[cur.second]) continue;

        for(pii nxt : adj[cur.second]) {
            int next = nxt.first;
            int nc = cur.first + nxt.second;

            if(dist[next] > nc) {
                pq.push({nc, next});
                dist[next] = nc;
                route[next] = cur.second;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int a, b, c; m--;) {
        cin >> a >> b >> c;
        adj[a].push_back({ b, c });
    }

    fill(dist, dist + n + 1, INF);

    cin >> src >> dest;

    dijkstra();
    cout << dist[dest] << '\n';

    vector<int> res;
    while(dest != 0) {
        res.push_back(dest);
        dest = route[dest];
    }

    cout << res.size() << '\n';
    for(auto it = res.rbegin(); it != res.rend(); it++)
        cout << (*it) << ' ';


    return 0;
}