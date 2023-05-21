#include <bits/stdc++.h>
using namespace std;

int n, DP[1001], arr[1001];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			DP[i] = max(DP[i], DP[i - j] + arr[j]);

	cout << DP[n];

	return 0;
}