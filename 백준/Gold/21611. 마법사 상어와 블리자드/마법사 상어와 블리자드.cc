#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
using pii = pair<int, int>;

const int MAX_N = 50;

// ←, ↓, →, ↑
const int dx[] = { 0,1,0,-1 };
const int dy[] = { -1,0,1,0 };
// ↑, ↓, ←, →
const int ddx[] = { -1,1,0,0 };
const int ddy[] = { 0,0,-1,1 };

int N, M, board[MAX_N][MAX_N];
int sx, sy;
int ans;

void Attack(int d, int s) {
	auto [x, y] = make_pair(sx, sy);

	while (s--) {
		x += ddx[d];
		y += ddy[d];
		board[x][y] = 0;
	}
}

vector<int> Pull() {
	vector<int> v;
	auto [x, y] = make_pair(sx, sy);
	auto [cnt, n_cnt, dir_cnt, dir] = make_tuple(0, 1, 0, 0);

	while (true) {
		x += dx[dir];
		y += dy[dir];
		if (x < 0 || y < 0) break;

		if(board[x][y] > 0)
			v.push_back(board[x][y]);

		cnt++;
		if (cnt == n_cnt) {
			cnt = 0;
			dir = (dir + 1) % 4;

			dir_cnt++;
			if (dir_cnt == 2) {
				dir_cnt = 0;
				n_cnt++;
			}
		}
	}

	return v;
}

vector<int> RemoveDup(vector<int> v) {
	if (v.empty()) return {};

	while (true) {
		vector<int> nxt_v;
		int cmp = v[0];
		int cnt = 0;

		for (auto nxt : v) {
			if (cmp == nxt) {
				nxt_v.push_back(nxt);
				cnt++;
			}
			else {
				if (cnt >= 4) {
					ans += cmp * cnt;
					while (cnt--) nxt_v.pop_back();
				}
				nxt_v.push_back(nxt);
				cmp = nxt;
				cnt = 1;
			}
		}
		if (cnt >= 4) {
			ans += cmp * cnt;
			while (cnt--) nxt_v.pop_back();
		}

		if (v.size() == nxt_v.size() || nxt_v.empty()) break;
		v = nxt_v;
	}

	return v;
}

vector<int> Grouping(vector<int> v) {
	if (v.empty()) return {};

	int cnt = 0;
	int cmp = v[0];
	vector<int> nxt_v;

	for (int nxt : v) {
		if (cmp == nxt) cnt++;
		else {
			nxt_v.push_back(cnt);
			nxt_v.push_back(cmp);
			cmp = nxt;
			cnt = 1;
		}
	}
	nxt_v.push_back(cnt);
	nxt_v.push_back(cmp);

	return nxt_v;
}

void Fill(vector<int> v) {
	auto [x, y] = make_pair(sx, sy);
	auto [cnt, n_cnt, dir_cnt, dir] = make_tuple(0, 1, 0, 0);

	int len = min((int)v.size(), N * N);

	for(int i=0; i<len; i++) {
		x += dx[dir];
		y += dy[dir];

		if (x < 0 || y < 0) break;

		board[x][y] = v[i];

		cnt++;
		if (cnt == n_cnt) {
			cnt = 0;
			dir = (dir + 1) % 4;

			dir_cnt++;
			if (dir_cnt == 2) {
				dir_cnt = 0;
				n_cnt++;
			}
		}
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

	tie(sx, sy) = make_pair(N / 2, N / 2);

	for (int d, s; M--;) {
		cin >> d >> s;
		Attack(d - 1, s);
		auto cur = Pull();
		cur = RemoveDup(cur);
		cur = Grouping(cur);
		fill(&board[0][0], &board[N][N], 0);
		Fill(cur);
	}

	cout << ans;
	return 0;
}