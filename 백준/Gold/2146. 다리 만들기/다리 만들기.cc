#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

typedef struct {
	int y, x, dist;
}Pos;

const int dy[] = { -1,1,0,0 };
const int dx[] = { 0,0,-1,1 };
const int SZ = 100, INF = 0x3f3f3f;
int n, ans = INF, division = 1;
pii arr[SZ][SZ];
bool visited[SZ][SZ];
bool tmp[SZ][SZ];

void get_division(int sy, int sx) {
	queue<pii> q;
	q.push({ sy, sx });
	visited[sy][sx] = true;
	arr[sy][sx].second = division;

	while (!q.empty()) {
		pii cur = q.front();
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int ny = cur.first + dy[dir];
			int nx = cur.second + dx[dir];

			if (ny < 0 || nx < 0 || ny >= n || nx >= n)
				continue;
			if (!visited[ny][nx] && arr[ny][nx].first == 1) {
				arr[ny][nx].second = division;
				q.push({ ny,nx });
				visited[ny][nx] = true;
			}
		}
	}
}

int get_distance(pii src, int cur_division) {
	fill_n(&visited[0][0], SZ * SZ, false);

	queue<Pos> q;
	q.push({ src.first, src.second, 1 });
	visited[src.first][src.second] = true;

	while (!q.empty()) {
		Pos cur = q.front();
		q.pop();

		if (arr[cur.y][cur.x].first == 1 && arr[cur.y][cur.x].second != cur_division)
			return cur.dist - 1;

		for (int dir = 0; dir < 4; dir++) {
			int ny = cur.y + dy[dir];
			int nx = cur.x + dx[dir];

			if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
			if (arr[ny][nx].second != cur_division && !visited[ny][nx]) {
				q.push({ ny,nx, cur.dist + 1 });
				visited[ny][nx] = true;
			}
		}
	}

	return INF;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j].first;
			arr[i][j].second = 0;
		}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j].first == 1 && !visited[i][j]) {
				get_division(i, j);
				division++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j].first == 1) {
				for (int dir = 0; dir < 4; dir++) {
					int ny = i + dy[dir];
					int nx = j + dx[dir];

					if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
					if (arr[ny][nx].first == 0 && !tmp[ny][nx]) {
						int dist = get_distance({ ny,nx }, arr[i][j].second);
						tmp[ny][nx] = true;

						ans = min(ans, dist);
					}
				}
			}
		}
	}

	cout << ans;
	return 0;
}