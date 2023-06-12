#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, ans = 0;
	cin >> n;

	while (n--) {
		bool chk = true;
		stack<char> st;
		string s;
		cin >> s;

		for (char c : s) {
			if (!st.empty() && st.top() == c) st.pop();
			else st.push(c);
		}

		if (!st.empty()) chk = false;
		if (chk) ans++;
	}

	cout << ans;
	return 0;
}