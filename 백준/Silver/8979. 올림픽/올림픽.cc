#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	vector<pii> v(n);
	vector<int> rank(n + 1);

	for (int i = 0; i < n; i++) {
		int c, g, s, b;
		cin >> c >> g >> s >> b;

		v[c - 1] = { ~(g * 3 + s * 2 + b), c };
	}

	sort(v.begin(), v.end());

	int cmp = v[0].first;
	int r = 1, cnt = 0;
	for (pii x : v) {
		if (cmp == x.first) {
			rank[x.second] = r;
			cnt++;
		}
		else {
			r += cnt;
			rank[x.second] = r;
			cmp = x.first;
		}
	}

	cout << rank[k];
	return 0;
}