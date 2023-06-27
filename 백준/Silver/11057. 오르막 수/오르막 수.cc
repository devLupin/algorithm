#include <bits/stdc++.h>
using namespace std;

const int SZ = 1000, MOD = 10007;
int n, DP[SZ][10];
long long ans;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;

	for(int i=0; i<10; i++)
		DP[0][i] = 1;

	for(int i=1; i<n; i++) {
		DP[i][0] = 1;
		for(int j=1; j<10; j++)
			DP[i][j] = (DP[i][j-1] + DP[i-1][j]) % MOD;
	}
	
	for(int i=0; i<10; i++)
		ans += DP[n-1][i] % MOD;

	cout << ans % MOD;
	return 0;
}