#include<bits/stdc++.h>
using namespace std;

int n, m, TC, DP[31][31];

int bridge(int l, int r) {
	if (l == r || l == 0) return 1;
	if (DP[l][r] != 0) return DP[l][r];
	return DP[l][r] = bridge(l - 1, r - 1) + bridge(l, r - 1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> TC;
	while (TC--) {
		cin >> n >> m;
		cout << bridge(n, m) << '\n';
	}
	return 0;
}