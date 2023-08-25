#include <bits/stdc++.h>
using namespace std;
using ti3 = tuple<int,int,int>;

const int SZ = 101;
const int dy[] = {-1,1,0,0};
const int dx[] = {0,0,-1,1};
char board[SZ][SZ];
bool vis[SZ][SZ];
int n, m, ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n;
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			cin >> board[i][j];

	deque<ti3> dq;
	dq.push_front({0,0,0});
	vis[0][0] = true;

	int y, x, c;
	while(!dq.empty()) {
		auto [y, x, c] = dq.front();
		dq.pop_front();

		if(y == n-1 && x == m-1) {
			ans = c;
			break;
		}

		for(int dir=0; dir<4; dir++) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];

			if(ny < 0 || nx < 0 || ny >= n || nx >=m) continue;
			if(!vis[ny][nx]) {
				if(board[ny][nx] == '0') dq.push_front({ny, nx, c});
				else dq.push_back({ny, nx, c+1});
				vis[ny][nx] = true;
			}
		}
	}

	cout << ans;

	return 0;
}