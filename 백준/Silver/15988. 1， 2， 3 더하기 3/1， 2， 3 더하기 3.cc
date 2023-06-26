#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 9;
const int SZ = 1e6 + 1;
int TC, n, DP[SZ] = {0, 1, 2, 4};

void memoization() {
	for(int i=4; i<SZ; i++)
		for(int j=1; j<=3; j++)
			DP[i] = (DP[i] + DP[i-j]) % MOD;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	memoization();

	cin >> TC;
	while(TC--) {
		cin >> n;
		cout << DP[n] << '\n';
	}
	
	return 0;
}