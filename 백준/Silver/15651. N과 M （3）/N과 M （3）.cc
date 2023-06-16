#include <bits/stdc++.h>
using namespace std;

const int SZ = 10;
int n, m, arr[SZ];
bool vis[SZ];

void solve(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) cout << arr[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; i++) {
		arr[cnt] = i;
		solve(cnt + 1);
		arr[cnt] = 0;
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	solve(0);
	return 0;
}