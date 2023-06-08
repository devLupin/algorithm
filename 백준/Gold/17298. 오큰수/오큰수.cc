#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, tmp;
	cin >> n;

	vector<int> v(n), ans(n);

	for (int i = 0; i < n; i++) cin >> v[i];

	stack<int> st;
	for (int i = v.size() - 1; i >= 0; i--) {
		while (!st.empty() && st.top() <= v[i]) st.pop();

		if (!st.empty()) ans[i] = st.top();
		else ans[i] = -1;

		st.push(v[i]);
	}

	for (int a : ans) cout << a << ' ';
	return 0;
}