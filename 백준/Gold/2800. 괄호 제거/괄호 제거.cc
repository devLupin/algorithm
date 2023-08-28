#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

stack<int> st;
vector<pii> v;
set<string> ans;
bool vis[11];

string remove_x(string cur, int n) {
	pii target = v[n];
	string s = "";

	for(int i=0; i<cur.size(); i++) {
		if(i != target.first && i != target.second) s += cur[i];
		else s += ' ';
	}

	return s;
}

void dfs(int cnt, string cur) {
	if(cnt > v.size()) return;

	for(int i=cnt; i<v.size(); i++) {
		if(!vis[i]) {
			string tmp;
			vis[i] = true;
			tmp = remove_x(cur, i);
			
			string s = "";
			for(char c : tmp) if(c != ' ') s += c;
			ans.insert(s);

			dfs(cnt+1, tmp);
			vis[i] = false;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;

	for(int i=0; i<s.size(); i++) {
		if(s[i] == '(') st.push(i);
		else if(s[i] == ')') {
			v.push_back({st.top(), i});
			st.pop();
		}
	}

	dfs(0, s);
	for(auto a : ans) cout << a << '\n';

	return 0;
}