#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, r_int=0, b_int=0;
	string s = "X";

	cin >> n;
	for(int i=0; i<n; i++) {
		char c;
		cin >> c;
		s += c;
	}

	for(int i=1; i<s.size(); i++) {
		if(s[i-1] != s[i]) {
			if(s[i] == 'B') b_int++;
			else if(s[i] == 'R') r_int++;
		}
	}

	cout << min(b_int, r_int)+1;
	return 0;
}