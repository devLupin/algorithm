#include <bits/stdc++.h>
#define S first
#define T second
using namespace std;
using pii = pair<int,int>;

priority_queue<int> pq;
vector<pii> v;
int n;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for(int s, t, i=0; i<n; i++) {
		cin >> s >> t;
		v.push_back({s, t});
	}

	sort(v.begin(), v.end());

	pq.push(~v[0].T);
	for(int i=1; i<n; i++) {
		pq.push(~v[i].T);
		if(~pq.top() <= v[i].S) pq.pop();
	}
	
	cout << pq.size();
	return 0;
}