#include <bits/stdc++.h>
using namespace std;

int n, k, arr[2][7], ans = 0;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	for (int s, y, i = 0; i < n; i++) {
		cin >> s >> y;
		arr[s][y]++;
	}

	for (int i = 1; i < 7; i++) {
		if (arr[0][i] % k != 0) ans++;
		if (arr[1][i] % k != 0) ans++;
		ans += (arr[0][i]) / k;
		ans += (arr[1][i]) / k;
	}

	cout << ans;
	return 0;
}