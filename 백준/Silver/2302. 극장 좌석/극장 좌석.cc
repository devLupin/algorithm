#include <bits/stdc++.h>
using namespace std;

const int SZ = 41;
int tmp, ans, n, m, DP[SZ];
vector<int> v;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;

	v.push_back(0);
	while(m--) {
		cin >> tmp;
		v.push_back(tmp);
	}
	v.push_back(n+1);

	DP[0] = DP[1] = 1;
	DP[2] = 2;
	for(int i=3; i<=n; i++) DP[i] = DP[i-1] + DP[i-2];

	ans = 1;
	for(int i=1; i<v.size(); i++) ans *= DP[v[i] - v[i-1] - 1];

    cout << ans; 
	return 0;
}