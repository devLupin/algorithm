#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

const int dy[] = {0, 0, -1, 1};
const int dx[] = {1, -1, 0, 0};
int n, m, sx, sy, k, board[25][25], cmd;
vector<int> dice(7, 0);

void move(int dir) {
    vector<int> cpy;
    cpy.assign(dice.begin(), dice.end());
    
    if(dir==0) {
        dice[1] = cpy[4];
        dice[3] = cpy[1];
        dice[4] = cpy[6];
        dice[6] = cpy[3];
    }

    else if(dir==1) {
        dice[1] = cpy[3];
        dice[3] = cpy[6];
        dice[4] = cpy[1];
        dice[6] = cpy[4];
    }

    else if(dir==2) {
        dice[1] = cpy[5];
        dice[2] = cpy[1];
        dice[5] = cpy[6];
        dice[6] = cpy[2];
    }

    else {
        dice[1] = cpy[2];
        dice[2] = cpy[6];
        dice[5] = cpy[1];
        dice[6] = cpy[5];
    }
}

bool oom(int y, int x) { return y < 0 || x < 0 || y >= n || x >= m; }

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> sy >> sx >> k;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        cin >> board[i][j];

    for(int i=0; i<k; i++) {
        cin >> cmd;
        cmd--;

        int ny = sy+dy[cmd];
        int nx = sx+dx[cmd];

        if(oom(ny, nx)) continue;

        move(cmd);
        if(board[ny][nx] == 0)
            board[ny][nx] = dice[6];
        else {
            dice[6] = board[ny][nx];
            board[ny][nx] = 0;
        }

        cout << dice[1] << '\n';
        tie(sy, sx) = {ny, nx};
    }

    return 0;
}