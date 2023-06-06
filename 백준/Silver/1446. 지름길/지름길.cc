#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int INF = 0x3f3f3f;
const int SZ = 10001;

int n, d;
vector<int> DP(SZ, INF);
vector<pii> v[SZ];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> d;

	for (int i = 0; i < n; i++) {
		int src, dest, w;
		cin >> src >> dest >> w;
		v[dest].push_back({ src, w });
	}

	DP[0] = 0;
	for (int i = 1; i <= d; i++) {
		if (v[i].size() == 0) DP[i] = DP[i - 1] + 1;
		else {
			for (auto a : v[i])
				DP[i] = min(DP[i], min(DP[i - 1] + 1, DP[a.first] + a.second));
		}
	}

	cout << DP[d];
	return 0;
}