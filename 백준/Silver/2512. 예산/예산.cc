#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;

vector<int> v;
int n, m;

int binary_search() {
	sort(v.begin(), v.end());

	int left = 0, right = v[n - 1];
	int ret = 0;

	while (left <= right) {
		int mid = (left + right) / 2;
		int sum = 0;
		for (int i = 0; i < v.size(); i++) {
			if (mid < v[i]) sum += mid;
			else sum += v[i];
		}

		if (sum == m) return mid;
		if (sum > m) right = mid - 1;
		else left = mid + 1;

		if (sum < m) ret = max(ret, mid);
	}
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int tmp, i = 0; i < n; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}
	cin >> m;

	cout << binary_search();
	return 0;
}