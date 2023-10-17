#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> A;
int N, K, ans;
bool vis[10] = {false,};

void dfs(int cnt, int remain) {
    ans = max(cnt, ans);
    
    for(int i=0; i<N; i++) {
        if(!vis[i]) {
            int min = A[i][0], used = A[i][1];
            if(remain >= min) {
                vis[i] = true;
                dfs(cnt+1, remain - used);
                vis[i] = false;
            }
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    N = dungeons.size();
    K = k;
    for(auto nxt : dungeons) A.push_back(nxt);
    
    dfs(0, K);
    
    return ans;
}