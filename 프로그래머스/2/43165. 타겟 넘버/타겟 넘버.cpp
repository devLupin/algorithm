#include <bits/stdc++.h>
using namespace std;

vector<int> A;
int T, ans;

void dfs(int s, int sum) {
    if(s == A.size()) {
        if(sum == T) ans++;
        return;
    }
    
    dfs(s+1, sum+A[s]);
    dfs(s+1, sum-A[s]);
}

int solution(vector<int> numbers, int target) {
    A.assign(numbers.begin(), numbers.end());
    T = target;
    
    dfs(0, 0);
    
    return ans;
}