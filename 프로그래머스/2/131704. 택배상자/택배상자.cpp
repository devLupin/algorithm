#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> order) {
    stack<int> st;
    int idx = 0, ans = 0;
    
    for(int i=1; i<=order.size(); i++) {
        st.push(i);
        
        while(!st.empty() && st.top() == order[idx]) {
            st.pop();
            idx++;
            ans++;
        }
    }
    
    return ans;
}