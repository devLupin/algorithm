#include <bits/stdc++.h>
using namespace std;

set<int> st;
string n;
bool vis[7];

bool chk(int num) {
	if (num <= 1) return false;
	for (int i = 2; i < num; i++)
		if (num % i == 0) return false;
	return true;
}

void dfs(string s) {
	if (s.size() > n.size()) return;

	int num = stoi(s);
	if (chk(num)) st.insert(num);

	for (int i = 0; i < n.size(); i++) {
		if (vis[i]) continue;

		vis[i] = true;
		dfs(s + n[i]);
		vis[i] = false;
	}
}

int solution(string numbers) {
	n = numbers;
	for (int i = 0; i < n.size(); i++) {
		string s = "";
		s += n[i];
		vis[i] = true;
		dfs(s);
		vis[i] = false;
	}
	return st.size();
}