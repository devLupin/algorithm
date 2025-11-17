#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> arr)
{
    int n = 0;
    bool run = true;
    while (run)
    {
        n++;
        for (int nxt : arr)
            if (n % nxt != 0)
            {
                run = false;
                break;
            }
        if (!run) run = true;
        else return n;
    }
}