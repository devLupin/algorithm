#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N; cin >> N;

	vector<long long> w(N-1);
	for (int i = 0; i < N - 1; i++)
		cin >> w[i];

	vector<int> node(N);
	for (int i = 0; i < N; i++)
		cin >> node[i];

	long long ans = 0;
	long long x = node[0];
	long long op = 0;
	for (int i = 1; i < N; i++) {
		if (node[i] > x) {
			op += w[i - 1];
			continue;
		}
		else {
			ans += (x * (op + w[i - 1]));
			x = node[i];
			op = 0;
		}
	}
	ans += x * op;
	cout << ans;

	return 0;
}
