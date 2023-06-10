#include <bits/stdc++.h>
using namespace std;

int n, k;
const int SZ = 100000;
bool visited[SZ + 1];
int parent[SZ + 1];
vector<int> path;

typedef struct {
	int x, w;
}Pos;

int bfs() {
	queue<Pos> q;
	q.push({ n, 0 });
	visited[n] = 1;

	while (!q.empty()) {
		Pos cur = q.front();
		q.pop();

		if (cur.x == k) {
			int idx = cur.x;
			while (idx != n) {
				path.push_back(idx);
				idx = parent[idx];
			}
			path.push_back(n);

			return cur.w;
		}

		int nx = cur.x + 1;
		if (nx <= SZ && !visited[nx]) {
			q.push({ nx, cur.w + 1 });
			visited[cur.x + 1] = true;
			parent[nx] = cur.x;
		}

		nx = cur.x - 1;
		if (nx >= 0 && !visited[nx]) {
			q.push({ nx, cur.w + 1 });
			visited[nx] = true;
			parent[nx] = cur.x;
		}

		nx = cur.x * 2;
		if (nx <= SZ && !visited[nx]) {
			q.push({ nx, cur.w + 1 });
			visited[nx] = true;
			parent[nx] = cur.x;
		}
	}

	return -1;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	cout << bfs() << '\n';

	for (int i = path.size() - 1; i >= 0; i--) cout << path[i] << ' ';
	return 0;
}