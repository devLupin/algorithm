#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ull a, b;
	cin >> a >> b;

	ull c = min(a, b);
	ull d = max(a, b);

	if (d - c > 0) {
		cout << d - c - 1 << '\n';
		for (ull i = c + 1; i < d; i++)
			cout << i << ' ';
	}
	else cout << 0;

	return 0;
}