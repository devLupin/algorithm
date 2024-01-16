#include <bits/stdc++.h>
#define MOD 1'000'000'007
using namespace std;


int solution(int n) {
    if(n % 2 != 0) return 0;
    
    long long DP[5001] = {0,};
    DP[0] = 1;
    DP[2] = 3;
    
    //F[N] = F[N - 2] * F[2] + F[N - 4] * 2 + F[N - 6] * 2 + ... + F[2] * 2 + 2
    for(int i=4; i<=n; i += 2) {
        DP[i] = DP[i-2] * 3;
        for(int j = i - 4; j >= 0; j -= 2)
            DP[i] += DP[j] * 2;
        DP[i] %= MOD;
    }
    
    return DP[n];
}