#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int year = 1;
	int E, S, M;
	cin >> E >> S >> M;

	while (true) {
		if ((year - E) % 15 == 0 && (year - S) % 28 == 0 && (year - M) % 19 == 0) {
			cout << year;
			break;
		}
		year++;
	}

	return 0;
}