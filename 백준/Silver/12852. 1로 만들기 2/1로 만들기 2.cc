#include <bits/stdc++.h>
using namespace std;

const int SZ = 1000001;
int n, DP[SZ], pre[SZ];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	
	DP[1] = 0;
	for(int i=2; i<=n; i++) {
		DP[i] = DP[i-1] + 1;
		pre[i] = i-1;

		if(i%2 == 0 && DP[i] > DP[i/2]) {
			DP[i] = DP[i/2] + 1;
			pre[i] = i/2;
		}

		if(i%3 == 0 && DP[i] > DP[i/3]) {
			DP[i] = DP[i/3] + 1;
			pre[i] = i/3;
		}
	}

	cout << DP[n] << '\n';
	
	int idx = n;
	while(true) {
		cout << idx << ' ';
		if(idx == 1) break;
		idx = pre[idx];
	}

	return 0;
}