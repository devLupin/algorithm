#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
using pii = pair<int, int>;

int N, M, T, mul, d, k, num;
deque<int> board[55];
const int dx[] = { -1,1,0,0 };
const int dy[] = { 0,0,-1,1 };

void print() {
	for (int i = 1; i <= N; i++) {
		for(int nxt : board[i])
			cout << nxt << ' ';
		cout << '\n';
	}
	cout << '\n';
}

void rotate() {
	for (int i = mul; i <= N; i += mul) {
		for (int j = 0; j < k; j++) {
			if (d == 0) {
				board[i].push_front(board[i].back());
				board[i].pop_back();
			}
			else {
				board[i].push_back(board[i].front());
				board[i].pop_front();
			}
		}
	}
}

bool remove_adj() {
	bool flag = false;

	vector<pii> v;

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] == 0) continue;

			bool chk = false;

			for (int dir = 0; dir < 4; dir++) {
				int x = i + dx[dir];
				int y = j + dy[dir];

				if (x < 1 || x > N) continue;

				if (y < 0) y = M - 1;
				else if (y >= M) y = 0;

				if (board[i][j] == board[x][y]) {
					chk = true;
					v.push_back({ x, y });
				}
			}

			if (chk)
				v.push_back({ i, j });
		}
	}

	for (pii nxt : v) board[nxt.X][nxt.Y] = 0;

	return (int)v.size() > 0;
}

void add() {
	int sum = 0;
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] == 0) continue;
			sum += board[i][j];
			cnt++;
		}
	}

	double cmp = (double)sum / cnt;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] == 0) continue;
			if ((double)board[i][j] > cmp) board[i][j]--;
			else if ((double)board[i][j] < cmp) board[i][j]++;
		}
	}
}

int main() {
	ios::sync_with_stdio(0); 
	cin.tie(0);

	//freopen("input.txt", "r", stdin);

	cin >> N >> M >> T;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> num;
			board[i].push_back(num);
		}
	}

	while (T--) {
		cin >> mul >> d >> k;
		rotate();
		if (!remove_adj()) add();
	}

	int sum = 0;
	for (int i = 1; i <= N; i++)
		for (int nxt : board[i])
			sum += nxt;

	cout << sum;

	return 0;
}