#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int a, b, c, n, m;
int arr[102][102], nxt[102][102];

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
		nxt[a][b] = b;
	}

	for(int k=1; k<=n; k++)
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++) {
				if(arr[i][j] > arr[i][k] + arr[k][j]) {
					arr[i][j] = arr[i][k] + arr[k][j];
					nxt[i][j] = nxt[i][k];
				}
			}

	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++)
			cout << (arr[i][j] == INF ? 0 : arr[i][j]) << ' ';
		cout << '\n';
	}

	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			if(arr[i][j] == 0 || arr[i][j] == INF) {
				cout << "0\n";
				continue;
			}

			vector<int> path;
			int cur = i;
			while(cur != j) {
				path.push_back(cur);
				cur = nxt[cur][j];
			}
			path.push_back(j);

			cout << path.size() << ' ';
			for(int x : path) cout << x << ' ';
			cout << '\n';
		}
	}

	return 0;
}