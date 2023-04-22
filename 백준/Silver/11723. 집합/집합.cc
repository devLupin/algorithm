#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	bool arr[21];
	fill_n(&arr[0], 21, false);

	vector<int> ans;

	int m; cin >> m;
	while (m--) {
		string opt;
		int v;
		cin >> opt;

		if (opt != "all" && opt != "empty")
			cin >> v;

		if (opt == "add")
			arr[v] = true;
		else if (opt == "remove")
			arr[v] = false;
		else if (opt == "check")
			cout << (arr[v] ? 1 : 0) << '\n';
		else if (opt == "toggle")
			arr[v] = !arr[v];
		else if (opt == "all")
			fill_n(&arr[0], 21, true);
		else
			fill_n(&arr[0], 21, false);
	}
	
	return 0;
}