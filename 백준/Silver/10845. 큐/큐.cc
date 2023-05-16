#include <bits/stdc++.h>
using namespace std;



int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	queue<int> q;

	int N; cin >> N;
	while (N--) {
		string opt; cin >> opt;

		if (opt == "push") {
			int tmp; cin >> tmp;
			q.push(tmp);
		}
		else if (opt == "pop") {
			if (q.empty()) cout << -1 << '\n';
			else {
				cout << q.front() << '\n';
				q.pop();
			}
		}
		else if (opt == "size")
			cout << q.size() << '\n';
		else if (opt == "empty")
			cout << ((q.empty()) ? 1 : 0) << '\n';
		else if (opt == "front")
			cout << (!q.empty() ? q.front() : -1) << '\n';
		else
			cout << (!q.empty() ? q.back() : -1) << '\n';
	}

	return 0;
}