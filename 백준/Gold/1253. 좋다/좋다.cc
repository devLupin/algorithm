#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int SZ = 2005;
int ans, n;
ll arr[SZ];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++)
        cin >> arr[i];

    sort(arr, arr+n);

    for(int i=0; i<n; i++) {
        int left=0, right = n-1;

        while(left < right) {
            if(left == i) {
                left++;
                continue;
            }
            else if(right == i) {
                right--;
                continue;
            }

            ll cmp = arr[left] + arr[right];
            
            if(cmp == arr[i]) {
                ans++;
                break;
            }
            else if(cmp < arr[i]) left++;
            else right--;
        }
    }

    cout << ans;
    return 0;
}