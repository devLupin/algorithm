#include <bits/stdc++.h>
using namespace std;

string solution(string number, int k) {
    list<char> st;

    for (char num : number) {
        while (k > 0 && !st.empty() && st.back() < num) {
            st.pop_back();
            k--;
        }
        st.push_back(num);
    }

    while (k--) st.pop_back();

    string answer = "";
    
    for (auto it = st.begin(); it != st.end(); it++)
        answer += *it;

    return answer;
}