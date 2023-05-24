#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	priority_queue<pii> pq;

	while (n--) {
		int x; cin >> x;
		
		if (x == 0) {
			if (pq.empty()) cout << 0 << '\n';
			else {
				cout << ~pq.top().second << '\n';
				pq.pop();
			}
		}
		else
			pq.push({~abs(x), ~x});
	}

	return 0;
}