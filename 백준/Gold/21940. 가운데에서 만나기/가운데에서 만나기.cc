#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int a, b, t, n, m, k, D[202][202];
vector<int> C;
vector<pair<int,int>> res;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			D[i][j] = (i==j ? 0 : INF);

	while(m--) {
		cin >> a >> b >> t;
		D[a][b] = min(D[a][b], t);
	}
	cin >> k;
	while(k--) {
		cin >> a;
		C.push_back(a);
	}

	for(int k=1; k<=n; k++)
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				D[i][j] = min(D[i][j], D[i][k] + D[k][j]);

	for(int i=1; i<=n; i++) {
		int mx = 0;
		for(int j : C)
			mx = max(mx, D[i][j] + D[j][i]);
		res.push_back({mx, i});
	}

	sort(res.begin(), res.end());
	int x = res[0].first;
	for(auto y : res) if(x == y.first) cout << y.second << ' ';

	return 0;
}