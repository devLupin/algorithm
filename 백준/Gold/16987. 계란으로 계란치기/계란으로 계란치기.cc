#include <bits/stdc++.h>
using namespace std;

const int SZ = 10;
int n, s[SZ], w[SZ];
int tmp, mx;

void solve(int cnt) {
	if(cnt == n) {
		mx = max(mx, tmp);
		return;
	}

	if(s[cnt] <= 0 || tmp == n-1) {
		solve(cnt+1);
		return;
	}

	for(int i=0; i<n; i++) {
		if(s[i] <= 0 || i == cnt) continue;

		s[cnt] -= w[i];
		s[i] -= w[cnt];
		if(s[cnt] <= 0) tmp++;
		if(s[i] <= 0) tmp++;
		solve(cnt+1);
		if(s[cnt] <= 0) tmp--;
		if(s[i] <= 0) tmp--;
		s[cnt] += w[i];
		s[i] += w[cnt];
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i=0; i<n; i++)
		cin >> s[i] >> w[i];
	
	solve(0);

	cout << mx;
    return 0;
}