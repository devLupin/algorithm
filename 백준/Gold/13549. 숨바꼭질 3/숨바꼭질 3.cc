#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

int n, k;
const int SZ = 100000+1;
bool vis[SZ];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;

	deque<pii> dq;
	dq.push_back({n, 0});
	vis[n] = true;

	while(!dq.empty()) {
		int x = dq.front().first;
		int w = dq.front().second;
		dq.pop_front();

		if(x == k) {
			cout << w;
			return 0;
		}

		int nx = x * 2;
		if(nx < SZ && !vis[nx]) {
			dq.push_front({nx, w});
			vis[nx] = true;
		}

		nx = x - 1;
		if(nx >= 0 && !vis[nx]) {
			dq.push_back({nx, w+1});
			vis[nx] = true;
		}

		nx = x + 1;
		if(nx < SZ && !vis[nx]) {
			dq.push_back({nx, w+1});
			vis[nx] = true;
		}
	}
}