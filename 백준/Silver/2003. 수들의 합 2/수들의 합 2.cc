#include <bits/stdc++.h>
using namespace std;

int n, m, arr[10005];
long long ans;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i=0; i<n; i++)
        cin >> arr[i];

    int l=0, r=0, sum=0;
    while(r <= n) {
        if(sum < m) sum += arr[r++];
        else {
            if(sum == m) ans++;
            sum -= arr[l++];
        }
    }

    cout << ans;

    return 0;
}