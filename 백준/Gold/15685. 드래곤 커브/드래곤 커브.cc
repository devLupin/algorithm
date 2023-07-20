#include <bits/stdc++.h>
using namespace std;

const int dy[] = {0,-1,0,1};
const int dx[] = {1,0,-1,0};
const int SZ = 105;
int n, x, y, d, g;
vector<int> dir;
bool board[SZ][SZ];

int count() {
    int ret = 0;

    for(int i=0; i<SZ; i++)
        for(int j=0; j<SZ; j++)
            ret += board[i][j] && board[i+1][j] && board[i][j+1] && board[i+1][j+1];

    return ret;
}

void make() {
    int sz = dir.size();
    for(int i = sz-1; i>=0; i--) {
        int nxt = (dir[i] + 1) % 4;
        y += dy[nxt];
        x += dx[nxt];

        board[y][x] = true;
        dir.push_back(nxt);
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    while(n--) {
        dir.clear();

        cin >> x >> y >> d >> g;
        board[y][x] = true;

        y += dy[d];
        x += dx[d];
        board[y][x] = true;

        dir.push_back(d);
        while(g--) make();
    }

    cout << count();
    return 0;
}