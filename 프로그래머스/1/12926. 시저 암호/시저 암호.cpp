#include <bits/stdc++.h>
using namespace std;

string solution(string s, int n)
{
    const int SZ = 26;
    char lowerCase[SZ], upperCase[SZ];
    for (int i = 0; i < SZ; i++)
    {
        lowerCase[i] = 'a' + i;
        upperCase[i] = 'A' + i;
    }

    string ans = "";
    for (char c : s)
    {
        if (c >= 'a' && c <= 'z')
            ans += lowerCase[(c + n - 'a') % SZ];
        else if (c == ' ')
            ans += ' ';
        else
            ans += upperCase[(c + n - 'A') % SZ];
    }

    return ans;
}