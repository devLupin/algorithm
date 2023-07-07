#include <bits/stdc++.h>
#define Y first
#define X second
using namespace std;
using pii = pair<int,int>;

vector<pii> cctv;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int board[8][8];
int n, m, ans = 64;


void check(int y, int x, int dir) {
	dir %= 4;

	while(true) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];

		tie(y, x) = {ny, nx};

		if(ny < 0 || nx < 0 || ny >= n || nx >= m) return;
		if(board[y][x] == 6) return;
		
		if(board[y][x] == 0) board[y][x] = 7; 
	}
}

void solve(int cnt) {
	if(cnt == cctv.size()) {
		int cmp = 0;

		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				cmp += (board[i][j] == 0);

		ans = min(ans, cmp);
		return;
	}

	int y = cctv[cnt].Y;
	int x = cctv[cnt].X;

	int cpy[8][8];

	for(int dir=0; dir<4; dir++) {
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				cpy[i][j] = board[i][j];

		if(board[y][x] == 1)
			check(y, x, dir);

		else if(board[y][x] == 2) {
			check(y, x, dir);
			check(y, x, dir+2);
		}

		else if(board[y][x] == 3) {
			check(y, x, dir);
			check(y, x, dir+3);
		}

		else if(board[y][x] == 4) {
			check(y, x, dir);
			check(y, x, dir+1);
			check(y, x, dir+3);
		}

		else if(board[y][x] == 5) {
			check(y, x, dir);
			check(y, x, dir+1);
			check(y, x, dir+2);
			check(y, x, dir+3);
		}

		solve(cnt + 1);

		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				board[i][j] = cpy[i][j];
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++) {
			cin >> board[i][j];

			if(board[i][j] >= 1 && board[i][j] <= 5)
				cctv.push_back({i,j});
		}

	solve(0);
	cout << ans;
	return 0;
}