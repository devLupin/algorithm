#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int ans = 0;
	string str;
	cin >> str;

	stack<char> st;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') st.push('(');
		else {
			if (str[i - 1] == '(') {
				st.pop();
				ans += st.size();
			}
			else {
				st.pop();
				ans++;
			}
		}
	}

	cout << ans;
}