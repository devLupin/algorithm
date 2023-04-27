#include <iostream>
#include <queue>
using namespace std;
using pii = pair<int, int>;

const int dy[] = { -1,1,0,0 };
const int dx[] = { 0,0,-1,1 };

bool visited[50][50];
char map[50][50];

void bfs(pii src, int n, int m) {
	queue<pii> q;
	q.push(src);
	visited[src.first][src.second] = true;

	while (!q.empty()) {
		pii cur = q.front();
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int ny = cur.first + dy[dir];
			int nx = cur.second + dx[dir];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m)
				continue;
			if (!visited[ny][nx] && map[ny][nx] == '1') {
				q.push({ ny, nx });
				visited[ny][nx] = true;
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int tc; cin >> tc;
	while (tc--) {
		int n, m, k, ans = 0;
		cin >> m >> n >> k;

		fill_n(&visited[0][0], 50 * 50, false);
		fill_n(&map[0][0], 50 * 50, '0');

		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;
			map[y][x] = '1';
		}

		for (int y = 0; y < n; y++)
			for (int x = 0; x < m; x++)
				if (map[y][x] == '1' && !visited[y][x]) {
					bfs({ y, x }, n, m);
					ans++;
				}
		cout << ans << '\n';
	}
	return 0;
}