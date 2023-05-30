#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
typedef struct { int y, x; } pos;

const int dy[] = { -1,1,0,0 };
const int dx[] = { 0,0,-1,1 };
const int SZ = 50, INF = 0x3f3f3f;
int n, m, ans, c[SZ][SZ];
bool selected[SZ];
vector<pos> house, chicken, pick;

int distance(pos a, pos b) { return abs(a.x - b.x) + abs(a.y - b.y); }

int find_min_distance() {
	int ret = 0;
	for (pos h : house) {
		int tmp = INF;
		for (pos chic : pick)
			tmp = min(tmp, distance(h, chic));
		ret += tmp;
	}
	return ret;
}

void dfs(int x, int cnt) {
	if (m == cnt) {
		int cmp = find_min_distance();
		ans = min(cmp, ans);
	}

	for (int i = x; i < chicken.size(); i++) {
		if (selected[i]) continue;

		selected[i] = true;
		pick.push_back(chicken[i]);
		dfs(i, cnt + 1);
		selected[i] = false;
		pick.pop_back();
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> c[i][j];
			if (c[i][j] == 1) house.push_back({ i,j });
			if (c[i][j] == 2) chicken.push_back({ i,j });
		}
	}

	ans = INF;
	dfs(0, 0);
	cout << ans;
	return 0;
}