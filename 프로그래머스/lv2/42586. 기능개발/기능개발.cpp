#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> ret;
	queue<int> q;

	const int SZ = speeds.size();
	for(int i=0; i<SZ; i++) {
		int remain = 100 - progresses[i];
		int tmp = (remain % speeds[i] == 0) ? remain/speeds[i] : remain/speeds[i] + 1;
		q.push(tmp);
	}

	int cnt = 1;
	int cmp = q.front();
	q.pop();

	while(!q.empty()) {
		if(q.front() <= cmp) cnt++;
		else {
			ret.push_back(cnt);
			cmp = q.front();
			cnt = 0;
			continue;
		}
		q.pop();
	}

	if(cnt != 0) ret.push_back(cnt);

	return ret;
}