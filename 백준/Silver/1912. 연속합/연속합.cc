#include <bits/stdc++.h>
using namespace std;

const int SZ = 100001;
int DP[SZ];
int arr[SZ];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int ans;

	int n; cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	DP[0] = ans = arr[0];
	for (int i = 1; i < n; i++) {
		DP[i] = max(DP[i - 1] + arr[i], arr[i]);
		ans = max(ans, DP[i]);
	}
	
	cout << ans;
	return 0;
}