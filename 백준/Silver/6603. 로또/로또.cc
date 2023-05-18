#include <bits/stdc++.h>
using namespace std;

int n, lotto[14], ans[6];

void dfs(int start, int depth) {
    if (depth == 6) {
        for (int i = 0; i < 6; i++)
            cout << ans[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = start; i < n; i++) {
        ans[depth] = lotto[i];
        dfs(i + 1, depth + 1);
    }
}

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin >> n && n) {
        for (int i = 0; i < n; i++)
            cin >> lotto[i];

        dfs(0, 0);
        cout << '\n';
    }
    
    return 0;
}