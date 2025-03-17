#include <bits/stdc++.h>
using namespace std;

bool solution(string s)
{
    stack<char> st;
    int idx = 0;
    
    while(idx < s.size())
    {
        if(s[idx] == '(') 
            st.push('(');
        else
        {
            if(st.empty()) return false;
            st.pop();
        }
        idx++;
    }
    return st.empty();
}