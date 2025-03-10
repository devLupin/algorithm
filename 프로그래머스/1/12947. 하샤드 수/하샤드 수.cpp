#include <bits/stdc++.h>
using namespace std;

bool solution(int x) 
{
    string s = to_string(x);
    int i = 0;
    for(char c : s) i += (c - '0');
    return x % i == 0;
}