#include <iostream>
#include <queue>
using namespace std;
using pii = pair<int, int>;

const int INF = 0x3f3f3f;
const int sz = 1001;
const int dy[] = { -1,1,0,0 };
const int dx[] = { 0,0,-1,1 };

int map[sz][sz];
int ans[sz][sz];

int n, m;

void bfs(pii src)
{
	queue<pii> q;
	q.push(src);
	
	while (!q.empty()) {
		pii cur = q.front();
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int ny = cur.first + dy[dir];
			int nx = cur.second + dx[dir];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m)
				continue;
			if (ans[ny][nx] != INF || map[ny][nx] != 1)
				continue;

			q.push({ ny, nx });
			ans[ny][nx] = ans[cur.first][cur.second] + 1;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;

	fill_n(&ans[0][0], sz * sz, INF);

	pii src;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				ans[i][j] = 0;
				src = { i,j };
			}
		}
	}
	
	bfs(src);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0 && ans[i][j] == INF) cout << 0 << ' ';
			else if (ans[i][j] == INF) cout << -1 << ' ';
			else cout << ans[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}