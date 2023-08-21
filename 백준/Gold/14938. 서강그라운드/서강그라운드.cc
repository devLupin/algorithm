#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f, SZ = 102;
int n, m, r, T[SZ], ans, D[SZ][SZ];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> r;

	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			D[i][j] = (i==j ? 0 : INF);

	for(int i=1; i<=n; i++)
		cin >> T[i];

	for(int u, v, w; r--;) {
		cin >> u >> v >> w;
		D[v][u] = D[u][v] = min(D[u][v], w);
	}

	for(int k=1; k<=n; k++)
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				D[i][j] = min(D[i][j], D[i][k] + D[k][j]);

	for(int i=1; i<=n; i++) {
		int cmp = T[i];
		for(int j=1; j<=n; j++) {
			if(D[i][j] == INF || D[i][j] == 0 || D[i][j] > m) continue;
			cmp += T[j];
		}
		ans = max(ans, cmp);
	}

	cout << ans;

	return 0;
}