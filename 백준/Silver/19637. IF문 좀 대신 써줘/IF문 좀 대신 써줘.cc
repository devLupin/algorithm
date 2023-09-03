#include <bits/stdc++.h>
using namespace std;
using pis = pair<int, string>;

int n, m, p;
string s;
vector<pis> v;

string upper_bound(int t) {
    int l = 0, r = v.size()-1;
    for(int m, cmp; l < r;) {
        m = (l+r)/2;
        cmp = v[m].first;
        if(cmp >= t) r = m;
        else l = m+1;
    }
    return v[r].second;
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

    cin >> n >> m;

    for(int i=0; i<n; i++) {
        cin >> s >> p;
        v.push_back({p, s});
    }

    while(m--) {
        cin >> p;

        cout << upper_bound(p) << '\n';
    }
 
    return 0;
}