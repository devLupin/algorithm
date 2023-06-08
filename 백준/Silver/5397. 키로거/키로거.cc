#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int TC; cin >> TC;
	while (TC--) {
		string str;
		cin >> str;

		list<char> li = {};
		auto p = li.begin();

		for (char c : str) {
			if (c == '<') {
				if (p != li.begin()) p--;
			}
			else if (c == '>') {
				if (p != li.end()) p++;
			}
			else if (c == '-') {
				if (p != li.begin()) p = li.erase(--p);
			}
			else li.insert(p, c);
		}

		for (char c : li) cout << c;
		cout << '\n';
	}

	return 0;
}