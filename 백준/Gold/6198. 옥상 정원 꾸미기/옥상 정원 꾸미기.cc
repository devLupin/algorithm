#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	stack<ll> st;
	ll ans = 0, tmp;
	int n; 
	cin >> n;

	while (n--) {
		ll tmp;
		cin >> tmp;

		while (!st.empty() && st.top() <= tmp) 
			st.pop();

		ans += st.size();
		st.push(tmp);
	}

	cout << ans;
	return 0;
}