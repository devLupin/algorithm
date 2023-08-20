#include <bits/stdc++.h>
using namespace std;

int n, DP[1002] = { 0, };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//입력
	int n;
	cin >> n;

	
	DP[1] = DP[3] = DP[4] = DP[5] = 1;
	DP[2] = 0;

	for (int i = 6; i <= n; i++) {
		if (DP[i - 1] == 0 || DP[i - 3] == 0 || DP[i - 4] == 0) DP[i] = 1;
		else DP[i] = 0;
	}

	if (DP[n] == 1) cout << "SK\n";
	else cout << "CY\n";

	return 0;
}