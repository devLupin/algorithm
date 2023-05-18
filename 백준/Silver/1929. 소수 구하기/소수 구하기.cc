#include <bits/stdc++.h>
using namespace std;

const int SZ = 10000001;
bool chk[SZ];

void eratos(void)
{
	chk[1] = true;

	for (int i = 2; i <= sqrt(SZ - 1); i++) {
		if (chk[i]) continue;
		for (int j = i * i; j <= SZ - 1; j += i)
			chk[j] = true;
	}

	return;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	eratos();

	int M, N;
	cin >> M >> N;
	for (int i = M; i <= N; i++)
		if (!chk[i])
			cout << i << '\n';
	
	return 0;
}