#include <string>
#include <vector>
#include <queue>
#include <iostream>
#define FOR(i, n) for(int i=0; i<(n); i++)
#define ELIF else if

using namespace std;
using pii = pair<int, int>;

char map[50][50];
int n, m;

pii move(pii src, string dir) {
    char d = dir[0];
    int w = dir[2] - '0';

    int dy = 0;
    int dx = 0;

    if (d == 'N') dy = -1;
    ELIF(d == 'E') dx = 1;
    ELIF(d == 'W') dx = -1;
    else dy = 1;

    int ny = src.first;
    int nx = src.second;

    FOR(i, w) {
        ny += dy;
        nx += dx;

        if (ny < 0 || nx < 0 || ny >= n || nx >= m)
            return src;
        if (map[ny][nx] == 'X')
            return src;
    }

    return {ny, nx};
}

vector<int> solution(vector<string> park, vector<string> routes) {
    pii start;

    n = park.size();
    m = park[0].size();

    FOR(i, park.size())
        FOR(j, park[i].size()) {
            map[i][j] = park[i][j];
            if (map[i][j] == 'S')
                start = { i, j };
    }

    FOR(i, routes.size())
        start = move(start, routes[i]);

    return { start.first, start.second };
}