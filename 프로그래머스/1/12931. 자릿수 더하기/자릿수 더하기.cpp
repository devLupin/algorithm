#include <bits/stdc++.h>
using namespace std;

int solution(int n) 
{
    string s = to_string(n);
    int sum = 0;
    for(char c : s) sum += c - '0';
    return sum;
}