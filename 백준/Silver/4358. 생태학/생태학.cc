#include <bits/stdc++.h>
using namespace std;

map<string, int> m;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int cnt = 0;
	string s;

	while(getline(cin, s)) {
		cnt++;
		m[s]++;
	}

	cout << fixed;
	cout.precision(4);
	for(auto it = m.begin(); it != m.end(); it++) {
		double cur = (double)(it->second) / cnt * 100;
		cout << it->first << ' ' << cur << '\n';
	}

	return 0;
}