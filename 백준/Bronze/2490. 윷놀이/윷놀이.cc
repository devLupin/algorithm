#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 3; i++) {
		int arr[2] = { 0, };
		for (int tmp, j = 0; j < 4; j++) {
			cin >> tmp;
			arr[tmp]++;
		}

		if (arr[0] == 1 && arr[1] == 3) cout << "A" << '\n';
		else if (arr[0] == 2 && arr[1] == 2) cout << "B" << '\n';
		else if (arr[0] == 3 && arr[1] == 1) cout << "C" << '\n';
		else if (arr[0] == 4) cout << "D" << '\n';
		else cout << "E" << '\n';
	}

	return 0;
}