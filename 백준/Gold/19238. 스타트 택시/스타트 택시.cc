#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

struct pos {
	int y, x, fuel;
};

const int dy[] = { -1,1,0,0 };
const int dx[] = { 0,0,-1,1 };

const int SZ = 20;
int N, M, board[SZ][SZ];
pos start;
vector<pii> src, dest;

bool oom(int y, int x) { return y < 0 || x < 0 || y >= N || x >= N; }

bool compare(pair<pos, int>& a, pair<pos, int>& b) {
	if (a.first.fuel == b.first.fuel) {
		if (a.first.y == b.first.y) return a.first.x < b.first.x;
		return a.first.y < b.first.y;
	}
	return a.first.fuel > b.first.fuel;
}

pair<pos,int> find_min_src() {
	vector<pair<pos,int>> res;

	for(int i=0; i<src.size(); i++) {
		bool vis[SZ][SZ] = { false, };
		queue<pos> q;
		pii target = src[i];

		q.push(start);
		vis[start.y][start.x] = true;

		while (!q.empty()) {
			pos cur = q.front();
			q.pop();

			if (cur.y == target.first && cur.x == target.second) {
				res.push_back({ { cur.y,cur.x,cur.fuel }, i });
			}

			if (cur.fuel < 0) break;

			for (int dir = 0; dir < 4; dir++) {
				int ny = cur.y + dy[dir];
				int nx = cur.x + dx[dir];

				if (oom(ny, nx) || vis[ny][nx] || board[ny][nx] == 1) continue;

				q.push({ ny,nx,cur.fuel - 1 });
				vis[ny][nx] = true;
			}
		}
	}
	
	if (res.size() != src.size()) return { { 0,0,0 },-1 };

	sort(res.begin(), res.end(), compare);
	return res[0];
}

pos find_dest(pii target) {
	bool vis[SZ][SZ] = { false, };
	queue<pos> q;

	q.push(start);
	vis[start.y][start.x] = true;

	while (!q.empty()) {
		pos cur = q.front();
		q.pop();

		if (cur.y == target.first && cur.x == target.second) return cur;
		if (cur.fuel < 0) return { -1,-1,-1 };

		for (int dir = 0; dir < 4; dir++) {
			int ny = cur.y + dy[dir];
			int nx = cur.x + dx[dir];

			if (oom(ny, nx) || vis[ny][nx] || board[ny][nx] == 1) continue;

			q.push({ ny,nx,cur.fuel - 1 });
			vis[ny][nx] = true;
		}
	}

	return { -1,-1,-1 };
}

int solve() {
	int fuel = start.fuel;

	while (!src.empty() && fuel > 0) {
		auto nxt = find_min_src();
		if (nxt.second == -1) return -1;

		start = nxt.first;
		pii target = dest[nxt.second];
		fuel -= (fuel - start.fuel);

		pos next = find_dest(target);
		if (next.fuel == -1) return -1;

		start = next;
		int tmp = fuel - start.fuel;
		fuel -= tmp;
		fuel += tmp * 2;
		start.fuel = fuel;

		src.erase(src.begin() + nxt.second);
		dest.erase(dest.begin() + nxt.second);
	}

	if (!src.empty()) return -1;
	return start.fuel;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	//freopen("input.txt", "r", stdin);

	cin >> N >> M >> start.fuel;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];

	cin >> start.y >> start.x;
	start.y--, start.x--;

	for (int a, b; M--;) {
		cin >> a >> b;
		a--, b--;
		src.push_back({ a,b });
		cin >> a >> b;
		a--, b--;
		dest.push_back({ a,b });
	}

	cout << solve();
}