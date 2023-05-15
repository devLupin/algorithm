#include <bits/stdc++.h>
using namespace std;

const int SZ = 125;
const int dy[] = { -1,1,0,0 };
const int dx[] = { 0,0,-1,1 };
int n;
int arr[SZ][SZ];
bool visited[SZ][SZ];


int bfs(void)
{
	priority_queue<tuple<int,int,int>> pq;
	pq.push({ -arr[0][0], 0, 0 });
	visited[0][0] = true;

	while (!pq.empty()) {
		auto cur = pq.top();
		pq.pop();

		int cy = get<1>(cur);
		int cx = get<2>(cur);
		int w = get<0>(cur);

		if (cy == n - 1 && cx == n - 1)
			return w;

		for (int dir = 0; dir < 4; dir++) {
			int ny = cy + dy[dir];
			int nx = cx + dx[dir];

			if (ny < 0 || nx < 0 || ny >= n || nx >= n)
				continue;
			if (!visited[ny][nx]) {
				pq.push({ w - arr[ny][nx], ny, nx });
				visited[ny][nx] = true;
			}
		}
	}
}

int main(void) 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int i = 1;
	while (true) {
		cin >> n;
		if (n == 0) break;

		fill_n(&arr[0][0], SZ * SZ, 0);
		fill_n(&visited[0][0], SZ * SZ, false);

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> arr[i][j];

		cout << "Problem " << i++ << ": " << - bfs() << '\n';
	}
	return 0;
}