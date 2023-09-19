#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	long long ans=0;
	cin >> n;

	vector<int> v(n);
	for(int i=0; i<n; i++) cin >> v[i];

	sort(v.begin(), v.end(), greater<>());

	for(int t, i=0; i<n; i++) {
		t = v[i]-(i+1-1);
		ans += (t >= 0 ? t : 0);
	}

	cout << ans;

	return 0;
}