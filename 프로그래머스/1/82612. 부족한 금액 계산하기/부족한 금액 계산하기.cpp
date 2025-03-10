#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL solution(int price, int money, int count)
{
    LL cmp = 0;
    for(int i=1; i<=count; i++)
        cmp += 1LL * price * i;
    
    return (cmp - money * 1LL > 0) ? cmp - money * 1LL : 0;
}