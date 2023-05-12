#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int main(void) 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n; cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	sort(v.begin(), v.end());

	int start = 0, end = v.size() - 1;
	int ans = 0;

	while (start < end) {
		int back = v[end];
		int front = v[start];

		if (v[start] == 0) {
			start++;
			continue;
		}

		v[--end] += back;
		v[start]--;
		ans++;
	}

	

	cout << ans;
}