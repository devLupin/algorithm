#include <bits/stdc++.h>
using namespace std;

int n, m, h, ans = 0x3f3f3f;
int board[11][30];
bool vis[11][30];

bool check() {
	for(int i=1; i<=n; i++) {
		int cur = i;
		for(int j=1; j<=h; j++) {
			if(vis[cur][j]) cur = cur+1;
			else if(vis[cur-1][j]) cur = cur-1;
		}
		if(cur != i) return false;
	}
	return true;
}

void dfs(int idx, int cnt) {
	if(cnt > 3) return;

	if(check()) {
		ans = min(ans, cnt);
		return;
	}

	for(int i=idx; i<=h; i++) {
		for(int j=1; j<n; j++) {
			if(vis[j][i] || vis[j-1][i] || vis[j+1][i]) continue;

			vis[j][i] = true;
			dfs(i, cnt+1);
			vis[j][i] = false;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> h;
	for(int a, b, i=0; i<m; i++) {
		cin >> a >> b;
		vis[b][a] = true;
	}

	dfs(1, 0);
	cout << (ans > 3 ? -1 : ans);

	return 0;
}