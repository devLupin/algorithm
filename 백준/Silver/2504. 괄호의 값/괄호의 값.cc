#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int num = 1, ans = 0;
	string str;
	cin >> str;

	stack<char> st;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') {
			num *= 2;
			st.push('(');
		}
		else if (str[i] == '[') {
			num *= 3;
			st.push('[');
		}

		else if (str[i] == ')') {
			if (st.empty() || st.top() != '(') {
				cout << "0";
				return 0;
			}

			if (str[i - 1] == '(') ans += num;
			num /= 2;
			st.pop();
		}
		else {
			if (st.empty() || st.top() != '[') {
				cout << "0";
				return 0;
			}

			if (str[i - 1] == '[') ans += num;
			num /= 3;
			st.pop();
		}
	}

	if (!st.empty()) cout << "0";
	else cout << ans;
}