#include <string>
#include <vector>
#include <queue>
#include <cstring>
#include <iostream>

using namespace std;
using pii = pair<int, int>;

typedef struct {
    int y, x, dist;
}pos;

const int dy[] = { -1,1,0,0 };
const int dx[] = { 0,0,-1,1 };

char map[100][100];
bool visited[100][100];

int bfs(pii src, pii dest, int y_len, int x_len) {
    memset(visited, false, sizeof(visited));

    queue<pos> q;
    q.push({ src.first, src.second, 0 });
    visited[src.first][src.second] = true;

    while (!q.empty()) {
        pos cur = q.front();
        q.pop();

        if (cur.y == dest.first && cur.x == dest.second)
            return cur.dist;

        for (int dir = 0; dir < 4; dir++) {
            int ny = cur.y + dy[dir];
            int nx = cur.x + dx[dir];

            if (ny < 0 || nx < 0 || ny >= y_len || nx >= x_len)
                continue;
            if (visited[ny][nx] || map[ny][nx] == 'X')
                continue;

            q.push({ ny, nx, cur.dist + 1 });
            visited[ny][nx] = true;
        }
    }

    return -1;
}

int solution(vector<string> maps) {
    pii s, e, l;

    int y_len = maps.size();
    int x_len = maps[0].size();

    for (int y = 0; y < y_len; y++) {
        for (int x = 0; x < x_len; x++) {
            map[y][x] = maps[y][x];

            if (map[y][x] == 'S')
                s = { y, x };
            if (map[y][x] == 'E')
                e = { y, x };
            if (map[y][x] == 'L')
                l = { y,x };
        }
    }

    int a = bfs(s, l, y_len, x_len);
    int b = bfs(l, e, y_len, x_len);

    return (a<0 || b <0) ? -1 : a+b;
}