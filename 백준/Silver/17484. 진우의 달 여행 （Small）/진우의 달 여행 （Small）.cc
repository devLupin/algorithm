#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f;
int N, M, ans=INF;
int D[8][8][4];
int A[8][8];

int DP(int y, int x, int dir) {
	if (y >= N && (0 <= x && x < M)) return 0;
	if (y < 0 || x < 0 || y >= N || x >= M) return INF;
	int &ret = D[y][x][dir];
	if (ret != -1) return ret;

	ret = 0;
	if (dir == 1) ret = min(DP(y + 1, x, 2), DP(y + 1, x + 1, 3)) + A[y][x];
	else if (dir == 2) ret = min(DP(y + 1, x - 1, 1), DP(y + 1, x + 1, 3)) + A[y][x];
	else if (dir == 3) ret = min(DP(y + 1, x - 1, 1), DP(y + 1, x, 2)) + A[y][x];
	else ret = min({ DP(y + 1, x - 1, 1), DP(y + 1, x, 2), DP(y + 1, x + 1, 3) }) + A[y][x];
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> A[i][j];
		}
	}
	memset(D, -1, sizeof(D));

	for (int i = 0; i < M; i++)
        ans = min(ans, DP(0, i, 0));

    cout << ans;

	return 0;
}