#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> ret;
    
    for(const auto& cmd : commands)
    {
        const int& st = cmd[0] - 1, en = cmd[1] - 1, tg = cmd[2] - 1;
        vector<int> v(array.begin() + st, array.begin() + en + 1);
        sort(v.begin(), v.end());
        ret.push_back(v[tg]);
    }
    
    return ret;
}