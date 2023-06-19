#include <bits/stdc++.h>
using namespace std;

const int SZ = 26;
int L, C;
char pw[SZ], v[SZ];

void solve(int cnt, int s) {
	if(cnt == L) {
		string str = "";
		int cnt1=0, cnt2=0;
		for(int i=0; i<L; i++) {
			if(v[i] == 'a' || v[i] == 'e' || v[i] == 'i' || v[i] == 'o' || v[i] == 'u') cnt1++;
			else cnt2++;
			str += v[i];
		}
		
		if(cnt1 >= 1 && cnt2 >= 2)
			cout << str << '\n';

		return;
	}

	for(int i=s; i<C; i++) {
		v[cnt] = pw[i];
		solve(cnt+1, i+1);
		v[cnt] = '\0';
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> L >> C;
	for(int i=0; i<C; i++)
		cin >> pw[i];

	sort(pw, pw+C);

	solve(0, 0);
    return 0;
}