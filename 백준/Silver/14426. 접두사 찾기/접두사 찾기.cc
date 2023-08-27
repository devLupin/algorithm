#include <bits/stdc++.h>
using namespace std;

int n, m;
const int ROOT = 1;
int unused = 2;
const int MX = 10'000 * 500 + 5;
bool chk[MX];
int nxt[MX][26];

int c2i(char c) {return c - 'a';}

void insert(string& s) {
	int cur = ROOT;
	for(auto c : s) {
		if(nxt[cur][c2i(c)] == -1)
			nxt[cur][c2i(c)] = unused++;
		cur = nxt[cur][c2i(c)];
	}
	chk[cur] = true;
}

bool find(string& s) {
	int cur = ROOT;
	for(auto c : s) {
		if(nxt[cur][c2i(c)] == -1)
			return false;
		cur = nxt[cur][c2i(c)];
	}
	return true;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int ans = 0;

	cin >> n >> m;
	for(int i=0; i<MX; i++)
		fill(nxt[i], nxt[i]+26, -1);

	for(string s; n--;) {
		cin >> s;
		insert(s);
	}
	for(string s; m--;) {
		cin >> s;
		ans += find(s);
	}

	cout << ans;

	return 0;
}