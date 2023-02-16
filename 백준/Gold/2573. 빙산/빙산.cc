#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

typedef struct {
	int y, x;
}pos;

const int dy[] = { -1,1,0,0 };
const int dx[] = { 0,0,-1,1 };

int map[300][300];
bool visited[300][300];

int n, m;
vector<pos> v;

void bfs(int sz)
{
	memset(visited, false, sizeof(visited));

	queue<pos> q;

	while (!v.empty()) {
		q.push(v.back());
		v.pop_back();
	}

	while (sz--) {
		pos cur = q.front();
		q.pop();
		visited[cur.y][cur.x] = true;

		for (int dir = 0; dir < 4; dir++) {
			int ny = cur.y + dy[dir];
			int nx = cur.x + dx[dir];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m)
				continue;
			if (!visited[ny][nx] && map[ny][nx] == 0) {
				if (map[cur.y][cur.x] == 0)
					break;
				(map[cur.y][cur.x])--;
			}
		}

		if (map[cur.y][cur.x] > 0)
			v.push_back({ cur.y,cur.x });
	}
}

void dfs(int y, int x)
{
	visited[y][x] = true;

	for (int dir = 0; dir < 4; dir++) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];

		if (ny < 0 || nx < 0 || ny >= n || nx >= m)
			continue;
		if (!visited[ny][nx] && map[ny][nx] != 0) {
			dfs(ny, nx);
		}
	}
}

int solve()
{
	int ans = 0;
	while (!v.empty()) {
		memset(visited, false, sizeof(visited));
		int cnt = 0;

		for (auto it = v.begin(); it != v.end(); it++) {
			auto cur = (*it);

			if (!visited[cur.y][cur.x] && map[cur.y][cur.x] != 0) {
				cnt++;
				dfs(cur.y, cur.x);
			}
		}

		if (cnt >= 2)
			return ans;

		bfs(v.size());
		ans++;
	}

	return 0;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int y = 0; y < n; y++)
		for (int x = 0; x < m; x++) {
			cin >> map[y][x];

			if (map[y][x] != 0)
				v.push_back({ y,x });
		}

	cout << solve();
}