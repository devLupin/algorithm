#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, x;
	cin >> n >> x;
	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		if (tmp < x) cout << tmp << ' ';
	}

	return 0;
}