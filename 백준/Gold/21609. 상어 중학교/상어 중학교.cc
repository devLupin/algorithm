#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
using pii = pair<int, int>;

const int SZ = 25;
const int BLACK = -1;
const int RAINBOW = 0;
const int EMPTY = 9;
const int MAX_M = 5;

const int dx[] = { -1,1,0,0 };
const int dy[] = { 0,0,-1,1 };

int N, M, board[SZ][SZ], ans;

bool OOM(int x, int y) { return x < 0 || y < 0 || x >= N || y >= N; }

pair<vector<pii>, int> BFS(int x, int y) {
	bool vis[SZ][SZ] = { false, };
	
	int rcnt = 0;
	vector<pii> pos;

	queue<pii> q;
	q.push({ x,y });
	vis[x][y] = true;

	while (!q.empty()) {
		pii cur = q.front();
		q.pop();

		if (board[cur.X][cur.Y] == RAINBOW) rcnt++;
		pos.push_back(cur);

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (OOM(nx, ny) || vis[nx][ny]) continue;

			if (board[x][y] == board[nx][ny] || board[nx][ny] == RAINBOW) {
				q.push({ nx, ny });
				vis[nx][ny] = true;
			}
		}
	}

	return make_pair(pos, rcnt);
}

bool compare(pair<vector<pii>, int>& a, pair<vector<pii>, int>& b) {
	if (a.first.size() != b.first.size()) 
		return a.first.size() > b.first.size();

	if (a.second != b.second) return a.second > b.second;

	pii apos, bpos;
	for(auto nxt : a.first)
		if (board[nxt.X][nxt.Y] != RAINBOW) {
			apos = nxt;
			break;
		}
	for (auto nxt : b.first)
		if (board[nxt.X][nxt.Y] != RAINBOW) {
			bpos = nxt;
			break;
		}

	if (apos.X != bpos.X) return apos.X > bpos.X;
	return apos.Y > bpos.Y;
}

vector<pii> Find() {
	vector<pair<vector<pii>, int>> v;
	bool visited[SZ][SZ] = { false, };

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j] && board[i][j] > 0 && board[i][j] <= MAX_M) {
				auto res = BFS(i, j);
				v.push_back(res);

				sort(res.first.begin(), res.first.end());

				for (auto nxt : res.first)
					if (board[nxt.X][nxt.Y] != RAINBOW)
						visited[nxt.X][nxt.Y] = true;
			}
		}
	}
	sort(v.begin(), v.end(), compare);
	if (v.empty() || v[0].first.size() < 2) return {};

	int point = v[0].first.size();
	ans += point * point;

	return v[0].first;
}

void RMBlock(vector<pii> pos) {
	for (auto& nxt : pos)
		board[nxt.X][nxt.Y] = EMPTY;
}

void Gravity() {
	for (int i = N - 2; i >= 0; i--) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == BLACK || board[i][j] == EMPTY) continue;

			auto [x, y] = make_pair(i + 1, j);
			while (!OOM(x, y) && board[x][y] == EMPTY) x++;

			swap(board[i][j], board[x - 1][y]);
		}
	}
}

void Rotate() {
	int next_board[SZ][SZ] = { 0, };

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			next_board[i][j] = board[j][N - i - 1];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			board[i][j] = next_board[i][j];
}


void Print() {
	cout << "\n\n";

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == BLACK) cout << 'B' << ' ';
			else if (board[i][j] == EMPTY) cout << 'E' << ' ';
			else cout << board[i][j] << ' ';
		}
		cout << '\n';
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	//freopen("input.txt", "r", stdin);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];

	while (true) {
		auto pos = Find();
		if (pos.empty()) break;

		RMBlock(pos);
		Gravity();
		Rotate();
		Gravity();
	}

	cout << ans;
	return 0;
}