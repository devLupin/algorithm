#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

bool visited[101] = { false };
bool adj_mat[101][101] = { false };
int n, e;
int answer = -1;

void dfs(int start) {
	if (visited[start])
		return;

	visited[start] = true;
	answer++;

	for (int i = 1; i <= n; i++)
		if (!visited[i] && adj_mat[start][i])
			dfs(i);
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	cin >> e;
	for (int i = 0; i < e; i++) {
		int src, dest;
		cin >> src >> dest;

		adj_mat[src][dest] = adj_mat[dest][src] = true;
	}

	dfs(1);
	cout << answer;

	return 0;
}