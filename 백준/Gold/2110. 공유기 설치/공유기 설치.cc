#include<bits/stdc++.h>
using namespace std;

const int SZ = 200000;
int n, c, arr[SZ];

bool check(int mid) {
	int cnt = 1;
	int prev = arr[0];

	for (int i = 1; i < n; i++) {
		if (arr[i] - prev >= mid) {
			prev = arr[i];
			cnt++;
		}
	}

	if (cnt >= c) return true;
	return false;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> c;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);

	int result = 0, low = 1, high = arr[n - 1] - arr[0];

	while (low <= high) {
		int mid = (low + high) / 2;

		if (check(mid)) {
			result = max(result, mid);
			low = mid + 1;
		}
		else high = mid - 1;
	}

	cout << result;
	return 0;
}