#include <bits/stdc++.h>
using namespace std;

const int SIZE = 52;
int n, m, start_i, start_j, end_i, end_j;
char a[SIZE][SIZE];
int water_day[SIZE][SIZE];
int check[SIZE][SIZE];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { -1, 1, 0, 0 };

queue<pair<int, int>> water;

void water_bfs() {
	while (!water.empty()) {
		int x = water.front().first;
		int y = water.front().second;
		water.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (water_day[nx][ny] == 0 && a[nx][ny] == '.') {
					water_day[nx][ny] = water_day[x][y] + 1;
					water.push(make_pair(nx, ny));
				}
			}
		}
	}
}

void bfs() {
	queue<pair<int, int>> q;
	q.push(make_pair(start_i, start_j));
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (check[nx][ny] == 0 && (a[nx][ny] == '.' || a[nx][ny] == 'D')) {
					if (water_day[nx][ny] == 0) {
						check[nx][ny] = check[x][y] + 1;
						q.push(make_pair(nx, ny));
					}
					else {
						if (water_day[nx][ny] > check[x][y] + 1) {
							check[nx][ny] = check[x][y] + 1;
							q.push(make_pair(nx, ny));
						}
					}
				}
			}
		}
	}
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

	for (int i = 0; i < n; i++) {
        cin >> a[i];
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 'S') {
				start_i = i;
				start_j = j;
			}
			else if (a[i][j] == 'D') {
				end_i = i;
				end_j = j;
			}
			else if (a[i][j] == '*') {
				water.push(make_pair(i, j));
			}
		}
	}

	water_bfs();
	bfs();

	if (check[end_i][end_j] != 0)
		cout << check[end_i][end_j];
	else 
		printf("KAKTUS\n");
}