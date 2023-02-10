#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

typedef struct {
	int x, y, dist;
}pos;

const int dy[] = { -1,1,0,0 };
const int dx[] = { 0,0,-1,1 };

int n, m;
char map[100][100] = { 0, };
bool visited[100][100] = { false, };

int bfs() {
	queue<pos> q;
	q.push({ 0, 0, 1 });
	visited[0][0] = true;

	while (!q.empty()) {
		pos cur = q.front();
		q.pop();

		if (cur.x == n - 1 && cur.y == m - 1)
			return cur.dist;

		for (int dir = 0; dir < 4; dir++) {
			int ny = cur.y + dy[dir];
			int nx = cur.x + dx[dir];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m)
				continue;
			if (!visited[nx][ny] && map[nx][ny] == '1') {
				visited[nx][ny] = true;
				q.push({ nx, ny, cur.dist + 1 });
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];

	cout << bfs();
	return 0;
}