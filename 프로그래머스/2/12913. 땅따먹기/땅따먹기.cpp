#include <bits/stdc++.h>
using namespace std;

int DP[100'005][4];

int solution(vector<vector<int> > land)
{
    int N = land.size();
    
    for(int i=0; i<4; i++) DP[0][i] = land[0][i];
    
    for(int i=1; i<N; i++) {
        DP[i][0] = max({DP[i-1][1], DP[i-1][2], DP[i-1][3]}) + land[i][0];
        DP[i][1] = max({DP[i-1][0], DP[i-1][2], DP[i-1][3]}) + land[i][1];
        DP[i][2] = max({DP[i-1][0], DP[i-1][1], DP[i-1][3]}) + land[i][2];
        DP[i][3] = max({DP[i-1][0], DP[i-1][1], DP[i-1][2]}) + land[i][3];
    }
    
    return max({DP[N-1][0], DP[N-1][1], DP[N-1][2], DP[N-1][3]});
}