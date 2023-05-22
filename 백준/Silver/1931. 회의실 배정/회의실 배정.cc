#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	vector<pii> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i].second >> v[i].first;

	sort(v.begin(), v.end());

	int ans = 1, end = v[0].first;
	for (int i = 1; i < n; i++) {
		if (v[i].second >= end) {
			ans++;
			end = v[i].first;
		}
	}

	cout << ans;
	return 0;
}