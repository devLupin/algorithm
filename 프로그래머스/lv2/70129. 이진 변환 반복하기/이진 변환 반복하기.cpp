#include <bits/stdc++.h>
using namespace std;

vector<int> solution(string s) {
    vector<int> ans;

	int zero = 0;
	int cnt = 0;

	while(s != "1") {
		string tmp = "";
		for(char c : s) {
			if(c == '0') zero++;
			else tmp += c;
		}

		bitset<150'001> bit(tmp.size());
		tmp = bit.to_string();
		string ch = "";
		for(int i=0, chk=0; i<tmp.size(); i++) {
			if(chk) ch += tmp[i];
			if(!chk && tmp[i] == '1') {
				chk = 1;
				ch += '1';
			}
		}

		s = ch;
		cnt++;
	}

	return {cnt, zero};
}