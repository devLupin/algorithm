#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	int c = a % b;

	while (c != 0) {
		a = b;
		b = c;
		c = a % b;
	}

	return b;
}

int lcm(int a, int b) { return (a * b) / gcd(a, b); }


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int TC; cin >> TC;

	while (TC--) {
		int a, b; cin >> a >> b;
		cout << lcm(a, b) << '\n';
	}

	return 0;
}