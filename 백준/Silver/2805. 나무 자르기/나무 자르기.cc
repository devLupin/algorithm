#include <bits/stdc++.h>
using namespace std;

int n, m, arr[1000005], ans;

bool check(int len) {
    long long tmp = 0;

    for(int i=0; i<n; i++) {
        int a = arr[i] - len;
        tmp += (a > 0 ? a : 0);
    }

    return tmp >= m;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i=0; i<n; i++)
        cin >> arr[i];

    sort(arr, arr+n);

    int low = 1, high = arr[n-1];
    while(low <= high) {
        int mid = (low+high) / 2;

        if(check(mid)) {
            ans = mid;
            low = mid+1;
        }
        else high = mid-1;
    }

    cout << ans;

    return 0;
}