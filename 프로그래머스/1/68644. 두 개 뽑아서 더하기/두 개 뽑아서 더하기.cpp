#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> numbers) 
{
    set<int> st;
    
    for(int i=0; i<numbers.size(); i++)
        for(int j=0; j<numbers.size(); j++)
            if(i != j)
                st.insert(numbers[i] + numbers[j]);
    
    return vector<int>(st.begin(), st.end());
}