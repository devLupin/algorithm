#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	sort(v.begin(), v.end());

	long ans = 0;
	for (int i = n - 1; i >= 0; i--) {
		int cur = v[i] * (n - i);
		if (ans < cur) ans = cur;
	}

	cout << ans;
	return 0;
}