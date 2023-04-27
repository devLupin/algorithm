#include <iostream>
#include <queue>
using namespace std;
using pii = pair<int, int>;

const int dy[] = { -1,1,0,0 };
const int dx[] = { 0,0,-1,1 };
const int sz = 1001;
bool visited[sz][sz];
char map[sz][sz];

typedef struct { int y, x, dist; }pos;

queue<pii> spread(queue<pii> fire, int w, int h)
{
	int sz = fire.size();
	while (sz--) {
		pii cur = fire.front();
		fire.pop();

		for (int dir = 0; dir < 4; dir++) {
			int ny = cur.first + dy[dir];
			int nx = cur.second + dx[dir];

			if (ny < 0 || nx < 0 || ny >= h || nx >= w)
				continue;
			if (map[ny][nx] == '.') {
				fire.push({ ny,nx });
				map[ny][nx] = '*';
			}
		}
	}

	return fire;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int tc; cin >> tc;
	while (tc--) {
		fill_n(&visited[0][0], sz * sz, false);
		fill_n(&map[0][0], sz * sz, false);

		queue<pii> fire;
		pii src;

		int w, h; cin >> w >> h;
		for (int y = 0; y < h; y++)
			for (int x = 0; x < w; x++) {
				cin >> map[y][x];

				if (map[y][x] == '*')
					fire.push({ y,x });
				if (map[y][x] == '@') {
					src = { y,x };
					map[y][x] = '.';
				}
			}

		bool flag = false;
		queue<pos> q;
		q.push({ src.first, src.second, 0 });
		visited[src.first][src.second] = true;

		while (!q.empty()) {
			if (flag) break;

			fire = spread(fire, w, h);

			int sz = q.size();
			while (sz--) {
				pos cur = q.front();
				q.pop();

				if (cur.y == 0 || cur.x == 0 || cur.y == h - 1 || cur.x == w - 1) {
					cout << cur.dist + 1 << '\n';
					flag = true;
					break;
				}

				for (int dir = 0; dir < 4; dir++) {
					int ny = cur.y + dy[dir];
					int nx = cur.x + dx[dir];

					if (ny < 0 || nx < 0 || ny >= h || nx >= w)
						continue;
					if (!visited[ny][nx] && map[ny][nx] == '.') {
						q.push({ ny,nx, cur.dist + 1 });
						visited[ny][nx] = true;
					}
				}
			}
		}

		if (!flag) cout << "IMPOSSIBLE" << '\n';
	}
	
	return 0;
}