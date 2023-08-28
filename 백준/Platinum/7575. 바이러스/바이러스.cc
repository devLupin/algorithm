#include <bits/stdc++.h>
using namespace std;

const int MX = 102;
int n, k;
vector<int> code[MX];

vector<int> failure(vector<int> &a) {
	vector<int> f(a.size());
	int j=0;
	for(int i=1; i<a.size(); i++) {
		while(j > 0 && a[i] != a[j]) j = f[j-1];
		if(a[i] == a[j]) f[i] = ++j;
	}
	return f;
}

int kmp(vector<int> &t, vector<int> &p) {
    vector<int> Pi = failure(p);
    for(int i=0, j=0; i<t.size(); i++) {
        while(j>0 && t[i] != p[j]) j = Pi[j-1];
		if(j == p.size()-1) return 1;
        if(t[i] == p[j]) j++;
    }
    return 0;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	for(int m, i=0; i<n; i++) {
		cin >> m;
		for(int x; m--;) {
			cin >> x;
			code[i].push_back(x);
		}
	}

	for(int i=0; i<code[0].size()-k+1; i++) {
		vector<int> sub(k);
		for(int j=0; j<k; j++) sub[j] = code[0][i+j];

		bool chk = true;
		for(int j=1; j<n; j++) {
			auto rev = code[j];
			reverse(rev.begin(), rev.end());
			if(!kmp(code[j], sub) && !kmp(rev, sub)) chk = false;
		}

		if(chk) {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";

	return 0;
}