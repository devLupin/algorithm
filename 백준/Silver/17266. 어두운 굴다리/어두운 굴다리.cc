#include<bits/stdc++.h>
using namespace std;

int n, m, light[100000];

bool check(int h) {
	int cmp = 0;

	for (int i = 0; i < m; i++) {
		if (light[i] - h <= cmp) cmp = light[i] + h;
		else break;
	}

	return n - cmp <= 0;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; i++) cin >> light[i];

	int left = 1, right = n, ans = 0;
	
	while (left <= right) {
		int mid = (left + right) / 2;

		if (check(mid)) {
			ans = mid;
			right = mid - 1;
		}
		else left = mid + 1;
	}

	cout << ans;
	return 0;
}