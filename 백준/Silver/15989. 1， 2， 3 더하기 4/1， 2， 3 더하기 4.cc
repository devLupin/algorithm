#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int memo[10001][4] = { 0, };

void DP()
{
	memo[1][1] = 1;
	memo[2][1] = 1, memo[2][2] = 1;
	memo[3][1] = 1, memo[3][2] = 1, memo[3][3] = 1;

	for (int i = 4; i <= 10000; i++) {
		memo[i][1] = memo[i - 1][1];
		memo[i][2] = memo[i - 2][1] + memo[i - 2][2];
		memo[i][3] = memo[i - 3][1] + memo[i - 3][2] + memo[i - 3][3];
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	DP();

	int tc; cin >> tc;
	while (tc--) {
		int n; cin >> n;
		cout << memo[n][1] + memo[n][2] + memo[n][3] << '\n';
	}
}