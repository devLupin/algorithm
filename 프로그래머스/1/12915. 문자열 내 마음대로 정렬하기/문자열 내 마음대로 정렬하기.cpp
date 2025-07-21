#include <bits/stdc++.h>
using namespace std;

int tg;

bool compare(const string& s1, const string& s2)
{
    if(s1[tg] != s2[tg]) return s1[tg] < s2[tg];
    return s1 < s2;
}

vector<string> solution(vector<string> strings, int n) 
{
    tg = n;
    sort(strings.begin(), strings.end(), compare);
    return strings;
}