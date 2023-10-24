#include <bits/stdc++.h>
using namespace std;

bool compare(const pair<string, int> &a, const pair<string, int> &b) {
    if(a.second == b.second) return a.first > b.first;
    return a.second > b.second;
}

vector<int> solution(string s) {
    string tmp = "";
    map<string, int> mp;
    vector<int> ans;

    for (auto c : s) {
        if (c >= '0' && c <= '9') tmp += c;
        else if (c == '}' || c == ',') {
            if (tmp != "") {
                mp[tmp]++;
                tmp = "";
            }
        }
    }
    
    vector<pair<string, int>> v(mp.begin(), mp.end());
    sort(v.begin(), v.end(), compare);
    
    for(auto nxt : v) ans.push_back(stoi(nxt.first));
    
    return ans;
}