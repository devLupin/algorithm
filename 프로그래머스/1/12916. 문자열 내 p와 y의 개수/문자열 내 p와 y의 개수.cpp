#include <bits/stdc++.h>
using namespace std;

bool solution(string s)
{
    int pCnt=0, yCnt=0;
    for(char c : s)
    {
        c = tolower(c);
        if(c == 'p') pCnt++;
        else if(c == 'y') yCnt++;
    }

    return pCnt == yCnt;
}