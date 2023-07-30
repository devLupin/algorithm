#include <bits/stdc++.h>
using namespace std;

int n, A[10005];
long long ans;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++)
        cin >> A[i];
    
    sort(A, A+n);

    for(int i=0; i<n-2; i++) {
        for(int j=i+1; j<n-1; j++) {
            int cmp = A[i] + A[j];
            int l = lower_bound(A + j + 1, A + n, -cmp) - A;
            int u = upper_bound(A + j + 1, A + n, -cmp) - A;
            ans += u-l;
        }   
    }

    cout << ans;

    return 0;
}