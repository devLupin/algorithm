#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int n, ans = 0;
int queen[15];
vector<pii> v;

bool chk(int cmp) {
	for (int i = 0; i < cmp; i++)
		if (queen[cmp] == queen[i] || cmp - i == abs(queen[cmp] - queen[i]))
			return false;
	return true;
}

void dfs(int row) {
	if (row == n) {
		ans++;
		return;
	}

	for (int i = 0; i < n; i++) {
		queen[row] = i;
		if (chk(row)) dfs(row + 1);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	dfs(0);

	cout << ans;
	return 0;
}