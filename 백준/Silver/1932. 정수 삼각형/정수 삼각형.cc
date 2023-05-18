#include <bits/stdc++.h>
using namespace std;

vector<int> v(1);
int n;

void DP(void) 
{
	int sz = v.size() - 1;
	int level = n - 2;
	for (int cnt = 0, i = sz - n; i > 0; i--, cnt++) {
		if (cnt > level) { 
			level--;
			cnt = 0;
		}
		v[i] += max(v[i + level + 1], v[i + level + 2]);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int tmp, j = 0; j <= i; j++) {
			cin >> tmp;
			v.push_back(tmp);
		}

	DP();
	cout << v[1];
	return 0;
}