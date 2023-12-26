#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
using pii = pair<int, int>;

vector<string> mapp;
int N, M;

vector<pii> search() {
	vector<pii> ret;

	for (int i = 0; i < N - 1; i++)
		for (int j = 0; j < M - 1; j++)
			if (mapp[i][j] != '0' && mapp[i][j] == mapp[i][j + 1] && mapp[i + 1][j] == mapp[i + 1][j + 1] && mapp[i][j] == mapp[i + 1][j]) {
				ret.push_back({ i, j });
				ret.push_back({ i + 1, j });
				ret.push_back({ i, j + 1 });
				ret.push_back({ i + 1, j + 1 });
			}

	return ret;
}

bool oom(int x, int y) { return x < 0 || y < 0 || x >= N || y >= M; }

void rm(vector<pii> pos) {
	for (pii nxt : pos) mapp[nxt.X][nxt.Y] = '0';

	for (int i = N - 2; i >= 0; i--) {
		for (int j = 0; j < M; j++) {
			char v = mapp[i][j];
			int x = i + 1;

			while (!oom(x, j) && mapp[x][j] == '0') x++;
			swap(mapp[i][j], mapp[x - 1][j]);
		}
	}
}

int solution(int m, int n, vector<string> board) {
	mapp.assign(board.begin(), board.end());
	tie(N, M) = { m, n };

	while (true) {
		vector<pii> pos = search();
		if (pos.size() < 1) break;
		rm(pos);
	}

	int ans = 0;
	for (string nxt : mapp)
		for (char c : nxt)
			if (c == '0') ans++;

	return ans;
}