#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000, SZ=5001;
string s;
int DP[SZ];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> s;
	s = ' ' + s;

	int len = s.size() - 1;
	DP[0] = 1;

	for(int i=1; i<=len; i++) {
		int c = s[i] - '0';
		if(c > 0) DP[i] = (DP[i] + DP[i-1]) % MOD;

		c += (s[i-1] - '0') * 10;
		if(c >= 10 && c <= 26) DP[i] = (DP[i] + DP[i-2]) % MOD;
	}

	cout << DP[len];
	return 0;
}