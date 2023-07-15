#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

const int sz = 21;
const int INF = 0x3f3f3f;

int n, m;
char map[sz][sz];
bool visited[sz][sz];
int record[11][11];

const int dy[] = { -1,1,0,0 };
const int dx[] = { 0,0,-1,1 };

typedef pair<int, int> pi;
typedef struct {
	int y, x, dist;
}pos;

int sy, sx;

vector<pi> dirty;

int bfs(pi src, pi dest)
{
	queue<pos> q;
	q.push({ src.first, src.second, 0 });
	visited[src.first][src.second] = true;

	while (!q.empty()) {
		pos cur = q.front();
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int ny = cur.y + dy[dir];
			int nx = cur.x + dx[dir];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m)
				continue;

			if (ny == dest.first && nx == dest.second) {
				while (!q.empty()) q.pop();
				return cur.dist + 1;
			}

			if (visited[ny][nx])
				continue;
			if (map[ny][nx] != 'x') {
				q.push({ ny,nx,cur.dist + 1 });
				visited[ny][nx] = true;
			}
		}
	}
	return -1;
}

int ans;
bool chk[11];
void dfs(int cur, int cnt, int dist_sum)
{
	if (cnt >= dirty.size() - 1) {
		ans = (ans > dist_sum) ? dist_sum : ans;
		return;
	}

	for (int i = 0; i < dirty.size(); i++) {
		if (i == cur || chk[i] || dist_sum + record[cur][i] > ans)
			continue;
		chk[i] = true;
		dfs(i, cnt + 1, dist_sum + record[cur][i]);
		chk[i] = false;
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	while (true) {
		cin >> m >> n;

		if (n == 0 && m == 0)
			break;

		memset(record, 0, sizeof(record));
		memset(chk, false, sizeof(chk));

		for (int y = 0; y < n; y++)
			for (int x = 0; x < m; x++) {
				cin >> map[y][x];

				if (map[y][x] == 'o') {
					sy = y;
					sx = x;

					map[y][x] = '*';
					dirty.push_back({ y,x });
				}
				else if (map[y][x] == '*')
					dirty.push_back({ y,x });
			}

		bool run = true;
		int start;
		for (int i = 0; i < dirty.size(); i++) {
			if (dirty[i].first == sy && dirty[i].second == sx)
				start = i;
			for (int j = 0; j < dirty.size(); j++) {
				if (i == j || record[i][j] != 0)
					continue;

				memset(visited, false, sizeof(visited));
				int distance = bfs(dirty[i], dirty[j]);

				if (distance > 0)
					record[i][j] = record[j][i] = distance;
				else {
					run = false;
					ans = -1;
					break;
				}
			}
		}

		
		if (run) {
			ans = INF;
			chk[start] = true;
			dfs(start, 0, 0);
		}
		cout << ans << '\n';
		
		while (!dirty.empty())dirty.pop_back();
	}
	return 0;
}