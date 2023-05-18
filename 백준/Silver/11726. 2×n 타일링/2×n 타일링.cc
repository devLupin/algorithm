#include<bits/stdc++.h>
using namespace std;

int n;
int memo[1001];

void DP()
{
	memo[1] = 1;
	memo[2] = 2;

	for (int i = 3; i <= n; i++)
		memo[i] = (memo[i - 1] + memo[i - 2]) % 10007;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	DP();
	cout << memo[n];
}