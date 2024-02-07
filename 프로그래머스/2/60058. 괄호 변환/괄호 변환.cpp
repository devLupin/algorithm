#include <bits/stdc++.h>
using namespace std;

bool is_right(string s) {
    stack<char> st;
    
    for(char c : s) {
        if(c == '(') st.push('(');
        else {
            if(st.empty()) return false;
            else st.pop();
        }
    }
    return st.empty();
} 

string solution(string p) {
    string ans = "";
    
    if(p == "") return p;
    
    string u, v;
    int l = 0, r = 0;
    for(int i=0; i<p.size(); i++) {
        char c = p[i];
        
        if(c == '(') l++;
        else if(c == ')') r++;
        
        if(l == r) {
            u = p.substr(0, i+1);
            v = p.substr(i+1);
            break;
        }
    }
    
    if(is_right(u)) {
        v = solution(v);
        ans = u + v;
    }
    
    else {
        ans = "(";
        ans += solution(v);
        ans += ")";
        
        u.erase(0, 1);
        u.erase(u.size()-1, 1);
        
        for(char c : u) {
            if(c == '(') ans += ')';
            else ans += '(';
        }
    }
    
    return ans;
}