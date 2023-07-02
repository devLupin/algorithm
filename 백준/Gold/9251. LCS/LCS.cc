#include <bits/stdc++.h>
using namespace std;

const int SZ = 1001;
int DP[SZ][SZ];
string s1, s2;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> s1 >> s2;

	for (int i = 1; i <= s1.size(); i++) {
		for (int j = 1; j <= s2.size(); j++) {
			if (s1[i - 1] == s2[j - 1]) DP[i][j] = DP[i - 1][j - 1] + 1;
			else DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
		}
	}

	cout << DP[s1.size()][s2.size()];
	return 0;
}