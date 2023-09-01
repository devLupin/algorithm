#include <bits/stdc++.h>
using namespace std;

int tc, n, k, t, m, a, b, c;
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

    cin >> tc;
    while (tc--) {
		int d[101][101] = {0, }, tim[101] = {0, }, cnt[101] = {0, };
		cin >> n >> k >> t >> m;
        t--;
        for (int i = 0; i < m; i++) {
            cin >> a >> b >> c;
            a--; b--;
            d[a][b] = max(d[a][b], c);
            cnt[a]++;
            tim[a] = i;
        }
        vector<pair<int, pair<int, pair<int, int>>>> v;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = 0; j < k; j++) 
                sum += d[i][j];
            v.push_back({ sum,{-cnt[i],{-tim[i],i}} });
        }
        sort(v.begin(), v.end());

        for (int i = 0; i < n; i++)
            if (v[i].second.second.second == t) cout << n-i << '\n';
    }
 
    return 0;
}
