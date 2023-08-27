#include <bits/stdc++.h>
using namespace std;

const int MX = 100'000 * 10 + 5;
const int ROOT = 1;

int unused = ROOT + 1;
int nxt[MX][26];
unordered_map<string, int> user;

int c2i(char c) { return c - 'a'; }

void insert(string& s) {
	int cur = ROOT;
	for(auto c : s) {
		if(nxt[cur][c2i(c)] == -1)
			nxt[cur][c2i(c)] = unused++;
		cur = nxt[cur][c2i(c)];
	}
}

string find(string& s) {
	string tmp = "";
	int cur = ROOT;
	for(auto c : s) {
		tmp += c;
		if(nxt[cur][c2i(c)] == -1) return tmp;
		cur = nxt[cur][c2i(c)];
	}
	if(user[s] > 1) tmp += to_string(user[s]);
	return tmp;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for(int i=0; i<MX; i++)
		fill(nxt[i], nxt[i]+26, -1);

	int n;
	cin >> n;
	for(string s; n--;) {
		cin >> s;
		user[s]++;
		cout << find(s) << '\n';
		insert(s);
	}
}