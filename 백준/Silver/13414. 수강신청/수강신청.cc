#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    unordered_map<string, int> um;
    int k, l;
    cin >> k >> l;
    for(int i=0; i<l; i++) {
        string s;
        cin >> s;
        
        if(um.find(s) != um.end()) {
            um.erase(s);
            um.insert({s, i});
        }
        else um.insert({s, i});
    }

    vector<pair<string, int>> v(um.begin(), um.end());
    sort(v.begin(), v.end(), [](const auto &a, const auto &b) {return a.second < b.second;});

    int sz = min(k, (int)v.size());
    for(int i=0; i<sz; i++) cout << v[i].first << '\n'; 

    return 0;
}