#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
using pii = pair<int, int>;

const int SZ = 505;

const int dx[] = { -1,1,0,0 };
const int dy[] = { 0,0,-1,1 };

int N, M, group[SZ][SZ];
bool vis[SZ][SZ];
int oil[SZ];
vector<vector<int>> board;
vector<int> group_cnt;

bool oom(int x, int y) { return x < 0 || y < 0 || x >= N || y >= M; }

int bfs(int x, int y, int gnum) {
	queue<pii> q;
	int ret = 0;

	q.push({ x, y });
	vis[x][y] = true;

	while (!q.empty()) {
		pii cur = q.front();
		q.pop();

		group[cur.X][cur.Y] = gnum;
		ret++;

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (!oom(nx, ny) && !vis[nx][ny] && board[nx][ny] == 1) {
				q.push({ nx, ny });
				vis[nx][ny] = true;
			}
		}
	}

	return ret;
}

int solution(vector<vector<int>> land) {
	N = land.size();
	M = land[0].size();
	board = land;
	group_cnt.push_back(0);

	int gnum = 1;
	for (int x = 0; x < N; x++)
		for (int y = 0; y < M; y++)
			if (!vis[x][y] && board[x][y] == 1) group_cnt.push_back(bfs(x, y, gnum++));

	int ans = 0;

	for (int y = 0; y < M; y++) {
		set<int> st;
		int cnt = 0;

		for (int x = 0; x < N; x++)
			st.insert(group[x][y]);

		for (int nxt : st)
			cnt += group_cnt[nxt];

		ans = max(ans, cnt);
	}

	return ans;
}