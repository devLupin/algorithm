#include<bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long DP[91] = { 0, };
	DP[1] = 1;
	DP[2] = 1;

	int n; cin >> n;
	for (int i = 3; i <= n; i++)
		DP[i] = DP[i - 1] + DP[i - 2];

	cout << DP[n];
	return 0;
}