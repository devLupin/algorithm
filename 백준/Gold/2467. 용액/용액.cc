#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll arr[100005];
ll a = 1000000005, b = 1000000005;
int n;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i=0; i<n; i++)
        cin >> arr[i];

    int left = 0, right = n-1;
    while(left < right) {
        ll cmp = arr[left] + arr[right];
        
        if(abs(a + b) > abs(cmp)) {
            a = arr[left];
            b = arr[right];
        }

        if(cmp > 0) right--;
        else left++;
    }
    
    cout << a << ' ' << b;
    return 0;
}