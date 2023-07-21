#include <bits/stdc++.h>
using namespace std;

int n, k, ans;
deque<int> dq;
deque<bool> chk;

int count() {
	int ret = 0;
	for(int i=0; i<dq.size(); i++)
		ret += (dq[i] == 0);
	return ret;
}

void rotate() {
	dq.push_front(dq.back());
	dq.pop_back();
	chk.push_front(chk.back());
	chk.pop_back();
}

void solve() {
	while(count() < k) {
		ans++;

		rotate();

		if(chk[n-1]) chk[n-1] = false;
		
		for(int i=n-2; i>=0; i--) {
			if(dq[i+1] > 0 && !chk[i+1] && chk[i]) {
				dq[i+1]--;
				chk[i] = false;

				if(i == n-2) continue;
				chk[i+1] = true;
			}
		}

		if(dq[0] > 0 && !chk[0]) {
			dq[0]--;
			chk[0] = true;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	for(int x, i=0; i<n*2; i++) {
		cin >> x;
		dq.push_back(x);
		chk.push_back(false);
	}

	solve();
	cout << ans;

	return 0;
}