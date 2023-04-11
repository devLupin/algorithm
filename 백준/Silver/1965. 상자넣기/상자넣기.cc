#include <iostream>
using namespace std;

const int sz = 1003;
int arr[sz], dp[sz];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	fill_n(arr, sz, 0);
	fill_n(dp, sz, 0);

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		dp[i] = 1;
		for (int j = 1; j < i; j++) {
			if (arr[j] < arr[i] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
			}
		}
		ans = (ans > dp[i]) ? ans : dp[i];
	}

	cout << ans;
	return 0;
}