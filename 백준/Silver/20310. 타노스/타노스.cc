#include <bits/stdc++.h>
using namespace std;

string s, s0, s1, ans;

int main() {
	ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;
    for(char c : s) {
        if(c == '0') s0 += '0';
        else s1 += '1';
    }

    for(int i=0; i<s0.size()/2; i++) ans += s0[i];
    for(int i=0; i<s1.size()/2; i++) ans += s1[i];

    cout << ans;

	return 0;
}