#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int ans = 0, arr[10] = { 0, };
	string n;
	cin >> n;
	for (char c : n) arr[c - '0']++;

	for (int i = 0; i < 10; i++) {
		if (i == 6 || i == 9) continue;
		ans = max(ans, arr[i]);
	}

	ans = max(ans, (arr[6] + arr[9] + 1) / 2);
	cout << ans;
}