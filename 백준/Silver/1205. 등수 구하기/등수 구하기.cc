#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<ll> v;
	int n, target, p, ans = 0;
	cin >> n >> target >> p;

	if (n == 0) {
		cout << "1";
		return 0;
	}

	for (int i = 0; i < n; i++) {
		ll tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	sort(v.rbegin(), v.rend());

	if (v[v.size() - 1] >= target && v.size() == p) cout << "-1";
	else {
		v.push_back(target);
		sort(v.rbegin(), v.rend());

		for (int i = 0; i < v.size(); i++) {
			if (v[i] == target) {
				ans = i;
				break;
			}
		}

		cout << ans + 1;
	}

	return 0;
}