#include <bits/stdc++.h>
using namespace std;

int m, n, arr[1000005], ans;

bool check(int sz) {
    int tmp = 0;

    for(int i=0; i<n; i++)
        tmp += arr[i] / sz;

    if(tmp >= m) return true;
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m >> n;
    for(int i=0; i<n; i++)
        cin >> arr[i];

    sort(arr, arr+n);

    int left = 1, right = arr[n-1];
    while(left <= right) {
        int mid = (left+right) / 2;

        if(check(mid)) {
            ans = mid;
            left = mid+1;
        }
        else right = mid-1;
    }

    cout << ans;

    return 0;
}