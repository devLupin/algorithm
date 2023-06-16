#include <bits/stdc++.h>
using namespace std;

const int SZ = 10;
int n, m, arr[SZ];

void solve(int cnt, int s) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) cout << arr[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = s; i <= n; i++) {
		arr[cnt] = i;
		solve(cnt + 1, i);
		arr[cnt] = 0;
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	solve(0, 1);
	return 0;
}