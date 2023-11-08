#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> A, vector<int> B) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int idx = 0, ans = 0;
    
    for(int i=0; i<A.size(); i++)
        if (B[i] > A[idx]) {
            ans++;
            idx++;
        }
    
    return ans;
}