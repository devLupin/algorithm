#include <bits/stdc++.h>
using namespace std;

int solution(int n) 
{
    int div = 2, ans = (n > 0) ? 1 : 0;
    while(n >= div)
    {
        if (n % div == 0)
            ans += div;
        div++;
    }
    return ans;
}