#include <bits/stdc++.h>
using namespace std;

const int SZ = 100001;
int DP[SZ];
int arr[SZ];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	DP[1] = arr[1];
	DP[2] = DP[1] + arr[2];

	for (int i = 3; i <= n; i++) {
		DP[i] = max(DP[i - 3] + arr[i - 1] + arr[i], DP[i - 2] + arr[i]);
		DP[i] = max(DP[i - 1], DP[i]);
	}
	
	cout << DP[n];
	return 0;
}