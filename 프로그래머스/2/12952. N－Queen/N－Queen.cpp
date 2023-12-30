#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int ans, N, A[15];
int dx[] = { -1,-1,-1,0,1,1,1,0 };
int dy[] = { -1,0,1,1,1,0,-1,-1 };

bool oom(int x, int y) { return x<1 || y<1 || x>N || y>N; }

bool search(int i, int j) {
    vector<pii> chk(8, { i, j });

    for (int dir = 0; dir < 8; dir++) {
        pii cur = chk[dir];
        int x = chk[dir].first + dx[dir];
        int y = chk[dir].second + dy[dir];

        while (!oom(x, y)) {
            if (A[x] == y) return false;
            x += dx[dir];
            y += dy[dir];
        }
    }

    return true;
}

void dfs(int x, int cnt) {
    if (cnt == N) {
        ans++;
        return;
    }

    for (int y = 1; y <= N; y++) {
        if (search(x, y)) {
            A[x] = y;
            dfs(x + 1, cnt + 1);
            A[x] = 0;
        }
    }
}

int solution(int n) {
    N = n;
    dfs(1, 0);
    return ans;
}