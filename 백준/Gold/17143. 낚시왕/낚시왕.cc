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

const int SZ = 105;
const int MAX_S = SZ * SZ;
const int dx[] = { -1,1,0,0 };
const int dy[] = { 0,0,1,-1 };

int R, C, M, ans;
int board[SZ][SZ], tmp[SZ][SZ];
tiii info[MAX_S];

void Catch(int y) {
	for (int x = 1; x <= R; x++) {
		int num = board[x][y];

		if (num) {
			ans += get<2>(info[num]);
			board[x][y] = 0;
			break;
		}
	}
}

bool oom(int x, int y) { return x < 1 || y < 1 || x > R || y > C; }

int Change(int d) {
	int dir;
	if (d == 0) dir = 1;
	else if (d == 1) dir = 0;
	else if (d == 2) dir = 3;
	else dir = 2;

	return dir;
}

void Move() {
	fill(&tmp[1][1], &tmp[R + 1][C + 1], 0);

	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++) {
			int num = board[i][j];

			if (num > 0) {
				auto& [s, d, z] = info[num];
				int x = i, y = j;

				for (int k = 0; k < s; k++) {
					int nx = x + dx[d];
					int ny = y + dy[d];

					if (oom(nx, ny)) d = Change(d);

					x += dx[d];
					y += dy[d];
				}

				if (tmp[x][y] > 0) {
					int c1 = get<2>(info[tmp[x][y]]);
					int c2 = get<2>(info[num]);

					tmp[x][y] = (c1 < c2) ? num : tmp[x][y];
				}
				else
					tmp[x][y] = num;
			}
		}

	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++)
			board[i][j] = tmp[i][j];
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	//freopen("input.txt", "r", stdin);

	cin >> R >> C >> M;
	for (int i = 1; i <= M; i++) {
		int x, y, s, d, z;
		cin >> x >> y >> s >> d >> z;
		d--;

		if (d == 0 || d == 1) s %= (2 * (R - 1));
		else s %= (2 * (C - 1));

		board[x][y] = i;
		info[i] = { s,d,z };
	}

	for (int i = 1; i <= C; i++) {
		Catch(i);
		Move();
	}

	cout << ans;
	return 0;
}