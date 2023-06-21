#include <bits/stdc++.h>
#define Y first
#define X second
using namespace std;
using pii = pair<int, int>;

const int W = 6, H = 12;
const int dy[] = { -1,1,0,0 };
const int dx[] = { 0,0,-1,1 };

bool chk, vis[H][W];
string board[H];

void explode(int y, int x) {
	queue<pii> q;
	vector<pii> tmp;

	q.push({ y, x });
	tmp.push_back({ y,x });
	vis[y][x] = true;

	while (!q.empty()) {
		pii cur = q.front();
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int ny = cur.Y + dy[dir];
			int nx = cur.X + dx[dir];

			if (ny < 0 || nx < 0 || ny >= H || nx >= W) continue;
			if (vis[ny][nx] || board[ny][nx] != board[cur.Y][cur.X]) continue;

			q.push({ ny,nx });
			tmp.push_back({ ny,nx });
			vis[ny][nx] = true;
		}
	}

	if (tmp.size() >= 4) {
		chk = true;

		for (pii pos : tmp)
			board[pos.Y][pos.X] = '.';
	}
}

void drop() {
	for (int i = 0; i < W; i++) {
		for (int j = H - 2; j >= 0; j--) {
			int tmp = j;
			while (tmp + 1 < H && board[tmp + 1][i] == '.') {
				swap(board[tmp][i], board[tmp + 1][i]);
				tmp++;
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < H; i++)
		cin >> board[i];

	int ans = 0;

	do {
		fill_n(&vis[0][0], H * W, false);
		chk = false;
		drop();

		for (int i = 0; i < H; i++) 
			for (int j = 0; j < W; j++) 
				if (!vis[i][j] && board[i][j] != '.')
					explode(i, j);

		if (chk) ans++;

	} while (chk);
	
	cout << ans;
	return 0;
}