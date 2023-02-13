#include <iostream>
#include <queue>
using namespace std;

const int dz[] = { -1,1,0,0,0,0 };
const int dy[] = { 0,0,-1,1,0,0 };
const int dx[] = { 0,0,0,0,-1,1 };

int m, n, h;

int map[101][101][101];

typedef struct {
	int z, y, x;
}pos;
queue<pos> q;


void spread(int sz) {
	while (sz--) {
		pos cur = q.front();
		q.pop();

		for (int dir = 0; dir < 6; dir++) {
			int nz = cur.z + dz[dir];
			int ny = cur.y + dy[dir];
			int nx = cur.x + dx[dir];

			if (nz < 0 || ny < 0 || nx < 0 || nz >= h || ny >= n || nx >= m)
				continue;

			if (map[nz][ny][nx] == 0) {
				q.push({ nz,ny,nx });
				map[nz][ny][nx] = 1;
			}
		}
	}
}

int solution() {
	int ret = 0;

	while (!q.empty()) {
		spread(q.size());
		ret++;
	}

	for (int z = 0; z < h; z++)
		for (int y = 0; y < n; y++)
			for (int x = 0; x < m; x++)
				if (map[z][y][x] == 0)
					return -1;
	return ret - 1;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> m >> n >> h;

	for (int z = 0; z < h; z++)
		for (int y = 0; y < n; y++)
			for (int x = 0; x < m; x++) {
				cin >> map[z][y][x];

				if (map[z][y][x] == 1)
					q.push({ z,y,x });
			}

	cout << solution();
	return 0;
}