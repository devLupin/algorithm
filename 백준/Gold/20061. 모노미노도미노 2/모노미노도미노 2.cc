#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
using pii = pair<int, int>;

const int dx[] = { 0, 0, 0, 1 };
const int dy[] = { 0, 0, 1, 0 };

int blue[4][6], green[6][4];
int k, t, cx, cy;
int score;

bool oom(int p) { return p < 0 || p >= 6; }

void move_blue() {
	vector<pii> pos;
	pos.push_back({ cx, 0 });
	pos.push_back({ cx + dx[t], 0 + dy[t] });

	bool flag = true;
	while (flag) {
		for (auto& nxt : pos) {
			int ny = nxt.Y + 1;
			if (ny >= 6 || blue[nxt.X][ny] != 0) {
				flag = false;
				break;
			}
		}

		if (flag) {
			pos[0].Y += 1;
			pos[1].Y += 1;
		}
	}

	for (auto& nxt : pos)
		blue[nxt.X][nxt.Y] = 1;
}

void move_green() {
	vector<pii> pos;
	pos.push_back({ 0, cy });
	pos.push_back({ 0 + dx[t], cy + dy[t] });

	bool flag = true;
	while (flag) {
		for (auto& nxt : pos) {
			int nx = nxt.X + 1;
			if (nx >= 6 || green[nx][nxt.Y] != 0) {
				flag = false;
				break;
			}
		}

		if (flag) {
			pos[0].X += 1;
			pos[1].X += 1;
		}
	}

	for (auto& nxt : pos)
		green[nxt.X][nxt.Y] = 1;
}

bool pop_blue() {
	bool ret = false;

	for (int j = 0; j < 6; j++) {
		bool flag = true;
		for (int i = 0; i < 4; i++)
			if (blue[i][j] == 0) flag = false;

		if (flag) {
			ret = true;
			for (int i = 0; i < 4; i++) blue[i][j] = -1;
			score++;
		}
	}

	return ret;
}

bool pop_green() {
	bool ret = false;

	for (int i = 0; i < 6; i++) {
		bool flag = true;
		for (int j = 0; j < 4; j++)
			if (green[i][j] == 0) flag = false;

		if (flag) {
			ret = true;
			for (int j = 0; j < 4; j++) green[i][j] = -1;
			score++;
		}
	}

	return ret;
}

void drop_blue() {
	for (int j = 5; j > 0; j--) {
		if (blue[0][j] == -1) {
			for (int i = 0; i < 4; i++) blue[i][j] = 0;

			for (int k = j - 1; k >= 0; k--)
				for (int i = 0; i < 4; i++) blue[i][k + 1] = blue[i][k];

			for (int i = 0; i < 4; i++) blue[i][0] = 0;

			j++;
		}
	}
	for (int j = 5; j >= 0; j--)
		if (blue[0][j] == -1)
			for (int i = 0; i < 4; i++) blue[i][j] = 0;
}

void drop_green()  {
	for (int i = 5; i > 0; i--) {
		if (green[i][0] == -1) {
			for (int j = 0; j < 4; j++) green[i][j] = 0;

			for (int k = i - 1; k >= 0; k--)
				for (int j = 0; j < 4; j++) green[k + 1][j] = green[k][j];

			for (int j = 0; j < 4; j++) green[0][j] = 0;

			i++;
		}
	}

	for (int i = 5; i >= 0; i--)
		if (green[i][0] == -1)
			for (int j = 0; j < 4; j++) green[i][j] = 0;
}

void drop_special_blue() {
	int cnt = 0;

	for (int j = 0; j < 2; j++) {
		bool flag = false;

		for (int i = 0; i < 4; i++) {
			if (blue[i][j] != 0) {
				flag = true;
				break;
			}
		}

		if (flag) cnt++;
	}

	for (int j = 5; j > 5 - cnt; j--)
		for (int i = 0; i < 4; i++)
			blue[i][j] = -1;
}

void drop_special_green() {
	int cnt = 0;

	for (int i = 0; i < 2; i++) {
		bool flag = false;

		for (int j = 0; j < 4; j++) {
			if (green[i][j] != 0) {
				flag = true;
				break;
			}
		}

		if (flag) cnt++;
	}

	for (int i = 5; i > 5 - cnt; i--)
		for (int j = 0; j < 4; j++)
			green[i][j] = -1;
}

int count() {
	int cnt = 0;

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 6; j++)
			cnt += blue[i][j] > 0;
	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 4; j++)
			cnt += green[i][j] > 0;

	return cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);

	cin >> k;
	while (k--) {
		cin >> t >> cx >> cy;

		move_blue();
		move_green();

		if (pop_blue()) drop_blue();
		if (pop_green()) drop_green();

		drop_special_blue();
		drop_blue();
		drop_special_green();
		drop_green();
	}

	cout << score << '\n' << count();

	return 0;
}