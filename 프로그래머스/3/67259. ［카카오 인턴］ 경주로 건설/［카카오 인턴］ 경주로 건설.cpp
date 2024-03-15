#include <bits/stdc++.h>
using namespace std;

const int SZ = 30, INF = 0x3f3f3f3f;
const int dx[] = {-1,1,0,0};
const int dy[] = {0,0,-1,1};

int N, vis[SZ][SZ][4];

int bfs(vector<vector<int>> board) {
    queue<tuple<int,int,int,int>> q;
    
    if(board[0][1] == 0) {
        q.push({0,1,100,3});
        vis[0][1][3] = 100;
    }
    if(board[1][0] == 0) {
        q.push({1,0,100,1});
        vis[1][0][1] = 100;
    }
    
    for(int dir=0; dir<4; dir++) vis[0][0][dir] = 0;
    
    while(!q.empty()) {
        auto [x, y, c, d] = q.front();
        q.pop();
        
        for(int dir=0; dir<4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            int nc = c + 100;
            
            if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if(board[nx][ny] == 0) {
                if(dx[d] != 0 && dy[dir] != 0) nc += 500;
                else if(dy[d] != 0 && dx[dir] != 0) nc += 500;
                
                if(nc < vis[nx][ny][dir]) {
                    vis[nx][ny][dir] = nc;
                    q.push({nx, ny, nc, dir});
                }
            }
        }
    }
    
    return *min_element(vis[N-1][N-1], vis[N-1][N-1] + 4);
}

int solution(vector<vector<int>> board) {
    N = board.size();
    fill(&vis[0][0][0], &vis[N][N][4], INF);
    return bfs(board);
}