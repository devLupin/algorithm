#include <bits/stdc++.h>
using namespace std;

string t, p;
vector<int> f, ans;

void failure(string &s) {
	f.assign(s.size(), 0);
	int j = 0;
	for(int i = 1; i < s.size(); i++) {
		while(j > 0 && s[i] != s[j]) j = f[j-1];
		if(s[i] == s[j]) f[i] = ++j;
	}
}

void solve() {
	int j = 0;
	for(int i = 0; i < t.size(); i++) {
		while(j > 0 && t[i] != p[j]) j = f[j-1];
		if(t[i] == p[j]) j++;
		if(j == p.size()) {
			ans.push_back(i-j+1);
			j = f[j-1];
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	getline(cin, t);
	getline(cin, p);

	failure(p);
	solve();

	cout << ans.size() << '\n';
	for(int x : ans) cout << x+1 << ' ';

	return 0;
}