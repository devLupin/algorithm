#include <iostream>

using namespace std;

const int sz = 101;
int map[sz][sz];
long long dp[sz][sz];
int n;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
	dp[0][0] = 1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (dp[i][j] == 0 || (i == n - 1 && j == n - 1))
				continue;

			int val = map[i][j];
			int down = i + val;
			int right = j + val;

			if (down < sz) dp[down][j] += dp[i][j];
			if (right < sz) dp[i][right] += dp[i][j];
		}
	}

	cout << dp[n - 1][n - 1];
	return 0;
}