#include <bits/stdc++.h>
using namespace std;

const int SZ = 4000005;
int n, arr[SZ], ans;
bool vis[SZ];

int eratos() {
    for(int i=2; i<=sqrt(n); i++) {
        if(vis[i]) continue;
        for(int j=i*i; j<=n; j+=i) {
            vis[j] = true;
        }
    }

    int idx = 0;
    for(int i=2; i<=n; i++)
        if(!vis[i]) arr[idx++] = i;
    
    return idx;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    int sz = eratos();

    int l=0, r=0, sum=0;
    while(r <= sz) {
        if(sum < n) sum += arr[r++];
        else {
            if(sum == n) ans++;
            sum -= arr[l++];
        }
    }

    cout << ans;

    return 0;
}