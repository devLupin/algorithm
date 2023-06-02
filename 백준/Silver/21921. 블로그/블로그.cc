#include<bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, x;
	cin >> n >> x;

	vector<int> v(n + 1);
	vector<int> dp(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
		dp[i] = (i > 0) ? dp[i - 1] + v[i] : v[i];
	}

	int res = 0, cnt = 0;
	for (int i = x; i <= n; i++) {
		int prefix_sum = dp[i] - dp[i - x];

		if (res < prefix_sum) {
			res = prefix_sum;
			cnt = 1;
		}
		else if (res == prefix_sum) cnt++;
	}

	if (res == 0) cout << "SAD";
	else cout << res << '\n' << cnt;

	return 0;
}