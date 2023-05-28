#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int TC; cin >> TC;
	while (TC--) {
		int a, b; cin >> a >> b;
		int tmp = 1;
		for (int i = 0; i < b; i++)
			tmp = (tmp * a) % 10;

		cout << (tmp == 0 ? 10 : tmp) << '\n';
	}
	return 0;
}