#include <bits/stdc++.h>
using namespace std;

const int SZ = 50;
int ans, n;
vector<int> pos, neg;

void sum(vector<int> v) {
	while (v.size() > 1) {
		int a = v.back();
		v.pop_back();
		int b = v.back();
		v.pop_back();

		ans += a * b;
	}
	if (v.size())
		ans += v.back();
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		if (tmp == 1) ans++;
		else if (tmp > 0) pos.push_back(tmp);
		else neg.push_back(tmp);
	}

	sort(pos.begin(), pos.end());
	sort(neg.begin(), neg.end(), greater<>());

	sum(pos);
	sum(neg);

	cout << ans;
	return 0;
}