#include <bits/stdc++.h>
using namespace std;

const int SZ = 1001, INF = 0x3f3f3f;
int arr[SZ][3], memo[SZ][3];
int n;

void DP() {
	fill_n(&memo[0][0], SZ * 3, INF);

	memo[1][0] = arr[1][0];
	memo[1][1] = arr[1][1];
	memo[1][2] = arr[1][2];
	
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				if (j == k) continue;
				memo[i][j] = min(memo[i][j], arr[i][j] + memo[i - 1][k]);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int r, g, b; cin >> r >> g >> b;
		arr[i][0] = r;
		arr[i][1] = g;
		arr[i][2] = b;
	}

	DP();
	cout << min(memo[n][0], min(memo[n][1], memo[n][2]));

	return 0;
}