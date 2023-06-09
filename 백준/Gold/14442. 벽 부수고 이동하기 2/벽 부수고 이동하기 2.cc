#include <bits/stdc++.h>
using namespace std;

const int SZ = 1000;
const int dy[] = { -1,1,0,0 };
const int dx[] = { 0,0,-1,1 };
int n, m, k;
char arr[SZ][SZ];
bool visited[SZ][SZ][10];

typedef struct {
	int y, x, d, k;
}Pos;

int bfs() {
	queue<Pos> q;
	q.push({ 0,0,1,0 });
	visited[0][0][0] = true;

	while (!q.empty()) {
		Pos cur = q.front();
		q.pop();

		if (cur.y == n - 1 && cur.x == m - 1) return cur.d;

		for (int dir = 0; dir < 4; dir++) {
			int ny = cur.y + dy[dir];
			int nx = cur.x + dx[dir];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;

			if (arr[ny][nx] == '0' && !visited[ny][nx][cur.k]) {
				q.push({ ny, nx, cur.d + 1, cur.k });
				visited[ny][nx][cur.k] = true;
			}
			if (arr[ny][nx] == '1' && cur.k < k && !visited[ny][nx][cur.k+1]) {
				q.push({ ny, nx, cur.d + 1, cur.k + 1 });
				visited[ny][nx][cur.k + 1] = true;
			}
		}
	}

	return -1;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];

	cout << bfs();
	return 0;
}