#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1000000005;
ll n, arr[5005];
vector<ll> ans;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ans = {INF, INF, INF};

    cin >> n;
    for(int i=0; i<n; i++)
        cin >> arr[i];

    sort(arr, arr+n);

    for(int i=0; i<n-2; i++) {
        int left=i+1, right=n-1;
        while(left < right) {
            ll cmp = arr[i] + arr[left] + arr[right];
            if(abs(ans[0]+ans[1]+ans[2]) > abs(cmp))
                ans = {arr[i], arr[left], arr[right]};
        
            (cmp < 0) ? left++ : right--;
        }
    }

    for(ll a : ans) cout << a << ' ';

    return 0;
}