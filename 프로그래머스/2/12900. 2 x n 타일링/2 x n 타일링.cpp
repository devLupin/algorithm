#include <string>
#include <vector>

using namespace std;

int memo[60'005];
int MOD = 1'000'000'007;

int solution(int n) {
    memo[1] = 1;
    memo[2] = 2;
    
    for(int i=3; i<=n; i++)
        memo[i] = (memo[i-1] + memo[i-2]) % MOD;
    
    return memo[n];
}