#include <bits/stdc++.h>
using namespace std;

string solution(string s) 
{
    vector<int> v;
    string n = "";
    s += " ";
    for(const char& c : s)
    {
        if(c == '-') n += '-';
        else if(c == ' ') 
        {
            v.push_back(stoi(n));
            n = "";
        }
        else n += c;
    }
    sort(v.begin(), v.end());
    return to_string(v[0]) + " " + to_string(v[v.size()-1]);
}