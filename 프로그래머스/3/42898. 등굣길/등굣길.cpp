#include <bits/stdc++.h>
using namespace std;

int memo[101][101];

int solution(int m, int n, vector<vector<int>> puddles) {
    memo[1][1] = 1;
    
    for (int i = 0; i < puddles.size(); i++)
        memo[puddles[i][1]][puddles[i][0]] = -1;
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(memo[i][j] == -1) continue;
            
            int a = max(0, memo[i-1][j]);
            int b = max(0, memo[i][j-1]);
            memo[i][j] += (a+b) % 1000000007;
        }
    }
    
    return memo[n][m];
}