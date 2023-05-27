#include<bits/stdc++.h>
using namespace std;

int R, C, ans = 0;
char arr[20][20];
bool visited[20][20];
bool alpha[26];

const int dy[] = { -1,1,0,0 };
const int dx[] = { 0,0,-1,1 };

void dfs(int y, int x, int dist)
{
	ans = max(ans, dist);

	for (int dir = 0; dir < 4; dir++) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];

		if (ny < 0 || nx < 0 || ny >= R || nx >= C)
			continue;
		
		char next = arr[ny][nx] - 'A';
		if (!visited[ny][nx] && !alpha[next]) {
			visited[ny][nx] = true;
			alpha[next] = true;
			dfs(ny, nx, dist + 1);
			visited[ny][nx] = false;
			alpha[next] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> R >> C;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			cin >> arr[i][j];

	visited[0][0] = true;
	alpha[arr[0][0] - 'A'] = true;
	dfs(0, 0, 1);

	cout << ans;
	return 0;
}