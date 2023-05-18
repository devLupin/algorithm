#include <bits/stdc++.h>
using namespace std;

const int SZ = 1001;
bool chk[SZ];

void eratos(void)
{
	chk[1] = true;

	for (int i = 2; i <= sqrt(SZ - 1); i++) {
		if (chk[i]) continue;
		for (int j = i * i; j <= SZ - 1; j += i)
			chk[j] = true;
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	eratos();

	int n, ans = 0; 
	cin >> n;
	for (int tmp, i = 0; i < n; i++) {
		cin >> tmp;
		if (!chk[tmp]) ans++;
	}
	cout << ans;
}