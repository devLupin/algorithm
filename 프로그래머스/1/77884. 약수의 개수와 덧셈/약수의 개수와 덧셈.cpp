#include <bits/stdc++.h>
using namespace std;

int LCD(int n)
{
    int ret = 0;
    for(int div = 1; div <= n; div++)
        ret += (n % div == 0);
    return ret;
}

int solution(int left, int right) 
{
    int ans = 0;
    for(int i=left; i<=right; i++)
    {
        int lcd = LCD(i);
        ans += (lcd % 2 == 0) ? i : -i;   
    }
    return ans;
}