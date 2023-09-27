#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, k, ans=0;
	cin >> n >> k;
	vector<int> v(n), d(n-1);

	for(int i=0; i<n; i++) cin >> v[i];
	sort(v.begin(), v.end());

	for(int i=1; i<n; i++) d[i-1] = v[i]-v[i-1];
	sort(d.rbegin(), d.rend());

	for(int i=k-1; i<n-1; i++) ans += d[i];
	cout << ans;

	return 0;
}