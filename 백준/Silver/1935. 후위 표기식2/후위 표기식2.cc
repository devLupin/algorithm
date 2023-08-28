#include <bits/stdc++.h>
using namespace std;

int P[26];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	double ans = 0.0;
	string s;
	cin >> n >> s;

	for(int i=0; i<n; i++) cin >> P[i];

	stack<double> st;
	for(char c : s) {
		if(c >= 'A' && c <= 'Z') st.push(P[c - 'A']);
		else {
			double b = st.top(); st.pop();
			double a = st.top(); st.pop();
			double r;
			if(c == '+') r = a+b;
			else if(c == '-') r = a-b;
			else if(c == '*') r = a*b;
			else r = (double)a/b;

			ans = r;
			st.push(r);
		}
	}

	cout << fixed;
	cout.precision(2);
	cout << ans;

	return 0;
}