#include <bits/stdc++.h>
using namespace std;

string solution(string s) 
{
    string answer = "";
    
    for(int i = s.size() - 1; i > 0; i--)
    {
        if (s[i - 1] == ' ' && s[i] >= 'a' && s[i] <= 'z')
            answer += char(s[i] - 'a' + 'A');
        else if (s[i - 1] != ' ' && s[i] >= 'A' && s[i] <= 'Z')
            answer += char(s[i] - 'A' + 'a');
        else
            answer += s[i];
    }
    
    if(s[0] >= 'a' && s[0] <= 'z')
        answer += char(s[0] - 'a' + 'A');
    else
        answer += s[0];
    
    reverse(answer.begin(), answer.end());
    return answer;
}