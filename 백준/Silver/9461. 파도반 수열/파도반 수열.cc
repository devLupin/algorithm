#include <iostream>
using namespace std;
using ull = unsigned long long;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	ull dp[101] = { 0, };
	dp[1] = dp[2] = dp[3] = 1;

	for (int i = 4; i < 101; i++)
		dp[i] = dp[i - 3] + dp[i - 2];

	int T;
	cin >> T;

	while (T--) {
		ull temp;
		cin >> temp;
		cout << dp[temp] << '\n';
	}

	return 0;
}