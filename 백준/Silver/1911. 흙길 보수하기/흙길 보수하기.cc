#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

using pii = pair<int, int>;
int n, l;

int solution(vector<pii> v) {
	sort(v.begin(), v.end());

	int idx = 0, cnt = 0;
	for (pii p : v) {
		if (idx >= p.second)
			continue;

		idx = max(idx, p.first);
		double temp = double(p.second - idx) / l;
		cnt += ceil(temp);
		idx += ceil(temp) * l;
	}

	return cnt;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> l;
	vector<pii> v(n);

	for (int i = 0; i < n; i++)
		cin >> v[i].first >> v[i].second;

	cout << solution(v);
	return 0;
}