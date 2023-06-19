#include <bits/stdc++.h>
using namespace std;

const int SZ = 10;
int n, m, arr[SZ], v[SZ];

void solve(int cnt, int cur) {
	if(cnt == m) {
		for(int i=0; i<m; i++)
			cout << v[i] << ' ';
		cout << '\n';

		return;
	}

	int tmp = 0;
	for(int i=cur; i<n; i++) {
		if(tmp != arr[i]) {
			tmp = v[cnt] = arr[i];
			solve(cnt+1, i+1);
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for(int i=0; i<n; i++)
		cin >> arr[i];
	
	sort(arr, arr+n);
	solve(0, 0);
	
    return 0;
}