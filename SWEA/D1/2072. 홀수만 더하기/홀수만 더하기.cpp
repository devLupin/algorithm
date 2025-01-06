/**
 * @author         lupin
 * @date           2025-01-06
 *
 * @submit         00:03:34
 */


#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	//freopen("input.txt", "r", stdin);

	int TC;
	cin >> TC;

	for (int i = 1; i <= TC; i++)
	{
		int sum = 0;
		for (int x, j = 0; j < 10; j++)
		{
			cin >> x;
			if (x % 2 != 0) sum += x;
		}
		cout << '#' << i << ' ' << sum << '\n';
	}

	return 0;
}