#include <bits/stdc++.h>
using namespace std;

const int SZ = 10;
int idx, n, m, arr[SZ], v[SZ];
bool vis[10002];

void solve(int cnt, int s) {
	if (cnt == m) {
		for(int i=0; i<m; i++)
			cout << v[i] << ' ';
		cout << '\n';
		return;
	}

	for(int i=s; i<idx; i++) {
		v[cnt] = arr[i];
		solve(cnt+1, i);
		v[cnt] = 0;
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for(int tmp, i=0; i<n; i++) {
		cin >> tmp;
		if(!vis[tmp]) {
			vis[tmp] = true;
			arr[idx++] = tmp;
		}
	}
	
	sort(arr, arr+idx);

	solve(0, 0);
    return 0;
}