#include <bits/stdc++.h>
using namespace std;

string solution(string s) 
{
    sort(s.begin(), s.end(), greater<>());
    return s;
}