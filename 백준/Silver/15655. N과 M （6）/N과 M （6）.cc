#include <bits/stdc++.h>
using namespace std;

const int SZ = 10001;
int n, m, arr[SZ], v[SZ];
bool vis[SZ];

void solve(int cnt, int s) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) cout << v[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = s; i < n; i++) {
		if (vis[i]) continue;

		v[cnt] = arr[i];
		vis[i] = true;
		solve(cnt + 1, i + 1);
		v[cnt] = 0;
		vis[i] = false;
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	
	solve(0, 0);
	return 0;
}