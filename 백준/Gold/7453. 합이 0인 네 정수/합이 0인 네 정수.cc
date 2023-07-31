#include <bits/stdc++.h>
using namespace std;

int n, arr[4005][4];
long long ans;
vector<int> A, B;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++)
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2] >> arr[i][3];
    
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++) {
            A.push_back(arr[i][0] + arr[j][1]);
            B.push_back(arr[i][2] + arr[j][3]);
        }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    for(int i=0; i<A.size(); i++) {
        int upper = upper_bound(B.begin(), B.end(), -A[i]) - B.begin();
        int lower = lower_bound(B.begin(), B.end(), -A[i]) - B.begin();
        ans += upper-lower;
    }

    cout << ans;

    return 0;
}