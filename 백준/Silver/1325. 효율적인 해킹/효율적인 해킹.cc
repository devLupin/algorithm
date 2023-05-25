#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

const int SZ = 10001;
vector<int> graph[SZ];
bool visited[SZ];
int n, m, cnt;


void dfs(int start) 
{
	cnt++;
	visited[start] = true;

	for (int i = 0; i < graph[start].size(); i++)
		if (!visited[graph[start][i]])
			dfs(graph[start][i]);
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;

	vector<pii> v;

	for (int i = 0; i < m; i++) {
		int to, from;
		cin >> to >> from;
		graph[from].push_back(to);
	}

	for (int i = 1; i <= n; i++) {
		dfs(i);
		v.push_back({ ~cnt,i });

		cnt = 0;
		memset(visited, false, sizeof(visited));
	}
	
	sort(v.begin(), v.end());

	cout << v[0].second << ' ';
	for (int i = 1; i < v.size(); i++)
		if (v[0].first == v[i].first)
			cout << v[i].second << ' ';

	return 0;
}