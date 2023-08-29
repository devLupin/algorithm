#include <bits/stdc++.h>
using namespace std;

vector<int> counting(string s) {
	vector<int> ret(10, 0);
	for(char c : s) ret[c-'0']++;
	return ret;
}

string solution(string X, string Y) {
    string ans = "";
	
	auto x = counting(X);
	auto y = counting(Y);

	for(int i=9; i>=0; i--) {
		int mn = min(x[i], y[i]);

		for(int j=0; j<mn; j++) ans += to_string(i);
	}

	if(!ans.size()) return "-1";
	if(ans[0] == '0') return "0";
	return ans;
}