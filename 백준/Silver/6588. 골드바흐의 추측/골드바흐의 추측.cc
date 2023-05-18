#include<bits/stdc++.h>
using namespace std;

const int SZ = 1000000;
bool chk[SZ + 1];

void eratos(void)
{
	chk[1] = true;
	for (int i = 2; i <= sqrt(SZ); i++) {
		if (chk[i]) continue;
		for (int j = i * i; j <= SZ; j += i)
			chk[j] = true;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	eratos();

	while (true) {
		int n; cin >> n;
		if (n == 0) break;

		bool flag = false;
		for (int i = 3; i <= n; i += 2) {
			if (!chk[i] && !chk[n - i]) {
				cout << n << " = " << i << " + " << n - i;
				flag = true;
				break;
			}
		}
		if (!flag) cout << "Goldbach's conjecture is wrong.";
		cout << '\n';
	}
}