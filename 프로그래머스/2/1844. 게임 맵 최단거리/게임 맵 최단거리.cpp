#include<bits/stdc++.h>
using namespace std;

struct pos {
    int y, x, d;
};

int N, M;
bool vis[102][102];

const int dy[] = {-1,1,0,0};
const int dx[] = {0,0,-1,1};

int bfs(vector<vector<int>> maps) {
    queue<pos> q;
    q.push({0,0,1});
    vis[0][0] = true;
    
    while(!q.empty()) {
        pos cur = q.front();
        q.pop();
        
        if(cur.y == N-1 && cur.x == M-1) return cur.d;
        
        for(int dir=0; dir<4; dir++) {
            int ny = cur.y + dy[dir];
            int nx = cur.x + dx[dir];
            
            if(ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
            if(vis[ny][nx] || maps[ny][nx] == 0) continue;
            
            q.push({ny,nx,cur.d+1});
            vis[ny][nx] = true;
        }
    }
    return -1;
}

int solution(vector<vector<int>> maps)
{
    N = maps.size();
    M = maps[0].size();
    
    return bfs(maps);
}