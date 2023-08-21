#include <bits/stdc++.h>
using namespace std;
using ti3 = tuple<int,int,int>;

int a, b, c, n, m, P[100'002], ans, cnt;
ti3 adj[1'000'002];

int Find(int x) { return P[x] = (x == P[x] ? x : Find(P[x])); }
bool Union(int x, int y) {
	x = Find(x);
	y = Find(y);

	if(x == y) return false;
	P[x] = y;
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for(int i=0; i<m; i++) {
		cin >> a >> b >> c;
		adj[i] = {c, a, b};
	}

	for(int i=1; i<=n; i++) P[i] = i;
	sort(adj, adj+m);

	for(int i=0; i<m && n>2; i++) {
		tie(c, a, b) = adj[i];
		if(Union(a, b)) {
			ans += c;
			cnt++;
		}
		if(cnt == n-2) break;
	}
	cout << ans;

	return 0;
}