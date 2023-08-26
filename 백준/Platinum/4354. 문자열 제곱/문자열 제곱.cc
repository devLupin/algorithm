#include <bits/stdc++.h>
using namespace std;

vector<int> failure(string p) {
	vector<int> f(p.size());
	int j=0;
	for(int i=1; i<p.size(); i++) {
		while(j > 0 && p[i] != p[j]) j = f[j-1];
		if(p[i] == p[j]) f[i] = ++j;
	}
	return f;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for(string p;;) {
		cin >> p;
		if(p[0] == '.') break;

		auto f = failure(p);
		int tmp = p.size() - f[p.size()-1];
		if(p.size() % tmp) cout << 1;
		else cout << p.size() / tmp;
		cout << '\n';
	}

	return 0;
}