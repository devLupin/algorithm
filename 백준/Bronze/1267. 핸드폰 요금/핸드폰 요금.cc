#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, cmp1 = 0, cmp2 = 0; 
	cin >> n;

	for (int tmp, i = 0; i < n; i++) {
		cin >> tmp;

		cmp1 += (tmp / 30 + 1) * 10;
		cmp2 += (tmp / 60 + 1) * 15;
	}

	if (cmp1 < cmp2) cout << "Y " << cmp1;
	else if (cmp1 == cmp2) cout << "Y M " << cmp1;
	else cout << "M " << cmp2;

	return 0;
}