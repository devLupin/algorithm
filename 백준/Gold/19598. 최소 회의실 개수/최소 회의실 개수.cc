#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

    priority_queue<int, vector<int>, greater<int>> pq;
	int n, ans = 1; 
    cin >> n;

    vector<pii> v(n);
	for(int i=0; i<n; i++)
        cin >> v[i].first >> v[i].second;

    sort(v.begin(), v.end());
    pq.push(v[0].second);

    for(int i=1; i<n; i++) {
        while(!pq.empty() && pq.top() <= v[i].first) pq.pop();
        pq.push(v[i].second);
        ans = max(ans, (int)pq.size());
    }

    cout << ans;

	return 0;
}