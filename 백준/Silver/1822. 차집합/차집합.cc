#include <bits/stdc++.h>
using namespace std;

const int SZ = 500005;
int a, b, A[SZ], B[SZ];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b;
    for(int i=0; i<a; i++) cin >> A[i];
    for(int i=0; i<b; i++) cin >> B[i];

    sort(A, A+a);
    sort(B, B+b);

    vector<int> ans;
    int idx1=0, idx2=0;
    while(idx1 < a && idx2 < b) {
        if(A[idx1] == B[idx2]) idx1++, idx2++;
        else {
            if(A[idx1] < B[idx2]) ans.push_back(A[idx1++]);
            else idx2++;
        }
    }

    if(idx1 < a)
        while(idx1 < a) 
            ans.push_back(A[idx1++]);

    cout << ans.size() << '\n';
    for(int a : ans) cout << a << ' ';

    return 0;
}