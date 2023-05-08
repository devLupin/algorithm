#include <iostream>
using namespace std;

bool search(string in, int start, int end)
{
	if (start >= end)
		return true;

	int left = start, right = end;

	while (left < right)
		if (in[left++] == in[right--])
			return false;

	return search(in, start, right - 1);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int tc; cin >> tc;
	while (tc--) {
		string in;
		cin >> in;

		bool ans = search(in, 0, in.size() - 1);
		cout << ((ans) ? "YES\n" : "NO\n");
	}

	return 0;
}