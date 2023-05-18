#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	int c = a % b;
	while (c != 0) {
		a = b;
		b = c;
		c = a % b;
	}
	return b;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	vector<int> tmp(n - 1);
	for (int i = 0; i < n - 1; i++)
		tmp[i] = v[i + 1] - v[i];

	int _gcd = tmp[0];
	for (int i = 1; i < tmp.size() - 1; i++)
		_gcd = gcd(_gcd, tmp[1]);

	int ans = 0;
	for (int i = 0; i < n - 1; i++)
		ans += (tmp[i] / _gcd - 1);

	cout << ans;
	return 0;
}