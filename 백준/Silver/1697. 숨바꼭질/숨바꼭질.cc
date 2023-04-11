#include <iostream>
#include <queue>
using namespace std;
using pii = pair<int, int>;

const int sz = 100001;
bool visited[sz] = { false, };

int n, k;

int solve() {
	queue<pii> q;
	q.push({ n, 0 });

	while (!q.empty()) {
		pii cur = q.front();
		q.pop();

		if (cur.first == k)
			return cur.second;

		if (cur.first > 0 && !visited[cur.first - 1]) {
			q.push({ cur.first - 1, cur.second + 1 });
			visited[cur.first - 1] = true;
		}
		if (cur.first < sz && !visited[cur.first + 1]) {
			q.push({ cur.first + 1, cur.second + 1 });
			visited[cur.first + 1] = true;
		}
		if (cur.first * 2 < sz && !visited[cur.first * 2]) {
			q.push({ cur.first * 2, cur.second + 1 });
			visited[cur.first * 2] = true;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;
	cout << solve();
}