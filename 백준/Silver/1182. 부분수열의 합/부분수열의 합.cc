#include <bits/stdc++.h>
using namespace std;

int n, s, ans = 0;
vector<int> v;

void dfs(int idx, int tmp) 
{
    if (idx == n) return;
    if (tmp + v[idx] == s) ans++;

    dfs(idx + 1, tmp);
    dfs(idx + 1, tmp + v[idx]);
}

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> s;
    v.assign(n, 0);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    
    dfs(0, 0);

    cout << ans;

    return 0;
}