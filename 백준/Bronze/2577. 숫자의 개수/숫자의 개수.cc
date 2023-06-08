#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b, c, arr[10] = { 0, };
	cin >> a >> b >> c;
	int n = a * b * c;
	
	while (n > 0) {
		arr[n % 10]++;
		n = n / 10;
	}

	for (int i = 0; i < 10; i++) cout << arr[i] << '\n';
	return 0;
}