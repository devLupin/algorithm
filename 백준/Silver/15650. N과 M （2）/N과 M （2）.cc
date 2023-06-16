#include <bits/stdc++.h>
using namespace std;

const int SZ = 10;
int n, m, arr[SZ];
bool vis[SZ];

set<vector<int>> s;

void solve(int cnt) {
	if (cnt == m) {
		vector<int> v;
		for (int i = 0; i < m; i++) v.push_back(arr[i]);
		sort(v.begin(), v.end());
		s.insert(v);
	}

	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			arr[cnt] = i;
			vis[i] = true;
			solve(cnt + 1);
			arr[cnt] = 0;
			vis[i] = false;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;

	solve(0);

	for (auto v : s) {
		for (auto a : v)
			cout << a << ' ';
		cout << '\n';
	}

	return 0;
}