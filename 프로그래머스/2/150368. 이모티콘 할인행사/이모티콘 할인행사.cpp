#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int dc[] = { 10, 20, 30, 40 };
vector<int> EMOTICONS;
vector<vector<int>> USERS;
int subscribe, sales;

pii calc(int idx, vector<int> discnt) {
	pii ret;

	int lim_dc = USERS[idx][0];
	int lim_cost = USERS[idx][1];
	int sum_cost = 0;

	for (int i = 0; i < EMOTICONS.size(); i++) {
		int cost = EMOTICONS[i];
		int dis = discnt[i];
		if (dis < lim_dc) continue;

		sum_cost += cost * (100 - dis) / 100;

		if (sum_cost >= lim_cost) {
			ret.first = 1;
			ret.second = 0;
			return ret;
		}
	}

	ret.second = sum_cost;
	return ret;
}

void dfs(vector<int> discnt) {
	if (discnt.size() == EMOTICONS.size()) {
		pii cmp = { 0,0 };

		for (int i = 0; i < USERS.size(); i++) {
			auto res = calc(i, discnt);
			cmp.first += res.first;
			cmp.second += res.second;
		}

		if (cmp.first > subscribe) {
			subscribe = cmp.first;
			sales = cmp.second;
		}
		else if (cmp.first == subscribe && cmp.second > sales)
			sales = cmp.second;

		return;
	}

	for (int i = 0; i < 4; i++) {
		discnt.push_back(dc[i]);
		dfs(discnt);
		discnt.pop_back();
	}
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
	USERS.assign(users.begin(), users.end());
	EMOTICONS.assign(emoticons.begin(), emoticons.end());

	dfs({});

	return {subscribe, sales};
}