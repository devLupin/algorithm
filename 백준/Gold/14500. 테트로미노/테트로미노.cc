#include <bits/stdc++.h>
using namespace std;

const int SZ = 500;
const int dy[] = {-1,1,0,0};
const int dx[] = {0,0,-1,1};
int n, m, arr[SZ][SZ], ans;
bool vis[SZ][SZ];

bool oom(int y, int x) { return y < 0 || x < 0 || y >= n || x >= m; }

int f1(int y, int x) {
	if (oom(y, x) || oom(y + 1, x) || oom(y + 2, x) || oom(y + 1, x + 1)) 
		return 0;
	return arr[y][x] + arr[y + 1][x] + arr[y + 2][x] + arr[y + 1][x + 1];
}

int f2(int y, int x) {
	if (oom(y, x) || oom(y, x + 1) || oom(y, x + 2) || oom(y + 1, x + 1)) 
		return 0;
	return arr[y][x] + arr[y][x + 1] + arr[y][x + 2] + arr[y + 1][x + 1];
}

int f3(int y, int x) {
	if (oom(y, x) || oom(y, x + 1) || oom(y, x + 2) || oom(y - 1, x + 1)) 
		return 0;
	return arr[y][x] + arr[y][x + 1] + arr[y][x + 2] + arr[y - 1][x + 1];
}

int f4(int y, int x) {
	if (oom(y, x) || oom(y + 1, x) || oom(y + 2, x) || oom(y + 1, x - 1)) 
		return 0;
	return arr[y][x] + arr[y + 1][x] + arr[y + 2][x] + arr[y + 1][x - 1];
}

void dfs(int cnt, int sum, int y, int x) {
	if(cnt == 4) {
		ans = max(sum, ans);
		return;
	}

	for(int dir=0; dir<4; dir++) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];

		if(oom(ny, nx)) continue;
		if(vis[ny][nx]) continue;

		vis[ny][nx] = true;
		dfs(cnt + 1, sum + arr[ny][nx], ny, nx);
		vis[ny][nx] = false;
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			cin >> arr[i][j];

	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			vis[i][j] = true;
			dfs(1, arr[i][j], i, j);
			vis[i][j] = false;

			ans = max(f1(i, j), ans);
			ans = max(f2(i, j), ans);
			ans = max(f3(i, j), ans);
			ans = max(f4(i, j), ans);
		}
	}

	cout << ans;
	return 0;
}