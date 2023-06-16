#include <bits/stdc++.h>
using namespace std;

const int SZ = 10001;
int n, m, arr[SZ], v[SZ];
bool vis[SZ];

void solve(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) cout << v[i] << ' ';
		cout << '\n';
		return;
	}

	int tmp = 0;
	for (int i = 0; i < n; i++) {
		if (vis[i] || tmp == arr[i]) continue;

		v[cnt] = arr[i];
		tmp = v[cnt];
		
		vis[i] = true;
		solve(cnt + 1);
		vis[i] = false;
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	
	solve(0);
	return 0;
}