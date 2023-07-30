#include <bits/stdc++.h>
using namespace std;

const int INF = 100000005;
int a=INF, b=INF, n, arr[100005];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++)
        cin >> arr[i];

    sort(arr, arr+n);

    int left=0, right=n-1;
    while(left < right) {
        int cmp = arr[left] + arr[right];

        if(abs(a+b) > abs(cmp)) {
            a = arr[left];
            b = arr[right];
        }

        if(cmp > 0) right--;
        else left++;
    }

    cout << a+b;

    return 0;
}