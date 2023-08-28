#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;

	stack<char> st;

	for(char c : s) {
		if(c >= 'A' && c <= 'Z') cout << c;
		else {
			if(c == '(') st.push(c);
			else if(c == ')') {
				while(!st.empty() && st.top() != '(') {
					cout << st.top();
					st.pop();
				}
				st.pop();
			}
			else if(c == '*' || c == '/') {
				while(!st.empty() && (st.top() == '*' || st.top() == '/')) {
					cout << st.top();
					st.pop();
				}
				st.push(c);
			}
			else if(c == '+' || c == '-') {
				while(!st.empty() && st.top() != '(') {
					cout << st.top();
					st.pop();
				}
				st.push(c);
			}
		}
	}
	while(!st.empty()) {
		cout << st.top();
		st.pop();
	}

	return 0;
}