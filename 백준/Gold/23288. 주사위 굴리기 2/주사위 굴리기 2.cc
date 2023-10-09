#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

struct pos {
	int y, x, d;
};

const int dy[] = { 0,1,0,-1 };
const int dx[] = { 1,0,-1,0 };
const int btn_idx = 3;
int N, M, K, ans;

int dice[6] = { 2,1,5,6,4,3 }, board[21][21];
int dir = 0, sy = 0, sx = 0;
bool vis[21][21];

void print() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++)
			cout << board[y][x] << ' ';
		cout << '\n';
	}
}

bool oom(int y, int x) { return y < 0 || x < 0 || y >= N || x >= M; }

void update() {
	int btn = dice[btn_idx];

	if (dir == 0) {
		dice[btn_idx] = dice[5];
		dice[5] = dice[1];
		dice[1] = dice[4];
		dice[4] = btn;
	}
	else if (dir == 1) {
		dice[btn_idx] = dice[2];
		dice[2] = dice[1];
		dice[1] = dice[0];
		dice[0] = btn;
	}
	else if (dir == 2) {
		dice[btn_idx] = dice[4];
		dice[4] = dice[1];
		dice[1] = dice[5];
		dice[5] = btn;
	}
	else {
		dice[btn_idx] = dice[0];
		dice[0] = dice[1];
		dice[1] = dice[2];
		dice[2] = btn;
	}
}

int bfs(int y, int x) {
	for (int i = 0; i < N; i++)
		memset(vis[i], false, sizeof(vis[i]));

	int ret = 0;
	int target = board[y][x];
	queue<pos> q;
	q.push({ y,x,0 });
	vis[y][x] = true;

	while (!q.empty()) {
		pos cur = q.front();
		q.pop();
		ret++;

		for (int nd = 0; nd < 4; nd++) {
			int ny = cur.y + dy[nd];
			int nx = cur.x + dx[nd];

			if (!oom(ny, nx) && !vis[ny][nx] && board[ny][nx] == target) {
				q.push({ ny,nx, cur.d + 1 });
				vis[ny][nx] = true;
			}
		}
	}

	return target * ret;
}

void move() {
	// 방향 조정
	int y = sy;
	int x = sx;
	if (oom(y + dy[dir], x + dx[dir])) dir = (dir + 2) % 4;
	y += dy[dir];
	x += dx[dir];

	sy = y, sx = x;

	//주사위 움직이기
	update();

	// 점수 획득
	ans += bfs(y, x);

	// A, B를 통한 방향 결정
	int A = dice[btn_idx];
	int B = board[y][x];

	if (A > B) {
		dir++;
		if (dir > 3) dir = 0;
	}
	else if (A < B) {
		dir--;
		if (dir < 0) dir = 3;
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// freopen("input.txt", "r", stdin);

	cin >> N >> M >> K;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++)
			cin >> board[y][x];

	while (K--) move();

	cout << ans;

	return 0;
}