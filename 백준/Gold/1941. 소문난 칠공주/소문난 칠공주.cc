#include <bits/stdc++.h>
#define Y first
#define X second
using namespace std;
using pii = pair<int, int>;

const int SZ = 5;
const int dy[] = { -1,1,0,0 };
const int dx[] = { 0,0,-1,1 };
string board[SZ];
bool mask[SZ * SZ], vis[SZ][SZ], conn[SZ][SZ];

bool is_correct(pii src) {
	queue<pii> q;
	q.push(src);
	vis[src.Y][src.X] = true;

	int adj = 0, dasom = 0;

	while (!q.empty()) {
		pii cur = q.front();
		q.pop();

		adj++;
		dasom += board[cur.Y][cur.X] == 'S';

		for (int dir = 0; dir < 4; dir++) {
			int ny = cur.Y + dy[dir];
			int nx = cur.X + dx[dir];

			if (ny < 0 || nx < 0 || ny >= SZ || nx >= SZ) continue;
			if (!conn[ny][nx] || vis[ny][nx]) continue;

			q.push({ ny, nx });
			vis[ny][nx] = true;
		}
	}

	return adj == 7 && dasom >= 4;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int ans = 0;

	for (int i = 0; i < SZ; i++)
			cin >> board[i];

	fill(mask + 7, mask + SZ * SZ, true);
	do {
		fill_n(&vis[0][0], SZ * SZ, false);
		fill_n(&conn[0][0], SZ * SZ, false);

		pii src = { -1,-1 };

		for (int i = 0; i < SZ * SZ; i++) {
			if (!mask[i]) {
				int y = i / 5;
				int x = i % 5;

				conn[y][x] = true;

				if (src.Y == -1) src = { y,x };
			}
		}
		
		ans += is_correct(src);
	} while (next_permutation(mask, mask + SZ * SZ));

	cout << ans;
	return 0;
}