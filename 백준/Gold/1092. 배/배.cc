#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

    int n, m, ans=0;
    
    cin >> n;
    vector<int> c(n);
    for(int i=0; i<n; i++) cin >> c[i];

    cin >> m;
    vector<int> b(m);
    for(int i=0; i<m; i++) cin >> b[i];

    sort(c.begin(), c.end());
    sort(b.begin(), b.end());

    if(c.back() < b.back()) {
        cout << -1;
        return 0;
    }

    while(!b.empty()) {
        ans++;

        for(int cra=c.size()-1; cra>=0; cra--) {
            for(int bx=b.size()-1; bx>=0; bx--) {
                if(c[cra] >= b[bx]) {
                    b.erase(b.begin()+bx);
                    break;
                }
            }
        }
    }

    cout << ans;

	return 0;
}