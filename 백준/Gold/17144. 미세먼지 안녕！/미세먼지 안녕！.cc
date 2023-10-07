#include <bits/stdc++.h>
using namespace std;

const int dy[] = { -1,1,0,0 };
const int dx[] = { 0,0,-1,1 };

const int ddy[] = { 0,-1,0,1,0,1,0,-1 };
const int ddx[] = { 1,0,-1,0,1,0,-1,0 };

const int SZ = 1000;
int R, C, T, ans;
int A[SZ][SZ], B[SZ][SZ];
vector<pair<int, int>> pos;

bool oom(int y, int x) { return y < 0 || x < 0 || y >= R || x >= C; }

void spread() {
    for (int i = 0; i < R; i++)
        memset(B[i], 0, sizeof(B[i]));

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            int cur = A[i][j];
            if (cur == -1 || cur == 0) continue;

            int cnt = 0;
            for (int dir = 0; dir < 4; dir++) {
                int ny = i + dy[dir];
                int nx = j + dx[dir];

                if (oom(ny, nx)) continue;
                if (A[ny][nx] == -1) continue;

                int rem = cur / 5;
                B[ny][nx] += rem;
                cnt++;
            }
            B[i][j] -= (cur / 5) * cnt;
        }
    }

    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            A[i][j] += B[i][j];
}

void clean() {
    vector<int> tmp[2];

    for (int i = 0; i < 2; i++) {
        int ny = pos[i].first;
        int nx = pos[i].second;

        tmp[i].push_back(0);

        for (int dir = 0; dir < 4; dir++) {
            int d = dir + i * 4;

            while (!oom(ny + ddy[d], nx + ddx[d])) {
                ny += ddy[d];
                nx += ddx[d];

                if (A[ny][nx] == -1) break;
                tmp[i].push_back(A[ny][nx]);
            }
        }
        tmp[i].pop_back();
    }

    for (int i = 0; i < 2; i++) {
        int ny = pos[i].first;
        int nx = pos[i].second;

        int idx = 0;

        for (int dir = 0; dir < 4; dir++) {
            int d = dir + i * 4;

            while (!oom(ny + ddy[d], nx + ddx[d])) {
                ny += ddy[d];
                nx += ddx[d];
                if (A[ny][nx] == -1) break;

                A[ny][nx] = tmp[i][idx];
                idx++;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> R >> C >> T;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++) {
            cin >> A[i][j];
            if (A[i][j] == -1) pos.push_back({ i,j });
        }

    while (T--) {
        spread();
        clean();

        int sum = 0;
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                sum += A[i][j];
        sum += 2;
        ans = sum;
    }

    cout << ans;
    
    return 0;
}