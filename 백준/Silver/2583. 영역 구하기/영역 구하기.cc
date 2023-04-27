#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

const int dy[] = { -1,1,0,0 };
const int dx[] = { 0,0,-1,1 };
const int sz = 100;
bool visited[sz][sz];
char map[sz][sz];

int y, x, k;

typedef struct { int y, x, dist; }pos;

int bfs(pii src) {
	queue<pos> q;
	q.push({ src.first, src.second, 1 });
	visited[src.first][src.second] = true;

	int ret = 1;

	while (!q.empty()) {
		pos cur = q.front();
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int ny = cur.y + dy[dir];
			int nx = cur.x + dx[dir];

			if (ny < 0 || nx < 0 || ny >= y || nx >= x)
				continue;
			if (!visited[ny][nx] && map[ny][nx] == '0') {
				q.push({ ny, nx, cur.dist + 1 });
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

	fill_n(&map[0][0], sz * sz, '0');
	fill_n(&visited[0][0], sz * sz, false);

	cin >> y >> x >> k;
	while (k--) {
		int sx, sy, ex, ey;
		cin >> sx >> sy >> ex >> ey;

		for (int i = sy; i < ey; i++)
			for (int j = sx; j < ex; j++)
				map[i][j] = '1';
	}
	
	vector<int> ans;

	for (int i = 0; i < y; i++)
		for (int j = 0; j < x; j++)
			if (map[i][j] == '0' && !visited[i][j])
				ans.push_back(bfs({ i,j }));

	sort(ans.begin(), ans.end());

	cout << ans.size() << '\n';
	for (int n : ans)
		cout << n << ' ';

	return 0;
}