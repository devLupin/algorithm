#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	stack<pii> st;
	int n;
	long long ans = 0;

	cin >> n;
	while (n--) {
		int h, cnt = 1;
		cin >> h;

		while (!st.empty() && st.top().first <= h) {
			ans += st.top().second;
			if (st.top().first == h) cnt += st.top().second;
			st.pop();
		}

		if (!st.empty()) ans++;
		st.push({ h, cnt });
	}
	
	cout << ans;
	return 0;
}