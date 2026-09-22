#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> nums)
{
    set<int> st;
    for(int n : nums)
        st.insert(n);
    return (st.size() <= nums.size() / 2) ? st.size() : nums.size() / 2;
}