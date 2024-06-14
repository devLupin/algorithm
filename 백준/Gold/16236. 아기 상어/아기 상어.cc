#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define X first
#define Y second
using namespace std;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

const int SZ = 20;
const int INF = SZ * SZ * SZ;
const int dx[] = { -1,1,0,0 };
const int dy[] = { 0,0,-1,1 };

int N, board[SZ][SZ], ans;
int sx, sy, cnt, vol = 2;

bool oom(int x, int y) { return x < 0 || y < 0 || x >= N || y >= N; }

int bfs(int tx, int ty) {
	queue<tiii> q;
	bool vis[SZ][SZ] = { false, };

	q.push({ sx, sy, 0 });
	vis[sx][sy] = true;

	while (!q.empty()) {
		auto [x, y, d] = q.front();
		q.pop();
		if (x == tx && y == ty) return d;

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (!oom(nx, ny) && !vis[nx][ny] && board[nx][ny] <= vol) {
				q.push({ nx, ny, d + 1 });
				vis[nx][ny] = true;
			}
		}
	}

	return INF;
}

bool search() {
	int x, y, cmp = INF;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (board[i][j] > 0 && board[i][j] < vol) {
				int dist = bfs(i, j);

				if (dist < cmp) {
					cmp = dist;
					tie(x, y) = make_pair(i, j);
				}
			}

	if (cmp == INF) return false;
	
	board[x][y] = 0;
	tie(sx, sy) = make_pair(x, y);

	cnt++;
	if (cnt == vol) {
		cnt = 0;
		vol++;
	}

	ans += cmp;
	return true;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	//freopen("input.txt", "r", stdin);
	
	cin >> N;
	for(int i=0; i<N; i++)
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			if (board[i][j] == 9) {
				tie(sx, sy) = make_pair(i, j);
				board[i][j] = 0;
			}
		}

	while (search());
	
	cout << ans;
	return 0;
}