#include <bits/stdc++.h>
using namespace std;

int n, v, tmp, arr[202];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	while (n--) {
		cin >> tmp;
		arr[tmp + 100]++;
	}
	cin >> v;

	cout << arr[v + 100];
	return 0;
}