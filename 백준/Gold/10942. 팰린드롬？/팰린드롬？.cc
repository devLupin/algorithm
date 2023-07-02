#include <bits/stdc++.h>
using namespace std;

const int SZ = 2005;
int n, m, s, e, arr[SZ], DP[SZ][SZ];

void memo() {
	for (int i = 1; i <= n; i++) {
		DP[i][i] = 1;
		DP[i - 1][i] = arr[i - 1] == arr[i];
	}

	for (int i = n - 1; i >= 1; i--) {
		for (int j = i + 2; j <= n; j++) {
			if (arr[i] == arr[j] && DP[i + 1][j - 1])
				DP[i][j] = true;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	memo();

	cin >> m;
	while (m--) {
		cin >> s >> e;
		cout << DP[s][e] << '\n';
	}
	
	return 0;
}