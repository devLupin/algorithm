#include <bits/stdc++.h>
using namespace std;

int solution(int n) 
{
    int answer = 1;
    
    for(int i = 1, sum = 1; i < n; i++)
    {
        for(int j = i + 1; j < n && sum + j <= n; j++)
            sum += j;
        if(sum == n) answer++;
        sum = 0;
    }
    
    return answer;
}