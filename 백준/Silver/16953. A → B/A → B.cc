#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

ll a, b;

int bfs() {
	queue<pii> q;
	q.push({a, 0});

	while(!q.empty()) {
		auto cur = q.front();
		ll x = cur.first;
		ll cnt = cur.second;
		q.pop();

		if(x == b) return cnt+1;

		if(x*2 <= b) q.push({x*2, cnt + 1});

		x = stoll(to_string(x)+"1");
		if(x <= b) q.push({x, cnt + 1});
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> a >> b;

	cout << bfs();
	return 0;
}