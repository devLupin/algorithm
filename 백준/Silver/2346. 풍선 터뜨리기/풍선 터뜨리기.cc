#include <bits/stdc++.h>
using namespace std;

int B[1002], n;
deque<int> dq;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for(int i=1; i<=n; i++) {
		cin >> B[i];
		dq.push_back(i);
	}

	while(!dq.empty()) {
		int cur = dq.front();
		dq.pop_front();

		cout << cur << ' ';
		cur = B[cur];

		if(cur > 0) {
			for(int i=0 ; i<cur-1; i++) {
				dq.push_back(dq.front());
				dq.pop_front();
			}
		}
		else {
			for(int i=0; i<cur*(-1); i++) {
				dq.push_front(dq.back());
				dq.pop_back();
			}
		}
	}

	return 0;
}