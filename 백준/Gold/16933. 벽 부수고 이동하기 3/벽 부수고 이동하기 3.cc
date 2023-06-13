#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
const int SZ = 1000;

int n, m, k;
char board[SZ][SZ];
bool visited[SZ][SZ][11][2];

typedef struct
{
    int y, x, w, k, state;
} Pos;

int bfs()
{
    queue<Pos> q;
    q.push({0, 0, 1, 0, 1});
    visited[0][0][0][1] = true; // 낮을 1으로

    while (!q.empty())
    {
        Pos cur = q.front();
        q.pop();

        if (cur.y == n - 1 && cur.x == m - 1)
            return cur.w;

        for (int dir = 0; dir < 4; dir++)
        {
            int ny = cur.y + dy[dir];
            int nx = cur.x + dx[dir];
            int nw = cur.w + 1;
            int n_state = !cur.state;

            if (ny < 0 || nx < 0 || ny >= n || nx >= m)
                continue;

            if (!visited[ny][nx][cur.k][n_state] && board[ny][nx] == '0')
            {
                q.push({ny, nx, nw, cur.k, n_state});
                visited[ny][nx][cur.k][n_state] = true;
            }

            if (board[ny][nx] == '1' && cur.state && cur.k < k)
            {
                if (!visited[ny][nx][cur.k + 1][n_state])
                {
                    q.push({ny, nx, nw, cur.k + 1, n_state});
                    visited[ny][nx][cur.k + 1][n_state] = true;
                }
            }
        }

        if (!visited[cur.y][cur.x][cur.k][!cur.state])
        {
            q.push({cur.y, cur.x, cur.w + 1, cur.k, !cur.state});
            visited[cur.y][cur.x][cur.k][!cur.state] = true;
        }
    }

    return -1;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];

    cout << bfs();
    return 0;
}