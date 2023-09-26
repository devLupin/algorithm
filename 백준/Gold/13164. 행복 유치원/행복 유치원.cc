#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    ull ans = 0;
    cin >> n >> k;
    vector<ull> v(n), d(n-1);

    cin >> v[0];
    for(int i=1; i<n; i++){
        cin >> v[i];
        d[i-1] = v[i] - v[i-1];
    }
    sort(d.begin(), d.end());

    for(int i=0; i<n-k; i++) ans += d[i];
    cout << ans;

    return 0;
}