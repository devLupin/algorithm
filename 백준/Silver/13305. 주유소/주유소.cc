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

	long long ans = node[0] * w[0];
	int i = 1;
	while (i < N-1) {
		if (node[i] < node[i + 1])
			ans += (node[i] * (w[i] + w[i + 1]));
		else
			ans += (node[i] * w[i] + node[i + 1] * w[i + 1]);
		i += 2;
	}
	cout << ans;
	return 0;
}