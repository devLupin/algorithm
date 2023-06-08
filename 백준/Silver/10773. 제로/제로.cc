#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	stack<int> st;
	int n, ans = 0; 
	cin >> n;

	while (n--) {
		int tmp; cin >> tmp;
		if (tmp == 0 && !st.empty()) st.pop();
		else st.push(tmp);
	}

	while (!st.empty()) {
		ans += st.top();
		st.pop();
	}

	cout << ans;
	return 0;
}