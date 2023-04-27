#include <iostream>
#include <queue>

using namespace std;
using pii = pair<int, int>;

const int dy[8] = { -1,-2,-2,-1,1,2,1,2 };
const int dx[8] = { -2,-1,1,2,-2,-1,2,1 };

bool visited[300][300];

typedef struct {
	int y, x, dist;
}pos;

int bfs(pii src, pii dest, int sz)
{
	fill_n(&visited[0][0], 300 * 300, false);
	
	queue<pos> q;
	q.push({ src.first, src.second, 0 });
	visited[src.first][src.second] = true;

	while (!q.empty()) {
		pos cur = q.front();
		q.pop();

		if (cur.y == dest.first && cur.x == dest.second)
			return cur.dist;

		for (int dir = 0; dir < 8; dir++) {
			int ny = cur.y + dy[dir];
			int nx = cur.x + dx[dir];

			if (visited[ny][nx] || ny < 0 || nx < 0 || ny >= sz || nx >= sz)
				continue;

			q.push({ ny, nx, cur.dist + 1 });
			visited[ny][nx] = true;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int tc; cin >> tc;
	while (tc--) {
		int sz, sx, sy, ex, ey;
		cin >> sz >> sx >> sy >> ex >> ey;
		cout << bfs({ sx, sy }, { ex, ey }, sz) << '\n';
	}

	return 0;
}