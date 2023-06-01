#include<bits/stdc++.h>
using namespace std;

typedef struct {
	int m, v;
}Jwe;

bool compare(const Jwe& a, const Jwe& b) {
	if (a.m == b.m) return a.v < b.v;
	return a.m < b.m;
}

int bag[300000];
Jwe j[300000];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		int m, v;
		cin >> m >> v;
		j[i] = { m,v };
	}

	for (int i = 0; i < k; i++)
		cin >> bag[i];

	sort(j, j + n, compare);
	sort(bag, bag + k);

	priority_queue<int> pq;
	int idx = 0;
	long long res = 0;
	for (int i = 0; i < k; i++) {
		while (idx < n && j[idx].m <= bag[i])
			pq.push(j[idx++].v);

		if (!pq.empty()) { 
			res += (long long)pq.top();
			pq.pop();
		}
	}

	cout << res;
	return 0;
}