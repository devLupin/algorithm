#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MX = 1000000005;
int n, arr[100005];
ll a=MX, b=MX;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++)
        cin >> arr[i];
    sort(arr, arr+n);

    int left=0, right=n-1;

    while(left < right) {
        ll sum = arr[left] + arr[right];

        if(abs(a+b) > abs(sum)) {
            a = arr[left];
            b = arr[right];
        }

        if(sum <= 0) left++;
        else right--;
    }

    cout << a << ' ' << b;

    return 0;
}