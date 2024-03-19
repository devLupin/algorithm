#include <bits/stdc++.h>
using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    
    vector<int> v;
    for(string s : timetable) {
        string HH = s.substr(0, 2);
        string MM = s.substr(3, 2);
        v.push_back(stoi(HH) * 60 + stoi(MM));
    }
    sort(v.begin(), v.end());
    
    int st = 540, idx = 0, ans = 0;
    for(int i = 1; i <= n; i++, st += t) {
        int cnt = 0;
        
        for(int j = idx; j < v.size() && v[j] <= st; j++) {
            idx++;
            cnt++;
            if(cnt == m) break;
        }
        
        if(i == n) {
            if(cnt == m) ans = v[idx - 1] - 1;
            else ans = st;
        }
    }
    
    int hour = ans / 60;
    int min = ans % 60;
    
    if (hour < 10)
        answer = "0" + to_string(hour) + ":";
    else
        answer = to_string(hour) + ":";
    
    if (min < 10)
        answer = answer + "0" + to_string(min);
    else
        answer = answer + to_string(min);
    
    return answer;
}