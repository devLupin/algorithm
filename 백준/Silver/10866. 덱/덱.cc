#include <bits/stdc++.h>
using namespace std;

void print(int n) { cout << n << '\n'; }

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	deque<int> dq;
	int n; cin >> n;
	while (n--) {
		string opt; cin >> opt;
		int tmp;

		if (opt == "push_front") {
			cin >> tmp;
			dq.push_front(tmp);
		}
		else if (opt == "push_back") {
			cin >> tmp;
			dq.push_back(tmp);
		}
		else if (opt == "pop_front") {
			if (dq.empty()) print(-1);
			else {
				print(dq.front());
				dq.pop_front();
			}
		}
		else if (opt == "pop_back") {
			if (dq.empty()) print(-1);
			else {
				print(dq.back());
				dq.pop_back();
			}
		}
		else if (opt == "size") print(dq.size());
		else if (opt == "empty") print(dq.empty() ? 1 : 0);
		else if (opt == "front") print(dq.empty() ? -1 : dq.front());
		else print(dq.empty() ? -1 : dq.back());
	}
	return 0;
}