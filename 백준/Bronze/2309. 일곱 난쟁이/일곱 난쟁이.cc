#include <bits/stdc++.h>
using namespace std;

int idx1, idx2, arr[9], sum = 0;
bool flag = false;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	sort(arr, arr + 9);

	for (int i = 0; i < 8 && !flag; i++) {
		for (int j = i + 1; j < 9; j++) {
			int tmp = sum - arr[i] - arr[j];

			if (tmp == 100) {
				idx1 = i;
				idx2 = j;
				flag = true;
				break;
			}
		}
	}

	for (int i = 0; i < 9; i++) {
		if (i == idx1 || i == idx2) continue;
		cout << arr[i] << '\n';
	}
	
	return 0;
}