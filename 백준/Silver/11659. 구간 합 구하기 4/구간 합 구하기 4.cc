#include <bits/stdc++.h>
using namespace std;

const int SZ = 100001;
int n, m, arr[SZ], prefix[SZ];
vector<int> ans;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for(int i=1; i<=n; i++)
		cin >> arr[i];
	
	for(int i=1; i<=n; i++)
		prefix[i] += prefix[i-1] + arr[i];

	while(m--) {
		int i, j;
		cin >> i >> j;
		cout << (prefix[j] - prefix[i-1]) << '\n';
	}
	
    return 0;
}