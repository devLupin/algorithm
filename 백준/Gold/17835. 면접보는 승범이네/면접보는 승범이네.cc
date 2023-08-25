#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pli = pair<ll,int>;

const int SZ = 100'002;
int n, m, k;
ll Dist[SZ], INF = 0x7f7f7f7f7f7f;
vector<pli> adj[SZ];
priority_queue<pli, vector<pli>, greater<pli>> pq;

void solve() {
	while(!pq.empty()) {
		int u, v;
		ll w, dw;

		tie(w, u) = pq.top();
		pq.pop();

		if(Dist[u] != w) continue;

		for(auto nxt : adj[u]) {
			tie(dw, v) = nxt;
			dw += w;

			if(Dist[v] > dw) {
				Dist[v] = dw;
				pq.push({dw, v});
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	fill(Dist+1, Dist+n+1, INF);

	for(int u, v, w; m--;) {
		cin >> u >> v >> w;
		adj[v].push_back({w, u});
	}

	for(int u; k--;) {
		cin >> u;
		Dist[u] = 0;
		pq.push({0, u});
	}

	solve();

	int target_idx = max_element(Dist+1, Dist+n+1) - Dist;
	cout << target_idx << '\n' << Dist[target_idx];

	return 0;
}