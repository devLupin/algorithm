#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    map<string, int> mp; 

    int n;
    cin >> n;

    while(n--) {
        string s1, s2;
        cin >> s1 >> s2;

        if(s2 == "enter") mp.insert({s1, 1});
        else mp.erase(s1);
    }

    vector<string> v;
    for(auto a : mp) v.push_back(a.first);

    sort(v.begin(), v.end(), greater<>());
    for(auto s : v) cout << s << '\n';

    return 0;
}