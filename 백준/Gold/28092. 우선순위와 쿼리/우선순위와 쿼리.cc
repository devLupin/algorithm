#include <bits/stdc++.h>
using namespace std;

const int SZ = 100'002;
int N, Q, P[SZ], Cy[SZ], Size[SZ];

struct T{
	int r, s;
	bool operator<(const T& t) const { return s ^ t.s ? s > t.s : r < t.r; }
};

set<T> S;

int Find(int x) { return P[x] = x == P[x] ? x : Find(P[x]); }
void Merge(int x, int y) {
	S.erase({x, Size[x]});
	S.erase({y, Size[y]});

	Cy[x] += (x == y);

	if(x ^ y) {
		if(Cy[x] + Cy[y]) Cy[x] = Cy[y] = 1;
		else {
			if (x > y) S.insert({ P[x] = y, Size[y] += Size[x] });
            else S.insert({ P[y] = x, Size[x] += Size[y] });
		}
	}
}

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> Q;

	for(int i=1; i<=N; i++) S.insert({P[i] = i, Size[i] = 1});

	for(int o, u, v; Q--;) {
		cin >> o;

		if(o == 1) {
			cin >> u >> v;
			Merge(Find(u), Find(v));
		}
		else {
			cout << (*S.begin()).r << '\n';
			S.erase(S.begin());
		}
	}
}
