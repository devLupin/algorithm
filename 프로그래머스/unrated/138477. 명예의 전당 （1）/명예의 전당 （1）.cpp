#include <bits/stdc++.h>
using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> ans;
	priority_queue<int, vector<int>, greater<int>> pq;

	for(int i=0; i<score.size(); i++) {
		if(pq.size() < k) {
			pq.push(score[i]);
			ans.push_back(pq.top());
		}
		else {
			if(score[i] > pq.top()) {
				pq.pop();
				pq.push(score[i]);
				ans.push_back(pq.top());
			}
			else ans.push_back(pq.top());
		}
	}

    return ans;
}