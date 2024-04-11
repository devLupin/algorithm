#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
using pii = pair<int, int>;

const int DIR_NUM = 8;
const int MAX_N = 4;
const int MAX_S = 105;
const int DECAY = 2;

// ←, ↖, ↑, ↗, →, ↘, ↓, ↙
const int dx[DIR_NUM] = { 0,-1,-1,-1,0,1,1,1 };
const int dy[DIR_NUM] = { -1,-1,0,1,1,1,0,-1 };
const int ddx[] = { -1,0,1,0 };
const int ddy[] = { 0,-1,0,1 };

int M, S, T;
int fish[MAX_S + 1][MAX_N + 1][MAX_N + 1][DIR_NUM];
int sx, sy;
int dead[MAX_N + 1][MAX_N + 1][DECAY + 1];

bool OOM(int x, int y) { return x < 0 || y < 0 || x >= MAX_N || y >= MAX_N; }

bool CanGo(int x, int y) {
	if (OOM(x, y)) return false;
	if (x == sx && y == sy) return false;
	if (dead[x][y][0] || dead[x][y][1]) return false;
	return true;
}

void MoveF() {
	for (int x = 0; x < MAX_N; x++)
		for (int y = 0; y < MAX_N; y++)
			for (int k = 0; k < DIR_NUM; k++)
				if (fish[T - 1][x][y][k] > 0) {
					int nd = k;
					int nx = x + dx[nd];
					int ny = y + dy[nd];
					bool flag = false;

					if (CanGo(nx, ny))
						flag = true;
					else {
						int cnt = 7;
						while (cnt--) {
							nd--;
							if (nd < 0) nd = 7;

							nx = x + dx[nd];
							ny = y + dy[nd];

							if (CanGo(nx, ny)) {
								flag = true;
								break;
							}
						}
					}

					if (flag) fish[T][nx][ny][nd] += fish[T - 1][x][y][k];
					else fish[T][x][y][k] += fish[T - 1][x][y][k];
				}
}

int Routes(int d1, int d2, int d3) {
	bool vis[MAX_N][MAX_N] = { false, };
	int ret = 0;
	auto [x, y] = make_pair(sx, sy);

	for (int dir : {d1, d2, d3}) {
		x += ddx[dir];
		y += ddy[dir];

		if (OOM(x, y)) return -1;
		if (vis[x][y])continue;

		for (int k = 0; k < DIR_NUM; k++)
			ret += fish[T][x][y][k];
		vis[x][y] = true;
	}

	return ret;
}

void MoveS() {
	int count = -1;
	tuple<int, int, int> best;

	for (int i = 0; i < MAX_N; i++)
		for (int j = 0; j < MAX_N; j++)
			for (int k = 0; k < 4; k++) {
				int cmp = Routes(i, j, k);
				
				if (count < cmp) {
					count = cmp;
					best = make_tuple(i, j, k);
				}
			}
	
	auto [d1, d2, d3] = best;
	for (int dir : {d1, d2, d3}) {
		sx += ddx[dir];
		sy += ddy[dir];

		for (int k = 0; k < DIR_NUM; k++) {
			dead[sx][sy][DECAY] += fish[T][sx][sy][k];
			fish[T][sx][sy][k] = 0;
		}
	}
}

void Update() {
	for (int i = 0; i < MAX_N; i++)
		for (int j = 0; j < MAX_N; j++) {
			for (int k = 0; k < DECAY; k++)
				dead[i][j][k] = dead[i][j][k + 1];
			dead[i][j][DECAY] = 0;
		}
}

void Copy() {
	for (int x = 0; x < MAX_N; x++)
		for (int y = 0; y < MAX_N; y++)
			for (int k = 0; k < DIR_NUM; k++)
				if (fish[T - 1][x][y][k] > 0) {
					fish[T][x][y][k] += fish[T - 1][x][y][k];
				}
}

int Answer() {
	int ret = 0;
	for (int x = 0; x < MAX_N; x++)
		for (int y = 0; y < MAX_N; y++)
			for (int k = 0; k < DIR_NUM; k++)
				ret += fish[T][x][y][k];
	return ret;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	//freopen("input.txt", "r", stdin);

	cin >> M >> S;
	for (int x, y, d, i = 1; i <= M; i++) {
		cin >> x >> y >> d;
		x--, y--, d--;

		fish[T][x][y][d]++;
	}
	cin >> sx >> sy;
	sx--, sy--;

	while (S--) {
		T++;
		MoveF();
		MoveS();
		Update();
		Copy();
	}

	cout << Answer();
	return 0;
}