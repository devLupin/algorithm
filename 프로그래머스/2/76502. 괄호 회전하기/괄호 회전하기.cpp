#include <iostream>
using namespace std;

#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string s) {
    int ans = 0;
    int x = s.size();
    while(x--) {
        stack<char> st;
        bool chk = false;
        
        for(int i=0; i<s.size(); i++) {
            char c = s[i];
            
            if(c == '{' || c == '[' || c =='(') st.push(c);
            else {
                if(st.empty()) {
                    chk = false;
                    break;
                }
                
                if(c == '}' && st.top() == '{') {
                    st.pop();
                    chk = true;
                }
                else if(c == ']' && st.top() == '[') {
                    st.pop();
                    chk = true;
                }
                else if(c == ')' && st.top() == '(') {
                    st.pop();
                    chk = true;
                }
                else {
                    chk = false;
                    break;
                }
            }
        }
        if(st.empty()) ans += chk;
        
        char tmp = s[0];
        s.erase(s.begin());
        s += tmp;
    }
    return ans;
}