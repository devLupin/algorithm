#include <bits/stdc++.h>
using namespace std;

struct pos {int x, y, d;};

const int dx[] = {-1,1,0,0};
const int dy[] = {0,0,-1,1};

vector<string> board;

bool bfs(int x, int y) {
    bool vis[5][5] = {false,};
    queue<pos> q;
    q.push({x, y, 0});
    vis[x][y] = true;
    
    while(!q.empty()) {
        pos cur = q.front();
        q.pop();
        
        if(cur.d == 2) continue;
        
        for(int dir=0; dir<4; dir++) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            
            if(nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;
            
            if(!vis[nx][ny]) {
                if(board[nx][ny] == 'O') {
                    q.push({nx, ny, cur.d + 1});
                    vis[nx][ny] = true;
                }
                else if(board[nx][ny] == 'P') return false;
            }
        }
    }
    
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for(auto& cur : places) { 
        board.assign(cur.begin(), cur.end());
        bool flag = true;
        
        for(int i=0; i<5 && flag; i++) {
            for(int j=0; j<5; j++) {
                if(board[i][j] == 'P') {
                    if(!bfs(i, j)) {
                        flag = false;
                        break;
                    }
                }
            }
        }
        
        if(flag) answer.push_back(1);
        else answer.push_back(0);
    }
    
    return answer;
}