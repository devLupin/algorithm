#include <bits/stdc++.h>
using namespace std;

typedef struct {
	int y, x, d, k;
}Pos;

const int dy[] = { -1,1,0,0 };
const int dx[] = { 0,0,-1,1 };
const int move_ky[] = { 1,2,2,1,-1,-2,-2,-1 };
const int move_kx[] = { -2,-1,1,2,2,1,-1,-2 };

int k, w, h;
int arr[200][200];
bool visited[200][200][31];

int bfs() {
	queue<Pos> q;
	q.push({ 0,0,0 });
	visited[0][0][0] = true;

	while (!q.empty()) {
		Pos cur = q.front();
		q.pop();

		if (cur.y == h - 1 && cur.x == w - 1) return cur.d;

		if (cur.k < k) {
			for (int dir = 0; dir < 8; dir++) {
				int ny = cur.y + move_ky[dir];
				int nx = cur.x + move_kx[dir];

				if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
				if (visited[ny][nx][cur.k + 1] || arr[ny][nx] == 1) continue;

				q.push({ ny, nx, cur.d + 1, cur.k + 1 });
				visited[ny][nx][cur.k + 1] = true;
			}
		}

		for (int dir = 0; dir < 4; dir++) {
			int ny = cur.y + dy[dir];
			int nx = cur.x + dx[dir];

			if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
			if (visited[ny][nx][cur.k] || arr[ny][nx] == 1) continue;

			q.push({ ny, nx, cur.d + 1, cur.k });
			visited[ny][nx][cur.k] = true;
		}
	}

	return -1;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> k >> w >> h;
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			cin >> arr[i][j];

	cout << bfs();
	return 0;
}