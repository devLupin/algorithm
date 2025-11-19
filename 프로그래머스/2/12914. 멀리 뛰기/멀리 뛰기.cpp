#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL solution(int n) 
{
    if (n <= 3) return n;
    LL ans;
    int n1 = 2, n2 = 3;
    
    for(int i=4; i<=n; i++)
    {
        ans = (n1 + n2) % 1234567;
        n1 = n2;
        n2 = ans;
    }
    
    return ans;
}