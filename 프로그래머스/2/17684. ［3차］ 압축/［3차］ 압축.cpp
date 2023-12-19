#include <bits/stdc++.h>
using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> mp;

    for (char c = 'A'; c <= 'Z'; c++) {
        string s = "";
        s += c;
        mp[s] = (c - 'A' + 1);
    }

    string tmp, str = "";
    for (char c : msg) {
        tmp = str;
        str += c;
        if (mp[str] > 0) continue;
        else {
            answer.push_back(mp[tmp]);
            mp[str] = (int)mp.size();
            str = c;
        }
    }

    if (mp[str] > 0) answer.push_back(mp[str]);
    else answer.push_back((int)mp.size());


    return answer;
}