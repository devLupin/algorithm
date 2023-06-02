#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;
using psi = pair<string, int>;

bool compare(const psi &a, const psi &b) {
	if (a.second == b.second) {
		if (a.first.size() == b.first.size()) return a.first < b.first;
		return a.first.size() > b.first.size();
	}
	return a.second > b.second;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	unordered_map<string, int> um;
	vector<string> v;
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string tmp; cin >> tmp;
		if (tmp.size() >= m) um[tmp]++;
	}
	
	vector<psi> tmp(um.begin(), um.end());
	sort(tmp.begin(), tmp.end(), compare);

	for (psi a : tmp) cout << a.first << '\n';
	return 0;
}