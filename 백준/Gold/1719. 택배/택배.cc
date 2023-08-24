#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f, SZ = 202;
int n, m, D[SZ][SZ], nxt[SZ][SZ];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for(int i=1; i<=n; i++) {
		fill(D[i]+1, D[i]+n+1, INF);
		D[i][i] = 0;
	}

	for(int u, v, c; m--;) {
		cin >> u >> v >> c;
		D[u][v] = D[v][u] = c;
		nxt[u][v] = v;
		nxt[v][u] = u;
	}

	for(int k=1; k<=n; k++)
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++) {
				if(D[i][j] > D[i][k]+D[k][j]) {
					D[i][j] = D[i][k]+D[k][j];
					nxt[i][j] = nxt[i][k];
				}
			}

	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			if(i==j) cout << "- ";
			else cout << nxt[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}