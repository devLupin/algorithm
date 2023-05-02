#include <iostream>
#include <queue>
using namespace std;
using pii = pair<int, int>;

const int dz[] = { -1,1,0,0,0,0 };
const int dy[] = { 0,0,-1,1,0,0 };
const int dx[] = { 0,0,0,0,-1,1 };

const int sz = 30;
char map[sz][sz][sz];
bool visited[sz][sz][sz];

int L, R, C;
typedef struct { int z, y, x, d; }pos;
pos src, dest;

int bfs() 
{
	queue<pos> q;
	q.push(src);
	visited[src.z][src.y][src.x] = true;
	while (!q.empty()) {
		pos cur = q.front();
		q.pop();

		if (cur.z == dest.z && cur.y == dest.y && cur.x == dest.x)
			return cur.d;

		for (int dir = 0; dir < 6; dir++) {
			int nz = cur.z + dz[dir];
			int ny = cur.y + dy[dir];
			int nx = cur.x + dx[dir];

			if (nz < 0 || ny < 0 || nx < 0 || nz > L || ny > R || nx > C)
				continue;
			if (visited[nz][ny][nx] || map[nz][ny][nx] != '.')
				continue;
			q.push({ nz, ny, nx, cur.d + 1 });
			visited[nz][ny][nx] = true;
		}
	}
	return -1;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (true) {
		cin >> L >> R >> C;
		if (L == 0 && R == 0 && C == 0)
			break;

		fill_n(&visited[0][0][0], sz * sz * sz, false);

		for (int z = 0; z < L; z++)
			for (int y = 0; y < R; y++)
				for (int x = 0; x < C; x++) {
					cin >> map[z][y][x];

					if (map[z][y][x] == 'S')
						src = { z,y,x,0 };
					if (map[z][y][x] == 'E') {
						dest = { z,y,x,0 };
						map[z][y][x] = '.';
					}
				}
		int ans = bfs();
		if (ans == -1) cout << "Trapped!" << '\n';
		else cout << "Escaped in " << ans << " minute(s)." << '\n';
	}
	return 0;
}