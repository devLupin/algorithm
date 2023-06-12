#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (true) {
		string str;
		getline(cin, str);

		if (str == ".") break;

		stack<char> st;
		bool chk = true;
		
		for (char c : str) {
			if (c == '(' || c == '[') st.push(c);
			else if (c == ')') {
				if (st.empty() || st.top() != '(') {
					chk = false;
					break;
				}
				st.pop();
			}
			else if (c == ']') {
				if (st.empty() || st.top() != '[') {
					chk = false;
					break;
				}
				st.pop();
			}
		}

		if (!st.empty()) chk = false;

		cout << (chk ? "yes" : "no") << '\n';
	}

	return 0;
}