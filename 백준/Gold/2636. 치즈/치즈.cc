#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

typedef struct {
	int y, x;
}pos;

int n, m;

const int dy[] = { -1,1,0,0 };
const int dx[] = { 0,0,-1,1 };

int map[101][101];
bool visited[101][101];

int lastRemain = 0;
int time = 0;

void bfs()
{
	queue<pos> del;

	queue<pos> q;

	while (true) {
		memset(visited, false, sizeof(visited));
		q.push({ 1,1 });

		while (!q.empty()) {
			pos cur = q.front();
			q.pop();

			for (int dir = 0; dir < 4; dir++) {
				int ny = cur.y + dy[dir];
				int nx = cur.x + dx[dir];

				if (ny < 0 || nx < 0 || ny >= n || nx >= m)
					continue;
				if (visited[ny][nx])
					continue;

				if (map[ny][nx] == 1) {
					del.push({ ny,nx });
					visited[ny][nx] = true;
					continue;
				}

				q.push({ ny,nx });
				visited[ny][nx] = true;
			}
		}
		if (del.size() == 0)
			break;

		lastRemain = del.size();

		while (!del.empty()) {
			pos cur = del.front();
			del.pop();

			map[cur.y][cur.x] = 0;
		}

		time++;
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int y = 0; y < n; y++)
		for (int x = 0; x < m; x++)
			cin >> map[y][x];

	bfs();
	cout << time << '\n' << lastRemain;
}