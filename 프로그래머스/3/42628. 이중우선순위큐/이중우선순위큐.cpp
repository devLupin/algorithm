#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> operations) {
    priority_queue<int> mx;
    priority_queue<int, vector<int>, greater<int>> mn;
    int cnt = 0;
    vector<int> ans;
    
    for(string s : operations) {
        char opt = s[0];
        int val = stoi(s.substr(1, s.size()));
        
        if(cnt == 0) {
            while(!mx.empty()) mx.pop();
            while(!mn.empty()) mn.pop();
        }
        
        if(opt == 'I') {
            mx.push(val);
            mn.push(val);
            cnt++;
        }
        
        else if(cnt > 0) {
            if(val == 1) mx.pop();
            else mn.pop();
            cnt--;
        }
    }
    
    if(cnt == 0) {
        ans.push_back(0);
        ans.push_back(0);
    }
    else {
        ans.push_back(mx.top());
        ans.push_back(mn.top());
    }
    
    return ans;
}