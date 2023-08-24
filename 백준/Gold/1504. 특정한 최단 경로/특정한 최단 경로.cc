#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

const int SZ = 802, INF = 0x3f3f3f3f;
int n, m, a, b;
vector<pii> adj[SZ];

long long solve(int src, int dst) {
	int D[SZ];
	fill(D, D+n+1, INF);

	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({0, src});
	D[src] = 0;

	for(int u, v, w, dw; !pq.empty();) {
		tie(w, u) = pq.top();
		pq.pop();

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

	cin >> n >> m;
	for(int u, v, c; m--;) {
		cin >> u >> v >> c;
		adj[u].push_back({c, v});
		adj[v].push_back({c, u});
	}

	cin >> a >> b;
	long long tmp = min(solve(1,a) + solve(a,b) + solve(b,n), solve(1,b) + solve(b,a) + solve(a,n));
	cout << (tmp >= INF ? -1 : tmp);

	return 0;
}