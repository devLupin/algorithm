#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int a, b, c, n, m, arr[102][102];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			arr[i][j] = (i==j ? 0 : INF);

	while(m--) {
		cin >> a >> b >> c;
		arr[a][b] = min(arr[a][b], c);
	}

	for(int k=1; k<=n; k++) 
		for(int i=1; i<=n; i++) 
			for(int j=1; j<=n; j++) 
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
	
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++)
			cout << (arr[i][j] == INF ? 0 : arr[i][j]) << ' ';
		cout << '\n';
	}

	return 0;
}