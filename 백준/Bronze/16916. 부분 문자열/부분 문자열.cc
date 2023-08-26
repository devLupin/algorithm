#include <bits/stdc++.h>
using namespace std;

string S, P;

vector<int> failure(string &s) {
	vector<int> f(s.size());
	
	int j=0;
	for(int i=1; i<s.size(); i++) {
		while(j>0 && s[i] != s[j]) j = f[j-1];
		if(s[i] == s[j]) f[i] = ++j;
	}

	return f;
}

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> S >> P;
	auto f = failure(P);

	int j=0;
	for(int i=0; i<S.size(); i++) {
		while(j > 0 && S[i] != P[j]) j = f[j-1];
		if(S[i] == P[j]) j++;
		if(j == P.size()) {
			cout << 1;
			return 0;
		}
	}

	cout << 0;
	return 0;
}
