#include <bits/stdc++.h>
using namespace std;

int solution(string dartResult) {
    vector<int> v;
    
    string num = "";
    for(auto c : dartResult) {
        if(c >= '0' && c <= '9') num += c;
        
        else if (c >= 'A' && c <= 'Z') {
            int n = stoi(num);
            
            if(c == 'S') v.push_back(n);
            else if (c == 'D') v.push_back(n*n);
            else if(c == 'T') v.push_back(n*n*n);
            
            num = "";
        }
        
        else { 
            if(c == '*') {
                int len = v.size();
                if(len >= 2) {
                    v[len-1] *= 2;
                    v[len-2] *= 2;
                }
                else v[len-1] *= 2;
            }
            else v[v.size()-1] *= -1;
        }
    }
    
    int ans = 0;
    for(auto nxt : v) ans += nxt;
    
    return ans;
}