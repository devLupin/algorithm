#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;

	vector<int> v(n);
	for(int i=0; i<n; i++) cin >> v[i];

	sort(v.begin(), v.end(), greater<>());

	int i, ans = 0;
	for(i=0; i+2<n; i+=3) ans += v[i] + v[i+1];

	if(i != n)
		for(;i<n; i++) ans += v[i];

	cout << ans;

	return 0;
}