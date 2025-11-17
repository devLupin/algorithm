#include <bits/stdc++.h>
using namespace std;

int solution(int k, vector<int> tangerine) 
{
    map<int, int> myMap;
    for(const int &i : tangerine)
        myMap[i]++;
    
    vector<int> vec;
    for(const auto& [k, v] : myMap)
        vec.push_back(v);
    
    sort(vec.begin(), vec.end(), greater<>());
    
    int sum = 0, cnt = 0;
    for(const int& x : vec)
    {
        if(sum >= k) break;
        sum += x; cnt++;
    }
    
    return cnt;
}