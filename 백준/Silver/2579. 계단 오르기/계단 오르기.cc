#include <iostream>
using namespace std;

int stair[301] = { 0, };
int dp[301] = { 0, };

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> stair[i];

	dp[0] = stair[0];
	dp[1] = max(stair[0] + stair[1], stair[1]);
	dp[2] = max(stair[0] + stair[2], stair[1] + stair[2]);

	for (int i = 3; i < n; i++) {
		dp[i] = max(dp[i - 2] + stair[i], dp[i - 3] + stair[i - 1] + stair[i]);
	}

	cout << dp[n-1];

	return 0;
}