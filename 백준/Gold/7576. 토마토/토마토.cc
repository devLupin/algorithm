#include <iostream>
#include <queue>
using namespace std;

int n, m;
int map[1000][1000];

const int dy[] = { -1,1,0,0 };
const int dx[] = { 0,0,-1,1 };

typedef pair<int, int> pii;
queue<pii> q;

int bfs() {
	int ret = 0;

	while (!q.empty()) {
		bool chk = false;
		int q_sz = q.size();

		while (q_sz--) {
			pii cur = q.front();
			q.pop();

			for (int dir = 0; dir < 4; dir++) {
				int ny = cur.first + dy[dir];
				int nx = cur.second + dx[dir];

				if (ny < 0 || nx < 0 || ny >= n || nx >= m)
					continue;
				if (map[ny][nx] == 0) {
					map[ny][nx] = 1;
					q.push({ ny, nx });
					chk = true;
				}
			}
		}
		ret++;
	}

	return ret;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> m >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1)
				q.push({ i, j });
		}

	int ans = bfs();

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (map[i][j] == 0) {
				ans = 0;
				break;
			}

	cout << ans - 1;
	return 0;
}