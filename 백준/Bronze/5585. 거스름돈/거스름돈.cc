#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int arr[6] = { 500, 100, 50, 10, 5, 1 };

	int N; cin >> N;
	N = 1000 - N;
	int ans = 0;
	for (int i = 0; i < 6; i++) {
		ans += N / arr[i];
		N %= arr[i];
	}

	cout << ans;
	return 0;
}