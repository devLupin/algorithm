#include <bits/stdc++.h>
using namespace std;

const int SZ = 100005;
int n, arr[SZ];
bool vis[SZ];
long long ans;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++)
        cin >> arr[i];
    
    int l=0, r=0;
    while(l < n) {
        while(r < n) {
            if(vis[arr[r]]) break;
            vis[arr[r++]] = true;
        }

        ans += (r-l);
        vis[arr[l++]] = false;
    }

    cout << ans;

    return 0;
}