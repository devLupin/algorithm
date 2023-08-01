#include <bits/stdc++.h>
using namespace std;

int TC, n, ans;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> TC;

    while(TC--) {
        cin >> n;

        map<string, int> mp;

        while(n--) {
            string a, b;
            cin >> a >> b;
            mp[b]++;
        }

        ans = 1;
        for(auto x : mp) ans *= x.second + 1;
        cout << ans-1 << '\n';
    }

    return 0;
}