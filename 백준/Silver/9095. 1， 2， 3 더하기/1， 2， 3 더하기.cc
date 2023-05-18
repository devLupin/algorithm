#include <bits/stdc++.h>
using namespace std;

int memo[11];

void DP(void) {
    memo[1] = 1;
    memo[2] = 2;
    memo[3] = 4;

    for (int i = 4; i <= 10; i++)
        memo[i] = memo[i - 1] + memo[i - 2] + memo[i - 3];
}

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    DP();
    int TC; cin >> TC;
    while (TC--) {
        int n; cin >> n;
        cout << memo[n] << '\n';
    }

    return 0;
}