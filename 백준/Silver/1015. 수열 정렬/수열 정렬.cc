#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N; cin >> N;
	vector<pii> v;
	for (int tmp, i = 0; i < N; i++) {
		cin >> tmp;
		v.push_back({ tmp, i });
	}
	sort(v.begin(), v.end());

	vector<int> tmp(N);
	for (int i = 0; i < N; i++)
		tmp[v[i].second] = i;

	for (int a : tmp)
		cout << a << ' ';

	return 0;
}