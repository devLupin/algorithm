#include <bits/stdc++.h>
using namespace std;

int n, x, arr[2000001], ans;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int tmp, i = 0; i < n; i++) {
		cin >> tmp;
		arr[tmp]++;
	}
	cin >> x;

	for (int i = 0; i < (x + 1) / 2; i++)
		if (arr[i] == 1 && arr[x - i] == 1)
			ans++;

	cout << ans;
	return 0;
}