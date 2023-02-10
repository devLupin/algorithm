#include <iostream>
#include <queue>
#include <cstring>
using namespace std;


int n, m, v;
bool adj_mat[1001][1001] = { false, };
bool visited[1001] = { false };

void dfs(int start) {
	cout << start << ' ';
	visited[start] = true;

	for (int i = 1; i <= n; i++)
		if (!visited[i] && adj_mat[start][i]) 
			dfs(i);

	return;
}

void bfs(int start) {
	memset(visited, false, sizeof(visited));

	queue<int> q;
	q.push(start);
	visited[start] = true;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		cout << cur << ' ';

		for (int i = 1; i <= n; i++) 
			if (!visited[i] && adj_mat[cur][i]) {
				q.push(i);
				visited[i] = true;
			}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> v;
	for (int i = 0; i < m; i++) {
		int src, dest;
		cin >> src >> dest;
		adj_mat[src][dest] = adj_mat[dest][src] = true;
	}

	dfs(v);
	cout << '\n';
	bfs(v);

	return 0;
}