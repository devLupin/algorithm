#include <bits/stdc++.h>
using namespace std;

const int DIV = 1000000000;
int n, DP[105][10];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;

	for(int i=1; i<10; i++) DP[1][i] = 1;
	
	for(int i=2; i<=n; i++) {
		for(int j=0; j<10; j++) {
			if(j != 0) DP[i][j] += DP[i-1][j-1];
			if(j != 9) DP[i][j] += DP[i-1][j+1];
			DP[i][j] %= DIV;
		}
	}

	long long ans = 0;
	for(int i=0; i<10; i++) ans += DP[n][i];

	cout << ans % DIV;
	return 0;
}