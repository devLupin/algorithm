#include <queue>
#include <iostream>
using namespace std;
using pii = pair<int, int>;

int F, S, G, U, D;
bool visited[1000001] = { false, };

int bfs() 
{
	queue<pii> q;
	q.push({ S, 0 });
	visited[S] = true;

	while (!q.empty()) {
		pii cur = q.front();
		q.pop();

		if (cur.first == G)
			return cur.second;

		int uy = cur.first + U;
		int dy = cur.first - D;

		if (uy <= F && !visited[uy]) {
			q.push({ uy, cur.second + 1 });
			visited[uy] = true;
		}
		if (dy >= 1 && !visited[dy]) {
			q.push({ dy, cur.second + 1 });
			visited[dy] = true;
		}
	}

	return -1;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> F >> S >> G >> U >> D;

	int ans = bfs();
	if (ans >= 0)
		cout << ans;
	else
		cout << "use the stairs";
}