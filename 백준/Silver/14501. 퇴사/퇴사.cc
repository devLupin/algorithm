#include <bits/stdc++.h>
using namespace std;

const int SZ = 16;
int T[SZ], P[SZ], DP[SZ];
int n;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	for(int i=1; i<=n; i++)
		cin >> T[i] >> P[i];
	
	for(int i=n; i>=1; i--) {
		if(i+T[i] <= n+1) DP[i] = max(DP[i+T[i]]+P[i], DP[i+1]);
		else DP[i] = DP[i+1];
	}

	cout << *max_element(DP, DP+n+1);
	return 0;
}