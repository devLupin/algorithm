#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int dx[] = { -1,1,0,0 };
const int dy[] = { 0,0,-1,1 };

int n;
char map[25][25];
bool visited[25][25] = { false, };

int ret = 0;

void dfs(int x, int y) {
	ret++;

	visited[x][y] = true;

	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 0 || ny < 0 || nx >= n || ny >= n)
			continue;
		if (visited[nx][ny] || map[nx][ny] != '1')
			continue;

		dfs(nx, ny);
	}
}

vector<int> solve() {
	int sector = 0;
	vector<int> v;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (map[i][j] == '1' && !visited[i][j]) {
				dfs(i, j);
				v.push_back(ret);
				ret = 0;
			}
		}
	sort(v.begin(), v.end());
	return v;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];

	auto ret = solve();
	cout << ret.size() << '\n';
	for (int i = 0; i < ret.size(); i++)
		cout << ret[i] << '\n';

	return 0;
}