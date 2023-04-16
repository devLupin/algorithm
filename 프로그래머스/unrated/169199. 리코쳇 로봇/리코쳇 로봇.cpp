#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
using pii = pair<int, int>;

const int dy[] = { -1,1,0,0 };
const int dx[] = { 0,0,-1,1 };

typedef struct {
    int y, x, w;
}pos;

bool visited[100][100];

int solution(vector<string> board) {
    pii src, dest;
    int y_len = board.size();
    int x_len = board[0].size();

    for (int y = 0; y < y_len; y++) {
        for (int x = 0; x < x_len; x++) {
            if (board[y][x] == 'R')
                src = { y, x };
            if (board[y][x] == 'G')
                dest = { y, x };
            visited[y][x] = false;
        }
    }

    queue<pos> q;
    q.push({ src.first, src.second, 0 });

    while (!q.empty()) {
        pos cur = q.front();
        q.pop();

        if (board[cur.y][cur.x] == 'G')
            return cur.w;

        for (int dir = 0; dir < 4; dir++) {
            int ny = cur.y + dy[dir];
            int nx = cur.x + dx[dir];
            bool chk = false;

            while (ny < y_len && nx < x_len && ny >= 0 && nx >= 0 && board[ny][nx] != 'D') {
                ny += dy[dir];
                nx += dx[dir];
                chk = true;
            }

            if (chk) {
                ny -= dy[dir];
                nx -= dx[dir];
                
                if (!visited[ny][nx]) {
                    q.push({ ny, nx, cur.w + 1 });
                    visited[ny][nx] = true;
                }
            }
        }
    }
    return -1;
}