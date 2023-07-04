#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int n, src, dest, from, to, ans;
vector<pii> v;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	while (n--) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a, b });
	}

	sort(v.begin(), v.end());

	from = v[0].first;
	to = v[0].second;
	ans += abs(to - from);

	for (int i = 1; i < v.size(); i++) {
		src = v[i].first;
		dest = v[i].second;

		from = max(to, src);
		to = max(to, dest);

		ans += abs(to - from);
	}

	cout << ans;
	return 0;
}