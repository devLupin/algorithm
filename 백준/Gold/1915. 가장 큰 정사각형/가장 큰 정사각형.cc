#include <bits/stdc++.h>
using namespace std;

const int SZ = 1005;
int n, m, DP[SZ][SZ];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for(int i=1; i<=n; i++)
		for (int j = 1; j <= m; j++) {
			char tmp; cin >> tmp;
			DP[i][j] = tmp - '0';
		}

	int biggest = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (DP[i][j]) {
				DP[i][j] = min({ DP[i][j - 1], DP[i - 1][j - 1], DP[i - 1][j] }) + 1;
				biggest = max(DP[i][j], biggest);
			}

	cout << biggest * biggest;
	return 0;
}