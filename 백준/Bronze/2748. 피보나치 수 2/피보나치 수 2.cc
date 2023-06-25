#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
ll fibo[100];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	
	fibo[1] = 1, fibo[2] = 1;
	for (int i = 3; i <= n; i++)
		fibo[i] = fibo[i - 1] + fibo[i - 2];

	cout << fibo[n];
	return 0;
}