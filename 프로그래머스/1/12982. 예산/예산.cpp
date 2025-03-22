#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> d, int budget) 
{
    int answer = 0;
    sort(d.begin(), d.end());
    
    for(int x : d)
    {
        if(budget - x >= 0)
        {
            answer++;
            budget -= x;
        }
        else break;
    }
    
    return answer;
}