#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int main(void) 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m; cin >> n >> m;

	priority_queue<pii> pq;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		int dist = -1, pos = -1;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] != 'S' && s[i] != 'F' && s[i] != '.') {
				dist = i;
				pos = s[i] - '0';
			}
		}
		if (dist == -1) continue;

		dist = s.size() - 1 - dist;
		pq.push({ ~dist, pos });
	}

	int arr[10] = { 0, };

	int prev = -1, rank = 0;
	while (!pq.empty()) {
		pii cur = pq.top();
		pq.pop();
		cur.first = ~cur.first;

		if (prev != -1 && prev == cur.first)
			arr[cur.second] = rank;
		else {
			arr[cur.second] = ++rank;
			prev = cur.first;
		}
	}

	for (int i = 1; i < 10; i++)
		cout << arr[i] << '\n';

	return 0;
}