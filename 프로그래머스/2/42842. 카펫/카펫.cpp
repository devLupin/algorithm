#include <bits/stdc++.h>
using namespace std;

vector<int> solution(int brown, int yellow) 
{
    vector<int> answer;
    int area = brown + yellow;
    
    for(int w, h = 3; h <= sqrt(area); h++)
    {
        if(area % h) continue;
        w = area / h;
        if((w + h) * 2 - 4 == brown)
            return {w, h};
    }
}