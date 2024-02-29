#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> v;
unordered_map<string, int> MAP;
int SZ, ans;
bool vis1[8], vis2[8];

void dfs(int cnt, int s, string tmp) {
	if (cnt == SZ) {
		if (MAP[tmp] == 0) {
			ans++;
			MAP[tmp]++;
		}

		return;
	}

	for (int i = s; i < v.size(); i++) {
		auto cur = v[i];

		if (vis1[cur.first] || vis2[cur.second]) continue;

		vis1[cur.first] = true;
		vis2[cur.second] = true;
		dfs(cnt + 1, i + 1, tmp + to_string(cur.first));
		vis1[cur.first] = false;
		vis2[cur.second] = false;
	}
}

int solution(vector<string> user_id, vector<string> banned_id) {
	int answer = 0;
	SZ = banned_id.size();

	for (int u = 0; u < user_id.size(); u++) {
		for (int b = 0; b < banned_id.size(); b++) {
			string user = user_id[u];
			string ban = banned_id[b];

			if (user.size() != ban.size()) continue;

			bool flag = false;
			int i = 0, j = 0;
			while (i == j && i < user.size()) {
				if (user[i] == ban[j] || ban[i] == '*') {
					flag = true;
					i++, j++;
				}
				else {
					flag = false;
					break;
				}
			}

			if (flag)
				v.push_back({ u, b });
		}
	}

	dfs(0, 0, "");
	return ans;
}