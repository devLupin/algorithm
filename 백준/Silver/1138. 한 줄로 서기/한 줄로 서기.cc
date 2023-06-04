#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, arr[10] = { 0, };
	cin >> n;

	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;

		for (int j = 0; j < n; j++) {
			if (tmp == 0 && arr[j] == 0) {
				arr[j] = i + 1;
				break;
			}
			else if (arr[j] == 0) tmp--;
		}
	}

	for (int i = 0; i < n; i++)
		cout << arr[i] << ' ';

	return 0;
}