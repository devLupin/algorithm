#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    int rm = *(min_element(arr.begin(), arr.end()));
    for(int x : arr)
        if(x != rm) answer.push_back(x);
    if(answer.empty()) answer.push_back(-1);
    return answer;
}