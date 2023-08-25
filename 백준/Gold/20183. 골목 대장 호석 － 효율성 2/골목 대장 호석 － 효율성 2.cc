#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pli = pair<ll, int>;

const ll INF = 0x7f7f7f7f7f7f7f;
int N, M, A, B;

vector<pli> adj[100'002];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll C, Cost[100'002], C_route[100'002];

	cin >> N >> M >> A >> B >> C;
	fill(Cost+1, Cost+N+1, INF);

	for(int u, v, w; M--;) {
		cin >> u >> v >> w;
		adj[u].push_back({w, v});
		adj[v].push_back({w, u});
	}

	priority_queue<pli, vector<pli>, greater<pli>> pq;
	pq.push({0, A});
	Cost[A] = 0;

	while(!pq.empty()) {
		int u, v;
		ll w, dw;

		tie(w, u) = pq.top();
		pq.pop();

		if(Cost[u] != w) continue;
		if(w > C) {
			Cost[u] = INF;
			continue;
		}

		for(auto nxt : adj[u]) {
			tie(dw, v) = nxt;

			if(dw + w > C) {
				Cost[v] = INF;
				continue;
			}
			if(dw + w < Cost[v]) {
				Cost[v] = dw + w;
				pq.push({dw + w, v});
				C_route[v] = max(C_route[u], dw);
			}
		}
	}

	if(Cost[B] == INF) cout << -1;
	else cout << C_route[B];

	return 0;
}