#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int n, k;
const int SZ = 500000;
bool visited[SZ + 1][2];


int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;

	queue<pii> q;

	q.push({ n, 0 });
	visited[n][0] = true;

	while (!q.empty()) {
		pii cur = q.front();
		q.pop();

		int now = cur.first;
		int time = cur.second;
		int pos = k + time * (time + 1) / 2;

		if (pos > SZ) {
			cout << -1;
			return 0;
		}

		if (now == pos || visited[pos][time % 2]) {
			cout << time;
			return 0;
		}

		for (int next : {now - 1, now + 1, 2 * now}) {
			if (next >= 0 && next <= 500000 && !visited[next][(time + 1) % 2])
			{
				q.push({ next,time + 1 });
				visited[next][(time + 1) % 2] = true;
			}
		}
		
	}

	return 0;
}