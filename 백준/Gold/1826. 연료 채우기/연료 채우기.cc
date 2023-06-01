#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, fuel, ans = 0; 
	cin >> n;
	vector<pii> v(n+1);
	priority_queue<int> pq;

	for (int i = 0; i < n; i++)
		cin >> v[i].first >> v[i].second;
	cin >> v[n].first >> fuel;

	sort(v.begin(), v.end());

	for (int i = 0; i <= n; i++) {
		while (fuel < v[i].first) {
			if (pq.empty()) {
				cout << -1;
				return 0;
			}

			fuel += pq.top();
			pq.pop();
			ans++;
		}

		pq.push(v[i].second);
	}

	cout << ans;
	return 0;
}