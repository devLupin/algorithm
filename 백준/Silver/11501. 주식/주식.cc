#include <bits/stdc++.h>
using namespace std;

int main(void) 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int tc; cin >> tc;
	while (tc--) {
		int n; cin >> n;
		vector<int> v(n);
		for (int i = 0; i < n; i++)
			cin >> v[i];

		int cmp = -1;
		long ans = 0;
		for (int i = n - 1; i >= 0; i--) {
			cmp = max(cmp, v[i]);
			ans += cmp - v[i];
		}

		cout << ans << '\n';
	}
	return 0;
}