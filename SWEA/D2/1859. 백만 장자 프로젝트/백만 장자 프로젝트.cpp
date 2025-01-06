/**
 * @author         lupin
 * @date           2025-01-06
 *
 * @submit         00:17:34
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
		stack<int> st;
		long long ans = 0;
		int N, mn = -1;

		cin >> N;

		for (int x, j = 0; j < N; j++)
		{
			cin >> x;
			st.push(x);
		}

		mn = st.top();
		st.pop();
		while (!st.empty())
		{
			if (st.top() <= mn) ans += mn - st.top();
			else mn = st.top();
			st.pop();
		}

		cout << '#' << i << ' ' << ans << '\n';
	}

	return 0;
}