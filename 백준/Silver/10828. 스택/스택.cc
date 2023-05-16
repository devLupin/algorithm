#include <bits/stdc++.h>
using namespace std;



int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	stack<int> st;

	int N; cin >> N;
	while (N--) {
		string opt; cin >> opt;

		if (opt == "push") {
			int tmp; cin >> tmp;
			st.push(tmp);
		}
		else if (opt == "pop") {
			if (st.empty()) cout << -1 << '\n';
			else {
				cout << st.top() << '\n';
				st.pop();
			}
		}
		else if (opt == "size")
			cout << st.size() << '\n';
		else if (opt == "empty")
			cout << ((st.empty()) ? 1 : 0) << '\n';
		else
			cout << (!st.empty() ? st.top() : -1) << '\n';
	}
	
	return 0;
}