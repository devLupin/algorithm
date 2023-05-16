#include <bits/stdc++.h>
using namespace std;

int arr[100000];
int N, M;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int len, sz = 1, ans = 0;
	int n; cin >> n;

	while (sz < n)
		sz *= 2;
	len = sz;

	while (n > 0) {
		if (n >= sz) n -= sz;
		else {
			sz /= 2;
			ans++;
		}
	}

	cout << len << ' ' << ans;
    return 0;
}