#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

struct Cmp {
	bool operator()(const pii& a, const pii& b) {
		if (a.second == b.second) return a.first > b.first;
		return a.second > b.second;
	}
};

bool book[1001];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int TC; cin >> TC;
	while (TC--) {
		int n, m, ans = 0;
		cin >> n >> m;

		fill_n(&book[0], 1001, false);
		priority_queue<pii, vector<pii>, Cmp> pq;

		for (int i = 0; i < m; i++) {
			int s, e; cin >> s >> e;
			pq.push({ s, e });
		}

		while (!pq.empty()) {
			pii cur = pq.top();
			pq.pop();

			for (int i = cur.first; i <= cur.second; i++) {
				if (!book[i]) {
					book[i] = true;
					ans++;
					break;
				}
			}
		}

		cout << ans << '\n';
	}

	return 0;
}