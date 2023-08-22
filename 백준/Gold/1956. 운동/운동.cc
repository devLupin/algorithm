#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int a, b, c, V, E, D[402][402];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> V >> E;
	for(int i=1; i<=V; i++) {
		fill(D[i]+1, D[i]+V+1, INF);
		D[i][i] = 0;
	}
	while(E--) {
		cin >> a >> b >> c;
		D[a][b] = c;
	}

	for(int k=1; k<=V; k++)
		for(int i=1; i<=V; i++)
			for(int j=1; j<=V; j++)
				D[i][j] = min(D[i][j], D[i][k] + D[k][j]);

	int ans = INF;
	for(int i=1; i<=V; i++)
		for(int j=i+1; j<=V; j++)
			ans = min(ans, D[i][j] + D[j][i]);

	cout << (ans == INF ? -1 : ans);

	return 0;
}