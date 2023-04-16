#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

const int dy[] = { -1,1,0,0 };
const int dx[] = { 0,0,-1,1 };

bool visited[100][100] = { false, };
int x_len, y_len;

int bfs(vector<string> maps, int sy, int sx, int cost)
{
	int ret = 0;

	queue<pii> q;
	q.push({ sy, sx });
	visited[sy][sx] = true;
	ret += cost;

	while (!q.empty()) {
		pii cur = q.front();
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int ny = cur.first + dy[dir];
			int nx = cur.second + dx[dir];

			if (ny < 0 || nx < 0 || ny >= y_len || nx >= x_len)
				continue;
			if (maps[ny][nx] != 'X' && !visited[ny][nx]) {
				q.push({ ny,nx });
				visited[ny][nx] = true;
				ret += (maps[ny][nx] - '0');
			}
		}
	}

	return ret;
}

vector<int> solution(vector<string> maps)
{
	vector<int> ret;
	y_len = maps.size();
	x_len = maps[0].size();

	for (int y = 0; y < y_len; y++) {
		for (int x = 0; x < x_len; x++) {
			if (maps[y][x] != 'X' && !visited[y][x]) {
				int temp = bfs(maps, y, x, (maps[y][x] - '0'));
				ret.push_back(temp);
			}
		}
	}

	sort(ret.begin(), ret.end());
	return (ret.size() ? ret : vector<int>{-1});
}