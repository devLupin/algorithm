#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int ans = 0, start = 1, idx = 0;
    
    while(start <= n) {
        int cur = stations[idx];
        
        if(start >= cur - w && start <= cur + w) {
            start = cur + w;
            idx++;
        }
        else {
            start += 2*w;
            ans++;
        }
        
        start++;
    }
    
    return ans;
}