#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

const int S = 301, E = 1201;
int n, ans;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<pii> v;

	cin >> n;
	for(int i=0; i<n; i++) {
		int sm, sd, em, ed;
		cin >> sm >> sd >> em >> ed;
		v.push_back({sm * 100 + sd, em * 100 + ed});
	}

	int t = S;
	while(t < E) {
		int next = t;

		for(int i=0; i<n; i++)
			if(v[i].first <= t && v[i].second > next)
				next = v[i].second;
		
		if(t == next) {
			cout << 0;
			return 0;
		}

		ans++;
		t = next;
	}

	cout << ans;
	return 0;
}