#include <bits/stdc++.h>
using namespace std;

const int SZ = 1500005;
int n, T[SZ], P[SZ];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for(int i=1; i<=n; i++) {
		cin >> T[i] >> P[i];
	}

	for(int i=n; i>=1; i--) {
		if(i + T[i] <= n+1) P[i] = max(P[i] + P[i + T[i]], P[i+1]);
		else P[i] = P[i+1];
	}

	cout << *max_element(P, P+n+1);
	return 0;
}