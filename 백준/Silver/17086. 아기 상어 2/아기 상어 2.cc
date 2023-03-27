#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

typedef pair<int, int> pii;
queue<pii> q;

int n, m;
int map[50][50];

const int dy[] = { -1,1,0,0,-1,1,-1,1 };
const int dx[] = { 0,0,-1,1,-1,-1,1,1 };

bool visited[50][50] = { false, };

void bfs() {
	while (!q.empty()) {
		int sz = q.size();
		while (sz--) {
			pii cur = q.front();
			q.pop();

			for (int dir = 0; dir < 8; dir++) {
				int ny = cur.first + dy[dir];
				int nx = cur.second + dx[dir];

				if (ny < 0 || nx < 0 || ny >= n || nx >= m)
					continue;
				if (map[ny][nx] == 0) {
					map[ny][nx] = map[cur.first][cur.second] + 1;
					q.push({ ny, nx });
				}
				else {
					int comp = map[cur.first][cur.second] + 1;
					map[ny][nx] = (map[ny][nx] < comp) ? map[ny][nx] : comp;
				}
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1)
				q.push({ i, j });
		}

	bfs();

	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			ans = (ans > map[i][j]) ? ans : map[i][j];

	cout << ans - 1;
}