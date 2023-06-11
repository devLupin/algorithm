#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (true) {
		int n;
		cin >> n;

		if (n == 0) break;

		stack<pll> st;
		ll ans = 0;

		for (int i = 0; i < n; i++) {
			int h, idx = i;
			cin >> h;

			while (!st.empty() && st.top().first >= h) {
				ans = max(ans, (i - st.top().second) * st.top().first);
				idx = st.top().second;
				st.pop();
			}
			st.push({ h, idx });
		}

		while (!st.empty()) {
			ans = max(ans, (n - st.top().second) * st.top().first);
			st.pop();
		}
		cout << ans << '\n';
	}

	return 0;
}