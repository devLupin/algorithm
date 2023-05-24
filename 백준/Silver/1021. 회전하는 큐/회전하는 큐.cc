#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m; cin >> n >> m;
	deque<int> dq;
	for (int i = 1; i <= n; i++)
		dq.push_back(i);

	int ans = 0;

	for (int target, i = 0; i < m; i++) {
		cin >> target;
		int sz = dq.size();

		int idx = 1;
		for (auto it = dq.begin(); it != dq.end(); it++, idx++)
			if ((*it) == target) 
				break;
		
		int left = idx - 1;
		int right = sz - idx + 1;

		if (left < right) {
			while (left--) {
				dq.push_back(dq.front());
				dq.pop_front();
				ans++;
			}
			dq.pop_front();
		}
		else {
			while (right--) {
				dq.push_front(dq.back());
				dq.pop_back();
				ans++;
			}
			dq.pop_front();
		}
	}

	cout << ans;
	return 0;
}