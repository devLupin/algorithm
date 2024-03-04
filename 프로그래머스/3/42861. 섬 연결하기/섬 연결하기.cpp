#include <bits/stdc++.h>
using namespace std;

vector<int> parent;

int findParent(int v) {
    if(parent[v] == -1) return v;
    return parent[v] = findParent(parent[v]);
}

bool compare(vector<int>& a, vector<int>& b) {return a[2] < b[2];}

int solution(int n, vector<vector<int>> costs) {
    int ans = 0;
    
    parent.assign(n, -1);
    sort(costs.begin(), costs.end(), compare);
    
    for(auto& nxt : costs) {
        int from = findParent(nxt[0]);
        int to = findParent(nxt[1]);
        int d = nxt[2];
        
        if(from != to) {
            ans += d;
            parent[to] = from;
        }
    }
    
    return ans;
}