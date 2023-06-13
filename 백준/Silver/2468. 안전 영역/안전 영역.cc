#include <bits/stdc++.h>
#define Y first
#define X second

using namespace std;
using pii = pair<int,int>;

const int SZ = 100;
const int dy[] = {-1,1,0,0};
const int dx[] = {0,0,-1,1};
int n, board[SZ][SZ];
bool visited[SZ][SZ];
int upper = 0;

void bfs(pii src, int limit) {
    queue<pii> q;
    q.push(src);
    visited[src.Y][src.X] = true;

    while(!q.empty()) {
        pii cur = q.front();
        q.pop();

        for(int dir=0; dir<4; dir++) {
            int ny = cur.Y + dy[dir];
            int nx = cur.X + dx[dir];

            if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
            if(visited[ny][nx] || board[ny][nx] <= limit) continue;

            q.push({ny, nx});
            visited[ny][nx] = true;
        }
    }
}

int solve(int limit) {
    int ret = 0;
    fill_n(&visited[0][0], SZ*SZ, false);

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(board[i][j] > limit && !visited[i][j]) {
                bfs({i, j}, limit);
                ret++;
            }
        }
    }

    return ret;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int ans = 0;

    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> board[i][j];
            upper = max(upper, board[i][j]);
        }
    }

    for(int limit=0; limit<=upper; limit++)
        ans = max(solve(limit), ans);

    cout << ans;
    return 0;
}