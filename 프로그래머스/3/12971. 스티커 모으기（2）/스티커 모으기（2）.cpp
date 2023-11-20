#include <iostream>
#include <vector>
using namespace std;

int DP[100'005];

int solution(vector<int> sticker)
{
    if(sticker.size() == 1) return sticker[0];
    
    int ans = 0;
    int sz = sticker.size();
    DP[0] = DP[1] = sticker[0];
    
    for(int i=2; i<sz-1; i++)
        DP[i] = max(DP[i-1], DP[i-2] + sticker[i]);
    ans = max(DP[sz-2], ans);
    
    DP[0] = 0;
    DP[1] = sticker[1];
    for(int i=2; i<sz; i++)
        DP[i] = max(DP[i-1], DP[i-2] + sticker[i]);
    ans = max(DP[sz-1], ans);
    
    return ans;
}