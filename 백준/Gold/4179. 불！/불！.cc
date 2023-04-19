#include <iostream>
#include <queue>
#include <string>
using namespace std;
using pii = pair<int, int>;

typedef struct {
	int y, x, w;
}pos;

const int dy[] = { -1,1,0,0 };
const int dx[] = { 0,0,-1,1 };

const int SZ = 1001;

char map[SZ][SZ];
bool visited[SZ][SZ];
int r, c;

queue<pii> fire;
pos src;

void spread(void) 
{
	int sz = fire.size();
	while (sz--) {
		pii cur = fire.front();
		fire.pop();

		for (int dir = 0; dir < 4; dir++) {
			int ny = cur.first + dy[dir];
			int nx = cur.second + dx[dir];

			if (ny < 0 || nx < 0 || ny >= r || nx >= c)
				continue;
			if (map[ny][nx] == '.') {
				fire.push({ ny, nx });
				map[ny][nx] = 'F';
			}
		}
	}
}

int escape(void) 
{
	queue<pos> q;
	q.push(src);
	visited[src.y][src.x] = true;

	while (!q.empty()) {
		int q_sz = q.size();
		while (q_sz--) {
			pos cur = q.front();
			q.pop();

			if (map[cur.y][cur.x] == 'F')
				continue;

			if (cur.y == r - 1 || cur.y == 0 || cur.x == c - 1 || cur.x == 0)
				return cur.w + 1;

			for (int dir = 0; dir < 4; dir++) {
				int ny = cur.y + dy[dir];
				int nx = cur.x + dx[dir];

				if (ny < 0 || nx < 0 || ny >= r || nx >= c)
					continue;
				if (visited[ny][nx] || map[ny][nx] != '.')
					continue;

				q.push({ ny, nx, cur.w + 1 });
				visited[ny][nx] = true;
			}
		}
		spread();
	}

	return -1;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> r >> c;
	for (int y = 0; y < r; y++) {
		for (int x = 0; x < c; x++) {
			cin >> map[y][x];

			if (map[y][x] == 'J') {
				src = { y,x,0 };
				map[y][x] = '.';
			}
			if (map[y][x] == 'F')
				fire.push({ y,x });
		}
	}

	int res = escape();
	if (res < 0) cout << "IMPOSSIBLE";
	else cout << res;

	return 0;
}