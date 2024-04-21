#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<int> money) {
    int ans = 0;
    const int MOD = 1000000007;
    int DP[100001] = { 0, };
    DP[0] = 1;

    sort(money.begin(), money.end());

    for (int coin : money)
        for (int cur = coin; cur <= n; cur++)
            DP[cur] = (DP[cur] + DP[cur - coin]) % MOD;

    return DP[n];
}