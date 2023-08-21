#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using ti3 = tuple<int,int,int>;

int u, v, w, n, m, P[1'002];
vector<ti3> adj;

int Find(int x) { 
	return P[x] = (x == P[x] ? x : Find(P[x]));
}
bool Union(int x, int y) {
	if(x == y) return false;
	P[x] = y;
	return true;
}

int solve() {
	int cnt = 0, sum = 0;

	for(int i=0; i<=n; i++) P[i] = i;

	for(auto [w, u, v] : adj) {
		if(Union(Find(u), Find(v))) {
			sum += w;
			if(++cnt == n) break;
		}
	}

	return sum;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for(int i=0; i<m+1; i++) {
		cin >> u >> v >> w;
		adj.push_back({!w, u, v});
	}

	sort(adj.begin(), adj.end());
	int mn = solve();

	sort(adj.rbegin(), adj.rend());
	int mx = solve();

	cout << mx*mx - mn*mn;

	return 0;
}