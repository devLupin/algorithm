#include <bits/stdc++.h>
#define TOP st.top()
using namespace std;
using pii = pair<int, int>;

vector<int> solution(vector<int> prices) {
    int sz = prices.size();
    vector<int> ans(sz);
    stack<int> st;

    for(int i=0; i<sz; i++) {
        while(!st.empty() && prices[TOP] > prices[i]) {
            ans[TOP] = i - TOP;
            st.pop();
        }
        st.push(i);
    }
    
    while(!st.empty()) {
        ans[TOP] = sz - 1 - TOP;
        st.pop();
    }

    return ans;
}