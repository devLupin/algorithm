#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	queue<int> q;
	for (int i = 1; i <= n; i++)
		q.push(i);

	while (!q.empty()) {
		if (q.size() == 1) {
			cout << q.front();
			break;
		}
		q.pop();
		q.push(q.front());
		q.pop();
	}
}