#include<bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	vector<int> arr(n), DP(k + 1);

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	DP[0] = 1;
	for (int tmp : arr)
		for (int j = tmp; j <= k; j++)
			DP[j] += DP[j - tmp];

	cout << DP[k];
	return 0;
}