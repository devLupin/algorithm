#include <bits/stdc++.h>
#define Y first
#define X second
using namespace std;
using pii = pair<int,int>;

const int dy[] = {-1,1,0,0};
const int dx[] = {0,0,-1,1};
const int INF = 0x3f3f3f;

int n, m, board[50][50], ans = INF;
bool virus_chk[10], visited[50][50];
vector<pii> virus_avail;
vector<pii> virus_pos;

void bfs() {
	int ret = 0;
	queue<pii> q;

	for(pii pos : virus_pos) {
		q.push(pos);
		visited[pos.Y][pos.X] = true;
	}

	while(!q.empty()) {
		int q_sz = q.size();
		
		while(q_sz--) {
			pii cur = q.front();
			q.pop();

			for(int dir=0; dir<4; dir++) {
				int ny = cur.Y + dy[dir];
				int nx = cur.X + dx[dir];

				if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
				
				if(!visited[ny][nx] && board[ny][nx] != 1) {
					visited[ny][nx] = true;
					q.push({ny, nx});
				}
			}
		}

		if(q.size()) ret++;
	}

	bool chk = true;

	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(board[i][j] == 1) continue;
			if(!visited[i][j]) {
				chk = false;
				break;
			}
		}
	}		

	if(chk) ans = min(ans, ret);
}

void dfs(int cnt, int s) {
	if(cnt == m) {
		fill_n(&visited[0][0], 50*50, false);
		bfs();
		return;
	}

	for(int i=s; i<virus_avail.size(); i++) {
		if(!virus_chk[i]) {
			virus_chk[i] = true;
			virus_pos.push_back(virus_avail[i]);
			dfs(cnt+1, i);
			virus_chk[i] = false;
			virus_pos.pop_back();
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++) {
			cin >> board[i][j];
			if(board[i][j] == 2) virus_avail.push_back({i,j});
		}
	
	dfs(0, 0);
	cout << (ans == INF ? -1 : ans);
    return 0;
}