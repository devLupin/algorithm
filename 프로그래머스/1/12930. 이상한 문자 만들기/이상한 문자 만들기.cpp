#include <bits/stdc++.h>
using namespace std;

char ToUpper(char c)
{
    if(c >= 'a' && c <= 'z') c = c - 'a' + 'A';
    return c;
}

char ToLower(char c)
{
    if(c >= 'A' && c <= 'Z') c = c - 'A' + 'a';
    return c;
}

string solution(string s) 
{
    string answer = "";
    int i = 0;
    
    for(char c : s)
    {
        if(c == ' ') 
        {
            i = 0;
            answer += ' ';
        }
        else
            answer += (i++ % 2 == 0) ? ToUpper(c) : ToLower(c);
    }
    
    return answer;
}