#include <bits/stdc++.h>
using namespace std;

string solution(string s) {
	string ans = "";

	string tmp = "";
	for(char c : s) {
		if(c == ' ') {
			ans += tmp + ' ';
			tmp = "";
		}
		else if(!tmp.size()) {
			if(c >= '0' && c <= '9') tmp += c;
			else if(c >= 'a' && c <= 'z') tmp += c-32;
			else tmp += c;
		}
		else {
			if(c >= '0' && c <= '9') tmp += c;
			else if(c >= 'A' && c <= 'Z') tmp += c+32;
			else tmp += c;
		}
	}
	ans += tmp;

	return ans;
}