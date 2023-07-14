#include <bits/stdc++.h>
#define Y first
#define X second
using namespace std;

const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};
const int SZ = 50;
int n, m, board[SZ][SZ], ans;

bool oom(int y, int x) {return y < 0 || x < 0 || y >= n || x >= m;}

void dfs(int y, int x, int d) {
	if(board[y][x] == 0) {
		board[y][x] = 2;
		ans++;
	}

	int ny, nx;

	for(int i=0; i<4; i++) {
		int nd = (d + 3 - i) % 4;
		tie(ny, nx) = make_pair(y + dy[nd], x + dx[nd]);

		if(!oom(ny, nx) && board[ny][nx] == 0) 
			dfs(ny, nx, nd);
	}

	int nd = (d + 2) % 4;
	tie(ny, nx) = make_pair(y + dy[nd], x + dx[nd]);

	if(oom(ny, nx) || board[ny][nx] == 1) {
		cout << ans;
		exit(0);
	}

	dfs(ny, nx, d);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int r, c, d;
	cin >> n >> m >> r >> c >> d;
	
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			cin >> board[i][j];

	dfs(r, c, d);
	return 0;
}