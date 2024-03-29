#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

const int INF = 0x3f3f3f3f;
const int SZ = 100'001;
vector<int> adj[SZ];

int bfs(int src, int dst) {
    queue<pii> q;
    bool vis[SZ] = {false,};
    
    q.push({src, 0});
    vis[src] = true;
    
    while(!q.empty()) {
        pii cur = q.front();
        q.pop();
        
        if(cur.first == dst) return cur.second;
        
        for(int nxt : adj[cur.first]) {
            if(!vis[nxt]) {
                q.push({nxt, cur.second + 1});
                vis[nxt] = true;
            }
        }
    }
    
    return -1;
}

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    
    for(auto nxt : roads) {
        adj[nxt[0]].push_back(nxt[1]);
        adj[nxt[1]].push_back(nxt[0]);
    }
    
    for(int src : sources) {
        if(src == destination) answer.push_back(0);
        else answer.push_back(bfs(src, destination));
    }
    
    return answer;
}