#include <bits/stdc++.h>
using namespace std;

int solution(string t, string p) 
{
    int answer = 0;
    unsigned long long cmp = stoull(p);
    
    for(int i=0; i<=t.size() - p.size(); i++)
    {
        string sub = t.substr(i, p.size());
        if (stoull(sub) <= cmp) answer++;
    }
    
    return answer;
}