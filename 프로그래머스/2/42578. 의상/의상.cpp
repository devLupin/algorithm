#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int ret = 1;
	map<string, int> m;
	for(auto v : clothes) m[v[1]]++;

	for(auto x : m) ret *= (x.second + 1);
	return ret - 1;
}