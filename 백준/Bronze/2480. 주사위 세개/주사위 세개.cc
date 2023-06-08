#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int arr[3], ans;
	cin >> arr[0] >> arr[1] >> arr[2];
	sort(arr, arr + 3);

	if (arr[0] == arr[2]) ans = 10000 + arr[0] * 1000;
	else if (arr[0] == arr[1]) ans = 1000 + arr[0] * 100;
	else if (arr[1] == arr[2]) ans = 1000 + arr[1] * 100;
	else ans = arr[2] * 100;

	cout << ans;
	return 0;
}