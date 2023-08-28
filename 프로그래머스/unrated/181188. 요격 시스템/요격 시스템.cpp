#include <bits/stdc++.h>
using namespace std;

bool compare(vector<int> &a, vector<int> &b) {
	return a[1] < b[1];
}

int solution(vector<vector<int>> targets) {
    int ans = 0;

	sort(targets.begin(), targets.end(), compare);
	int tmp = -1;
	for(auto cur : targets) {
		if(cur[0] >= tmp) {
			ans++;
			tmp = cur[1];
		}
	}

	return ans;
}