#include <bits/stdc++.h>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    map<string, int> m;

	for(string s : participant) m[s]++;
	for(string s : completion) m[s]--;

	for(auto x : m)
		if(x.second != 0)
			return x.first;		
}