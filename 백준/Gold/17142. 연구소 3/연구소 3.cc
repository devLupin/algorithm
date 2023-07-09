#include <bits/stdc++.h>
#define Y first
#define X second
using namespace std;
using pii = pair<int,int>;

const int dy[] = {-1,1,0,0};
const int dx[] = {0,0,-1,1};
const int SZ = 50, MX = 51*51;

int n, m, board[SZ][SZ];
vector<pii> virus;
bool vis[10];
int cnt_zero, ans = MX;
int bla;

int bfs() {
	int ret = 0;
	int zero = 0;

	int visited[SZ][SZ] = {false,};
	fill_n(&visited[0][0], SZ*SZ, -1);

	queue<pii> q;

	for(int i=0; i<virus.size(); i++)
		if(vis[i]) {
			auto cur = virus[i];
			q.push(cur);
			visited[cur.Y][cur.X] = 0;
		}

	while(!q.empty()) {
		int q_sz = q.size();
		while(q_sz--) {
			auto cur = q.front();
			q.pop();

			for(int dir=0; dir<4; dir++) {
				int ny = cur.Y + dy[dir];
				int nx = cur.X + dx[dir];

				if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
				if(board[ny][nx] == 1 || visited[ny][nx] >= 0) continue;
				
				q.push({ny, nx});
				visited[ny][nx] = visited[cur.Y][cur.X] + 1;
				if(board[ny][nx] == 0) {
					ret = visited[ny][nx];
					zero++;
				}
			}
		}
	}
	if(zero == cnt_zero) return ret;
	return MX;
}

void dfs(int cnt, int s) {
	if(cnt > m) return;

	int cmp = bfs();
	ans = min(ans, cmp);
	bla++;

	for(int i=s; i<virus.size(); i++) {
		auto cur = virus[i];
		
		if(!vis[i]) {
			auto cur = virus[i];

			vis[i] = true;
			dfs(cnt+1, i+1);
			vis[i] = false;
		}
	} 
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for(int i=0; i<n; i++) {
		for(int tmp, j=0; j<n; j++) {
			cin >> tmp;
			board[i][j] = tmp;
			if(tmp == 0) cnt_zero++;
			if(tmp == 2) virus.push_back({i, j});
		}
	}

	dfs(0, 0);

	cout << (ans == MX ? -1 : ans);
	return 0;
}