#include <bits/stdc++.h>
using namespace std;

string solution(string s) {
	vector<int> v;

	string tmp = "";
	for(char c : s) {
		if(c == ' ') {
			v.push_back(stoi(tmp));
			tmp = "";
		}
		else tmp += c;
	}
	v.push_back(stoi(tmp));

	sort(v.begin(), v.end());
    return to_string(v[0]) + " " + to_string(v[v.size()-1]);
}