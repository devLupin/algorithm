#include <iostream>
#include <algorithm>
#define FOR(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int cnt = 0, ans = -1;
	int arr[26] = { 0, };
	string str;
	cin >> str;

	FOR(i, str.size()) {
		int idx = (str[i] >= 'a') ? str[i] - 'a' : str[i] - 'A';
		(arr[idx])++;
	}

	FOR(i, 26) {
		if (cnt < arr[i]) {
			cnt = arr[i];
			ans = i;
		}
		else if (cnt == arr[i])
			ans = -1;
	}

	char ch = (ans == -1) ? '?' : 'A' + ans;
	cout << ch;
}