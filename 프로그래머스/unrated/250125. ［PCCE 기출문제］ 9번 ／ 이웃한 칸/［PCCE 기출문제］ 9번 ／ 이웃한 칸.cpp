#include <bits/stdc++.h>
using namespace std;

const int dx[] = {-1,1,0,0};
const int dy[] = {0,0,-1,1};

int solution(vector<vector<string>> board, int h, int w) {
    int ans = 0;
    
    for(int dir=0; dir<4; dir++) {
        int ny = h + dy[dir];
        int nx = w + dx[dir];
        
        if(ny < 0 || nx < 0 || ny >= board.size() || nx >= board.size()) continue;
        if(board[h][w] == board[ny][nx]) ans++;
    }
    
    return ans;
}