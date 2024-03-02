#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int K;

bool check(int mid) {
	int cnt = 0;

	for (auto& nxt : v) {
		if (nxt < mid) cnt++;
		else cnt = 0;

		if (cnt >= K) return false;
	}

	return true;
}

int solution(vector<int> stones, int k) {
	int ans, left, right, mid;

	tie(ans, left, right, K) = 
		make_tuple(0, *min_element(stones.begin(), stones.end()), *max_element(stones.begin(), stones.end()), k);
	v.assign(stones.begin(), stones.end());

	while (left <= right) {
		mid = (left + right) / 2;

		if (check(mid)) {
			left = mid + 1;
			ans = max(ans, mid);
		}
		else right = mid - 1;
	}

	return ans;
}