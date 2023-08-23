#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f, SZ = 252;
int n, m, u, v, b, k;
int D[SZ][SZ];

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for(int i=1; i<=n; i++) {
		fill(D[i], D[i]+n+1, INF);
		D[i][i] = 0;
	}

	while(m--) {
		cin >> u >> v >> b;
		D[u][v] = 0;
		D[v][u] = !b;
	}

	for(int k=1; k<=n; k++)
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				D[i][j] = min(D[i][j], D[i][k]+D[k][j]);

	cin >> k;
	while(k--) {
		cin >> u >> v;
		cout << D[u][v] << '\n';
	}

	return 0;
}
