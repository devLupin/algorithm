#include <bits/stdc++.h>
using namespace std;

vector<int> solution(long long n) {
    string s = to_string(n);
    vector<int> v;
    for(int i=s.size()-1; i>=0; i--) v.push_back(s[i] - '0');
    return v;
}