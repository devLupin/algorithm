#include <bits/stdc++.h>
using namespace std;

const int MOD = 15746;
const int SZ = 1000005;
int n;
long long DP[SZ];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;

	DP[1] = 1;
	DP[2] = 2;

	for(int i=3; i<=n; i++)
		DP[i] = (DP[i-2] + DP[i-1]) % MOD;	

	cout << DP[n];
	return 0;
}