#include <bits/stdc++.h>
using namespace std;
using ti3 = tuple<int,int,int>;

int n, P[302], e, cnt, ans, a, b, cost;
ti3 edge[100'002];

int Find(int x) { return (x == P[x] ? x : Find(P[x])); }
bool Union(int x, int y) {
	x = Find(x);
	y = Find(y);

	if(x == y) return false;
	P[x] = y;
	return true;
}

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for(int c, i=1; i<=n; i++) {
		cin >> c;
		edge[e++] = {c, i, n+1};
	}

	for(int i=1; i<=n; i++) {
		P[i] = i;
		for(int c, j=1; j<=n; j++) {
			cin >> c;
			if(i >= j) continue;
			edge[e++] = {c, i, j};
		}
	}
	n += 1;
	sort(edge, edge + e);

	for(int i=0; i<e; i++) {
		tie(cost, a, b) = edge[i];
		if(Union(a, b)) {
			ans += cost;
			cnt++;
			if(cnt == n) break;
		}
	}

	cout << ans;

	return 0;
}
