#include <bits/stdc++.h>
using namespace std;

const int SZ = 100000;
int TC, n, arr[2][SZ], DP[2][SZ];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> TC;
	while(TC--) {
		cin >> n;
		for(int i=0; i<2; i++)
			for(int j=0; j<n; j++)
				cin >> arr[i][j];
		
		DP[0][0] = arr[0][0];
		DP[1][0] = arr[1][0];
		DP[0][1] = arr[0][1] + arr[1][0];
		DP[1][1] = arr[1][1] + arr[0][0];
		
		for(int i=2; i<n; i++) {
			DP[0][i] = arr[0][i] + max(DP[1][i-1], DP[1][i-2]);
			DP[1][i] = arr[1][i] + max(DP[0][i-1], DP[0][i-2]);
		}

		cout << max(DP[0][n-1], DP[1][n-1]) << '\n';
	}
	
	return 0;
}