#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    map<string, string> mp;
    int n, m;
    cin >> n >> m;

    while(n--) {
        string s1, s2;
        cin >> s1 >> s2;
        mp[s1] = s2;
    }

    while(m--) {
        string s;
        cin >> s;
        cout << mp[s] << '\n';
    }

    return 0;
}