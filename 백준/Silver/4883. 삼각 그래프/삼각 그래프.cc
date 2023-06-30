#include <bits/stdc++.h>
using namespace std;

const int SZ = 100005;
int arr[SZ][4], DP[SZ][4];
int N, cnt = 1;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while(true) {
		cin >> N;
		if(N == 0) break;

		for(int i=0; i<N; i++)
			for(int j=1; j<=3; j++)
				cin >> arr[i][j];

		DP[0][1] = 1001;
		DP[0][2] = arr[0][2];
		DP[0][3] = arr[0][2] + arr[0][3];

		for(int i=1; i<N; i++) {
			DP[i][1] = arr[i][1] + min(DP[i-1][1], DP[i-1][2]);
			DP[i][2] = arr[i][2] + min({DP[i-1][1], DP[i-1][2], DP[i-1][3], DP[i][1]});
			DP[i][3] = arr[i][3] + min({DP[i-1][2], DP[i-1][3], DP[i][2]});
		}

		cout << cnt++ << ". " << DP[N-1][2] << '\n';
	}

	return 0;
}