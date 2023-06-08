#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int arr[21];
	for (int i = 1; i < 21; i++) arr[i] = i;

	for (int s, e, i = 0; i < 10; i++) {
		cin >> s >> e;

		int n = (e - s) / 2;
		for (int j = 0; j <= n; j++) {
			int tmp = arr[s + j];
			arr[s + j] = arr[e - j];
			arr[e - j] = tmp;
		}
	}

	for (int i = 1; i < 21; i++)
		cout << arr[i] << ' ';
}