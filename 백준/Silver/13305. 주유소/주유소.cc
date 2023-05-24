#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N; cin >> N;
	vector<int> DP(N);

	vector<int> w(N-1);
	for (int i = 0; i < N - 1; i++)
		cin >> w[i];

	vector<int> node(N);
	for (int i = 0; i < N; i++)
		cin >> node[i];

	DP[0] = 0;
	DP[1] = node[0] * w[0];
	for (int i = 2; i < N; i++) {
		DP[i] = DP[i - 2] + (node[i - 2] * (w[i - 1] + w[i - 2]));
		DP[i] = min(DP[i], DP[i - 1] + (node[i - 1] * w[i - 1]));
	}
	cout << DP[N - 1];

	return 0;
}