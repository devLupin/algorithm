#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int solution(vector<int> priorities, int location) {

	queue<pii> q;
	for(int i=0; i<priorities.size(); i++)
		q.push({priorities[i], i});

	sort(priorities.begin(), priorities.end(), greater<>());

	int ret = 1;
	int mx = 0;
	while(!q.empty()) {
		pii cur = q.front();
		q.pop();

		if(cur.first == priorities[mx]) {
			if(cur.second == location) 
				break;
			mx++;
			ret++;
		}

		else q.push(cur);
	}
	return ret;
}