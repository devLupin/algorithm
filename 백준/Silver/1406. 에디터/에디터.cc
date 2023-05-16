#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s = "", ans = "";
	cin >> s;

	list<char> li(s.begin(), s.end());
	auto cursor = li.end();

	int M; cin >> M;
	while (M--) {
		char opt, c;
		cin >> opt;

		switch (opt)
		{
		case 'L':
			if (cursor != li.begin())
				cursor--;
			break;

		case 'D':
			if (cursor != li.end())
				cursor++;
			break;

		case 'B':
			if (cursor != li.begin())
				cursor = li.erase(--cursor);
			break;

		default:
			cin >> c;
			li.insert(cursor, c);
			break;
		}
	}

	for (auto cursor : li)
		cout << cursor;
}