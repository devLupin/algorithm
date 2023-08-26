#include <bits/stdc++.h>
using namespace std;

string s, k;

vector<int> failure(string &s) {
	vector<int> f(s.size());
	int j = 0;
	for (int i = 1; i < (int)s.size(); i++) {
		while (j > 0 && s[i] != s[j]) j = f[j - 1];
		if (s[i] == s[j]) f[i] = ++j;
	}
	return f;
}

bool solve(vector<int> f) {
	int j = 0;
	for (int i = 0; i < (int)s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') continue;
		while (j > 0 && s[i] != k[j]) j = f[j - 1];
		if (s[i] == k[j]) j++;
		if (j == (int)k.size()) return 1;
	}
	return 0;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> s >> k;
	cout << solve(failure(k));
	return 0;
}