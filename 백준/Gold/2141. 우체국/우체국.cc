#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
vector<pair<int, int>> v;
ll D[100'002];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

    cin >> n;
    v.assign(n, {});
    for(int i=0; i<n; i++)
        cin >> v[i].first >> v[i].second;

    sort(v.begin(), v.end());

    D[0] = v[0].second;
    for(int i=1; i<n; i++) D[i] = D[i-1] + v[i].second;

    int l=0, r=n-1, ans = 0x3f3f3f;
    while(l <= r) {
        int m = (l+r) / 2;

        if(D[m] >= D[n-1] - D[m]) {
            r = m - 1;
            ans = min(ans, v[m].first);
        }
        else l = m+1;
    }

    cout << ans;
	return 0;
}