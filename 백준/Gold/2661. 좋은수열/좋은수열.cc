#include<bits/stdc++.h>
using namespace std;

int n;
string res;
bool flag = false;

void dfs(string s, int cnt) {
	if (flag) return;

	int sz = s.size();
	for (int i = 1; i <= sz / 2; i++)
		if (s.substr(sz - i, i) == s.substr(sz - i * 2, i))
			return;

	if (cnt == n) {
		res = s;
		flag = true;
	}

	for (int i = 0; i < n; i++) {
		dfs(s + "1", cnt + 1);
		dfs(s + "2", cnt + 1);
		dfs(s + "3", cnt + 1);
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	dfs("", 0);

	cout << res;
	return 0;
}