#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
using pii = pair<int, int>;

enum { WHITE, RED, BLUE };

const int SZ = 15;

// →, ←, ↑, ↓
const int dx[] = { 0, 0, -1,1 };
const int dy[] = { 1,-1,0,0 };

int N, K;
int board[SZ][SZ];
vector<int> chess[SZ][SZ];
pii pos[SZ];
int cdir[SZ];

bool OOM(int x, int y) { return x < 0 || y < 0 || x >= N || y >= N; }

bool Move() {
	for (int i = 1; i <= K; i++) {
		pii& cur_pos = pos[i];
		int& cur_d = cdir[i];
		auto& cur_chess = chess[cur_pos.X][cur_pos.Y];

		// 위에 쌓이면 push_back();
		int c_idx = find(cur_chess.begin(), cur_chess.end(), i) - cur_chess.begin();
		int cnt = cur_chess.size() - c_idx;
		vector<int> v;

		int nx = cur_pos.X + dx[cur_d];
		int ny = cur_pos.Y + dy[cur_d];

		if (OOM(nx, ny) || board[nx][ny] == BLUE) {
			if (cur_d == 0) cur_d = 1;
			else if (cur_d == 1) cur_d = 0;
			else if (cur_d == 2) cur_d = 3;
			else if (cur_d == 3) cur_d = 2;

			nx = cur_pos.X + dx[cur_d];
			ny = cur_pos.Y + dy[cur_d];

			if (OOM(nx, ny) || board[nx][ny] == BLUE) continue;
		}

		if (board[nx][ny] == RED)
			reverse(cur_chess.begin() + c_idx, cur_chess.end());

		while (cnt--) {
			v.push_back(cur_chess.back());
			cur_chess.pop_back();
		}

		reverse(v.begin(), v.end());

		for (auto nxt : v) {
			chess[nx][ny].push_back(nxt);
			pos[nxt] = { nx, ny };
		}

		if (chess[nx][ny].size() >= 4) return false;
	}

	return true;
}

void Print() {
	cout << "\n\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (chess[i][j].size() > 0) {
				cout << i << ' ' << j << '\n';
				for (int nxt : chess[i][j])
					cout << nxt << ' ';
				cout << "\n\n";
			}
		}
	}
	for (int i = 1; i <= K; i++)
		cout << cdir[i] << ' ';
	cout << '\n';
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	//freopen("input.txt", "r", stdin);

	cin >> N >> K;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];

	for (int x, y, d, i = 1; i <= K; i++) {
		cin >> x >> y >> d;
		x--, y--, d--;

		chess[x][y].push_back(i);
		pos[i] = { x, y };
		cdir[i] = d;
	}

	int t = 1;

	while (Move() && t <= 1000)
		t++;

	if (t > 1000) cout << -1;
	else cout << t;

	return 0;
}