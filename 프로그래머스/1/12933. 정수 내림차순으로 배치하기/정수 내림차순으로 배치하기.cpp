#include <bits/stdc++.h>
using namespace std;

long long solution(long long n) 
{
    string s = to_string(n);
    vector<int> v;
    for(char c : s) v.push_back(c - '0');
    sort(v.begin(), v.end(), greater<>());
    s = "";
    for(int x : v) s += to_string(x);
    return stoll(s);
}