#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m;
ll arr[1000005], cnt[1005], ans;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        cin >> arr[i];
        arr[i] += arr[i-1];
        cnt[arr[i]%m]++;
    }

    ans = cnt[0];
    for(int i=0; i<m; i++)
        ans += cnt[i] * (cnt[i] - 1) / 2;

    cout << ans;

    return 0;
}