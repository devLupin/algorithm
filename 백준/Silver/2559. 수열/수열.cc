#include <bits/stdc++.h>
using namespace std;

int n, k, arr[100001], ans;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int l=0, r=0, sum=0;

    cin >> n >> k;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
        if(i<k) sum += arr[i];
    }

    r = k, ans = sum;
    while(r < n) {
        sum -= arr[l++];
        sum += arr[r++];
        ans = max(ans, sum);
    }

    cout << ans;
    return 0;
}