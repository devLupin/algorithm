#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int sum = 0, _min = 100;

	for (int tmp, i = 0; i < 7; i++) {
		cin >> tmp;
		
		if (tmp % 2 != 0) {
			sum += tmp;
			_min = min(_min, tmp);
		}
	}

	if (sum == 0) cout << -1;
	else cout << sum << '\n' << _min;
	return 0;
}