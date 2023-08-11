#include <bits/stdc++.h>
using namespace std;

int V, E, a, b, c, P[10'002], ans;
tuple<int,int,int> edge[1'000'002];

int find(int x) {
	if(P[x] == x) return x;
	else return P[x] = find(P[x]);
}

void uni(int f, int t) {
	f = find(f);
	t = find(t);
	P[t] = f;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> V >> E;
	for(int i=0; i<E; i++){
		cin >> a >> b >> c;
		edge[i] = {c, a, b};
	}

	sort(edge, edge+E);
	for(int i=1; i<=V; i++) P[i] = i;


	for(int i=0; i<E; i++) {
		int f, t, cost;
		tie(cost, f, t) = edge[i];

		if(find(f) != find(t)) {
			uni(f, t);
			ans += cost;
		}
	}

	cout << ans;

	return 0;
}