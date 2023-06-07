#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, d, k, c, ans = 0;
	cin >> n >> d >> k >> c;

	vector<int> v(n);
	vector<bool> chk;

	for (int i = 0; i < n; i++)
		cin >> v[i];

	for (int i = 0; i < n; i++) {
		int cmp = 0;
		chk.assign(d + 1, false);

		for (int j = i; j < i + k; j++) {
			int cur = v[j % n];

			if (!chk[cur]) {
				cmp++;
				chk[cur] = true;
			}
		}
		if (!chk[c]) cmp++;
		ans = max(ans, cmp);
	}

	cout << ans;
	return 0;
}