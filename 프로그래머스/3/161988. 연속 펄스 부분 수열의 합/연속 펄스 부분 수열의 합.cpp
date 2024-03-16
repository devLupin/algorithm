#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL DP[500'005][2];   // 1, -1

LL solution(vector<int> sequence) {
    DP[0][0] = sequence[0];
    DP[0][1] = -sequence[0];
    
    LL answer = max(DP[0][0], DP[0][1]);
    
    for(int i=1; i<sequence.size(); i++) {
        LL cur = sequence[i];
        DP[i][0] = max(cur, DP[i-1][1] + cur);
        DP[i][1] = max(-cur, DP[i-1][0] - cur);
        answer = max({answer, DP[i][0], DP[i][1]});
    }
    
    return answer;
}