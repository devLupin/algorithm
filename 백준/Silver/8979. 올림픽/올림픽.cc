#include<bits/stdc++.h>
using namespace std;

typedef struct {
	int gold, silver, bronze, num;
}Medal;

bool compare(const Medal& a, const Medal& b) {
	if (a.gold == b.gold) {
		if (a.silver == b.silver) return a.bronze > b.bronze;
		return a.silver > b.silver;
	}
	return a.gold > b.gold;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	vector<Medal> v(n);

	for (int i = 0; i < n; i++) {
		int c, g, s, b;
		cin >> c >> g >> s >> b;

		v[c - 1] = { g,s,b,c };
	}

	sort(v.begin(), v.end(), compare);

	Medal target;

	for(int i=0; i<n; i++)
		if (v[i].num == k) {
			target = v[i];
			break;
		}

	int rank;
	for (int i = 0; i < n; i++) {
		if (v[i].gold == target.gold && v[i].silver == target.silver && v[i].bronze == target.bronze) {
			rank = i+1;
			break;
		}
	}

	cout << rank;
	return 0;
}
