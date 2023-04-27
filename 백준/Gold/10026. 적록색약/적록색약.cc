#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using pii = pair<int, int>;

const int dy[] = { -1,1,0,0 };
const int dx[] = { 0,0,-1,1 };

int n;
bool visited[100][100];

void bfs(vector<string> map, pii src) 
{
	queue<pii> q;
	q.push(src);
	visited[src.first][src.second] = true;

	while (!q.empty()) {
		pii cur = q.front();
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int ny = cur.first + dy[dir];
			int nx = cur.second + dx[dir];

			if (ny < 0 || nx < 0 || ny >= n || nx >= n)
				continue;
			if (!visited[ny][nx] && map[ny][nx] == map[cur.first][cur.second]) {
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

	cin >> n;
	vector<string> RGB(n);
	vector<string> GB(n);
	for (int i = 0; i < n; i++) {
		cin >> RGB[i];
		GB[i] = RGB[i];
		for (int j = 0; j < GB[i].size(); j++)
			if (GB[i][j] == 'R' || GB[i][j] == 'G')
				GB[i][j] = 'G';
	}

	int ans1 = 0;
	fill_n(&visited[0][0], 100 * 100, false);
	for (int i = 0; i < RGB.size(); i++) {
		for (int j = 0; j < RGB[i].size(); j++) {
			if (!visited[i][j]) {
				bfs(RGB, { i, j });
				ans1++;
			}
		}
	}

	int ans2 = 0;
	fill_n(&visited[0][0], 100 * 100, false);
	for (int i = 0; i < GB.size(); i++) {
		for (int j = 0; j < GB[i].size(); j++) {
			if (!visited[i][j]) {
				bfs(GB, { i, j });
				ans2++;
			}
		}
	}

	cout << ans1 << ' ' << ans2;
	return 0;
}