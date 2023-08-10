#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int sz = 100001;

int n, k;

typedef pair<int, int> pi;
vector<int> v;

bool visited[sz] = { false, };
void bfs()
{
	queue<pi> q;

	q.push({ 0,n });

	int min_time = -1;

	while (!q.empty()) {
		pi cur = q.front();
		int time = cur.first;
		int node = cur.second;
		q.pop();
		visited[node] = true;

		if (min_time >= 0 && node == k && min_time == time) {
			v.push_back(time);
		}

		if (min_time == -1 && node == k) {
			min_time = time;
			v.push_back(time);
		}

		if (node + 1 < sz && !visited[node + 1]) {
			q.push({ time + 1, node + 1 });
		}
		if (node - 1 >= 0 && !visited[node - 1]) {
			q.push({ time + 1, node - 1 });
		}
		if (node * 2 < sz && !visited[node * 2]) {
			q.push({ time + 1, node * 2 });
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;
	
	bfs();
	sort(v.begin(), v.end());

	cout << v[0] << '\n' << v.size();
	return 0;
}