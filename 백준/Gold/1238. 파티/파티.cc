#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

const int SZ = 1002, INF = 0x3f3f3f3f;
int n, m, dest, ans;
vector<pii> adj[SZ];
bool vis[SZ];


int solve(int src, int dst) {
	int D[SZ];
	fill(D+1, D+n+1, INF);

	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({0, src});
	D[src] = 0;

	for(int u, v, w, dw; !pq.empty();) {
		tie(w, u) = pq.top();
		pq.pop();

		if(D[u] != w) continue;

		for(auto nxt : adj[u]) {
			tie(dw, v) = nxt;

			if(dw + w < D[v]) {
				D[v] = dw + w;
				pq.push({dw+w, v});
			}
		}
	}

	return D[dst];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> dest;
	for(int u, v, c; m--;) {
		cin >> u >> v >> c;
		adj[u].push_back({c, v});
	}

	int ans = 0;
	for(int i=1; i<=n; i++)
		ans = max(ans, solve(i, dest) + solve(dest, i));
	cout << ans;

	return 0;
}