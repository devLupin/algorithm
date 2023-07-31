#include <bits/stdc++.h>
using namespace std;

int n, k, arr[1000005];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for(int i=0; i<n; i++)
        cin >> arr[i];

    int left=0, right=0, tmp=0, ans=0;
    while(left <= right && right < n) {
        int cur = arr[right];

        if(cur % 2 != 0) {
            if(tmp < k) tmp++;
            else {
                if(arr[left++] % 2 != 0) tmp--;
                right--;
            }
        }
        else ans = max(ans, right-left+1-tmp);
        right++;
    }

    cout << ans;

    return 0;
}