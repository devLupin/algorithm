#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> MAP;
vector<int> ans(2, 0);

void dfs(int x, int y, int sz) {
	bool chk0, chk1;
	chk0 = chk1 = true;

	for (int i = x; i < x + sz; i++) {
		for (int j = y; j < y + sz; j++) {
			if (MAP[i][j] == 0) chk1 = false;
			if (MAP[i][j] == 1) chk0 = false;
		}
	}

	if (chk0) {
		ans[0]++;
		return;
	}
	if (chk1) {
		ans[1]++;
		return;
	}

	sz /= 2;
	dfs(x, y, sz);
	dfs(x, y + sz, sz);
	dfs(x + sz, y, sz);
	dfs(x + sz, y + sz, sz);
}

vector<int> solution(vector<vector<int>> arr) {
	MAP = arr;
	dfs(0, 0, arr.size());
	return ans;
}