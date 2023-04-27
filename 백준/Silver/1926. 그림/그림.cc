#include <iostream>
#include <queue>
using namespace std;
using pii = pair<int, int>;

int y, x;
int map[500][500];
bool visited[500][500] = { false, };

const int dy[] = { -1,1,0,0 };
const int dx[] = { 0,0,-1,1 };

int bfs(pii src) {
	int ret = 1;

	queue<pii> q;
	q.push({ src.first, src.second });
	visited[src.first][src.second] = true;

	while (!q.empty()) {
		pii cur = q.front();
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int ny = cur.first + dy[dir];
			int nx = cur.second + dx[dir];

			if (visited[ny][nx] || ny < 0 || nx < 0 || ny >= y || nx >= x)
				continue;
			if (map[ny][nx] == 1) {
				q.push({ ny,nx });
				visited[ny][nx] = true;
				ret++;
			}
		}
	}

	return ret;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int cnt = 0, biggest = 0;

	cin >> y >> x;
	for (int i = 0; i < y; i++)
		for (int j = 0; j < x; j++)
			cin >> map[i][j];

	for (int i = 0; i < y; i++)
		for (int j = 0; j < x; j++) {
			if (!visited[i][j] && map[i][j] == 1) {
				int ret = bfs({ i,j });
				biggest = max(biggest, ret);
				cnt++;
			}
		}

	cout << cnt << '\n' << biggest;
	return 0;
}