#include <bits/stdc++.h>
using namespace std;

int n;
const int SZ = 41;
int DP[SZ][2];

void fibonacci(void) {
	DP[0][0] = 1;
	DP[0][1] = 0;

	for (int i = 1; i < SZ; i++) {
		DP[i][0] = DP[i - 1][1];
		DP[i][1] = DP[i - 1][0] + DP[i - 1][1];
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	fibonacci();

	int TC; cin >> TC;
	while (TC--) {
		int n; cin >> n;
		cout << DP[n][0] << ' ' << DP[n][1] << '\n';
	}
	return 0;
}