#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

const int dy[] = { -1,1,0,0 };
const int dx[] = { 0,0,-1,1 };
const int INF = 0x3f3f3f;
const int sz = 1001;
int visited[sz][sz][2] = { 0, };
char map[sz][sz];
int n, m;

typedef struct { int y, x, crush; }pos;

int bfs(void) 
{
	queue<pos> q;
	q.push({ 0,0,0 });
	visited[0][0][0] = 1;

	while (!q.empty()) {
		pos cur = q.front();
		q.pop();

		if (cur.y == n - 1 && cur.x == m - 1)
			return visited[cur.y][cur.x][cur.crush];

		for (int dir = 0; dir < 4; dir++) {
			int ny = cur.y + dy[dir];
			int nx = cur.x + dx[dir];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m)
				continue;
			if (visited[ny][nx][cur.crush])
				continue;

			if (map[ny][nx] == '1' && !cur.crush) {
				q.push({ ny, nx, 1 });
				visited[ny][nx][1] = visited[cur.y][cur.x][cur.crush] + 1;
			}
			if (map[ny][nx] == '0') {
				q.push({ ny, nx, cur.crush });
				visited[ny][nx][cur.crush] = visited[cur.y][cur.x][cur.crush] + 1;
			}
		}
	}
	return -1;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];

	cout << bfs();
}