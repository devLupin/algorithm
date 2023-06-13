#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

vector<pair<int, int>> avail[101][101];
bool visited[101][101];
bool on[101][101];
int cnt = 0;
int n, m;
void bfs()
{
    queue<pair<int, int>> Q;
    Q.push({1, 1});
    visited[1][1] = true;
    on[1][1] = true;
    cnt++;
    for (auto room : avail[1][1])
    {
        if (!on[room.X][room.Y])
        {
            on[room.X][room.Y] = true;
            cnt++;
        }
    }
    while (!Q.empty())
    {
        auto cur = Q.front();
        Q.pop();
        for (auto &room : avail[cur.X][cur.Y])
        {
            if (!on[room.X][room.Y])
            { 
                on[room.X][room.Y] = true;
                cnt++;
                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = room.X + dx[dir];
                    int ny = room.Y + dy[dir];
                    if (nx < 1 || ny < 1 || nx > n || ny > n)
                        continue;
                    if (visited[nx][ny])
                    { 
                        Q.push({room.X, room.Y});
                        visited[room.X][room.Y] = true;
                        break;
                    }
                }
            }
        }
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 1 || ny < 1 || nx > n || ny > n)
                continue;
            if (!on[nx][ny] || visited[nx][ny])
                continue;
            Q.push({nx, ny});
            visited[nx][ny] = true;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        avail[x][y].push_back({a, b});
    }
    bfs();
    cout << cnt;

    return 0;
}