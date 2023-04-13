#include <iostream>
using namespace std;

int DP[1000001];

int memoization(int n) {
	DP[1] = 0;

	for (int i = 2; i <= n; i++) {
		DP[i] = DP[i - 1] + 1;
		if (i % 3 == 0) DP[i] = min(DP[i], DP[i / 3] + 1);
		if (i % 2 == 0) DP[i] = min(DP[i], DP[i / 2] + 1);
	}

	return DP[n];
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	cout << memoization(n);
	return 0;
}