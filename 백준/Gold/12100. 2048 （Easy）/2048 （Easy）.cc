#include <bits/stdc++.h>
#define Y first
#define X second
using namespace std;
using ll = long long;

const int SZ = 20, MAX_CNT = 5;
const int dy[] = {-1,1,0,0};
const int dx[] = {0,0,-1,1};
int n;
ll ans;

void print(vector<vector<ll>> board) {
    cout << '\n';
    for(int i=0; i<n; i++) {        
        for(int j=0; j<n; j++)
            cout << board[i][j] << ' ';
        cout << '\n';
    }
}

vector<vector<ll>> merge(int dir, vector<vector<ll>> board) {
    if(dir == 0) {
        for(int i=0; i<n-1; i++) {
            for(int j=0; j<n; j++) {
                if(board[i][j] == 0) continue;
                if(board[i][j] == board[i+1][j]) {
                    board[i][j] += board[i+1][j];
                    board[i+1][j] = 0;
                }
            }
        }
    }
    else if(dir == 1) {
        for(int i=n-1; i>=1; i--) {
            for(int j=0; j<n; j++) {
                if(board[i][j] == 0) continue;
                if(board[i][j] == board[i-1][j]) {
                    board[i][j] += board[i-1][j];
                    board[i-1][j] = 0;
                }
            }
        }
    }
    else if(dir == 2) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n-1; j++) {
                if(board[i][j] == 0) continue;
                if(board[i][j] == board[i][j+1]) {
                    board[i][j] += board[i][j+1];
                    board[i][j+1] = 0;
                }
            }
        }
    }
    else {
        for(int i=0; i<n; i++) {
            for(int j=n-1; j>=1; j--) {
                if(board[i][j] == 0) continue;
                if(board[i][j] == board[i][j-1]) {
                    board[i][j] += board[i][j-1];
                    board[i][j-1] = 0;
                }
            }
        }
    }

    return board;
}

vector<vector<ll>> move(int dir, vector<vector<ll>> board) {
    if(dir == 0) {
        for(int i=1; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(board[i][j] != 0) {
                    int y = i;
                    int x = j;

                    while(y+dy[dir] >= 0 && x+dx[dir] >= 0 && y+dy[dir] < n && x+dx[dir] < n && board[y+dy[dir]][x+dx[dir]] == 0) {
                        swap(board[y][x], board[y+dy[dir]][x+dx[dir]]);
                        y += dy[dir];
                        x += dx[dir];
                    }
                }
            }
        }
    }
    else if(dir == 1) {
        for(int i=n-2; i>=0; i--) {
            for(int j=0; j<n; j++) {
                if(board[i][j] != 0) {
                    int y = i;
                    int x = j;

                    while(y+dy[dir] >= 0 && x+dx[dir] >= 0 && y+dy[dir] < n && x+dx[dir] < n && board[y+dy[dir]][x+dx[dir]] == 0) {
                        swap(board[y][x], board[y+dy[dir]][x+dx[dir]]);
                        y += dy[dir];
                        x += dx[dir];
                    }
                }
            }
        }
    }
    else if(dir == 2) {
        for(int i=0; i<n; i++) {
            for(int j=1; j<n; j++) {
                if(board[i][j] != 0) {
                    int y = i;
                    int x = j;

                    while(y+dy[dir] >= 0 && x+dx[dir] >= 0 && y+dy[dir] < n && x+dx[dir] < n && board[y+dy[dir]][x+dx[dir]] == 0) {
                        swap(board[y][x], board[y+dy[dir]][x+dx[dir]]);
                        y += dy[dir];
                        x += dx[dir];
                    }
                }
            }
        }
    }
    else {
        for(int i=0; i<n; i++) {
            for(int j=n-2; j>=0; j--) {
                if(board[i][j] != 0) {
                    int y = i;
                    int x = j;

                    while(y+dy[dir] >= 0 && x+dx[dir] >= 0 && y+dy[dir] < n && x+dx[dir] < n && board[y+dy[dir]][x+dx[dir]] == 0) {
                        swap(board[y][x], board[y+dy[dir]][x+dx[dir]]);
                        y += dy[dir];
                        x += dx[dir];
                    }
                }
            }
        }
    }

    return board;
}

void dfs(int cnt, vector<vector<ll>> board) {
    for(int i=0; i<n; i++)
        ans = max(ans, *max_element(board[i].begin(), board[i].end()));

    if(cnt == MAX_CNT) {
        return;
    }

    for(int dir=0; dir<4; dir++) {
        auto origin = board;

        auto tmp = move(dir, board);
        tmp = merge(dir, tmp);
        tmp = move(dir, tmp);
        dfs(cnt+1, tmp);

        board = origin;
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    vector<vector<ll>> board(n, vector<ll>(n));
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> board[i][j];

    dfs(0, board);
    cout << ans;
    return 0;
}