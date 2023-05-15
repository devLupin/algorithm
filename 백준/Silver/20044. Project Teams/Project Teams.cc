#include <bits/stdc++.h>
using namespace std;


int main(void) 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n; cin >> n;
	deque<int> dq;
	for (int tmp, i = 0; i < n*2; i++) {
		cin >> tmp;
		dq.push_back(tmp);
	}

	sort(dq.begin(), dq.end());
	
	vector<int> v;
	while (!dq.empty()) {
		v.push_back(dq.front() + dq.back());
		dq.pop_front(); dq.pop_back();
	}

	sort(v.begin(), v.end());
	cout << v[0];
	return 0;
}