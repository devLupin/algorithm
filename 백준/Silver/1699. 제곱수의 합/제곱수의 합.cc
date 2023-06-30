#include <bits/stdc++.h>
using namespace std;

const int SZ = 100005;
int n, DP[SZ];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		DP[i] = i;
		for (int j = 1; j * j <= i; j++)
			DP[i] = min(DP[i - j * j] + 1, DP[i]);
	}

	cout << DP[n];
	return 0;
}