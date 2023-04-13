#include <iostream>
using namespace std;

int DP[1000];
int arr[1000];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int ans = 0;
	for (int i = 0; i < n; i++) {
		DP[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i] && DP[i] < DP[j] + 1)
				DP[i] = DP[j] + 1;
		}
		ans = (ans > DP[i]) ? ans : DP[i];
	}

	cout << ans;
	return 0;
}