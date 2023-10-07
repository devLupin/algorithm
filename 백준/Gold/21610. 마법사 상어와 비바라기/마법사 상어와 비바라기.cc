#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

const int dy[] = { 0,-1,-1,-1,0,1,1,1 };
const int dx[] = { -1,-1,0,1,1,1,0,-1 };
const int SZ = 102;

bool chk[SZ][SZ];
int n, m, A[SZ][SZ], d, s;
vector<pii> cloud;

void move() {
    vector<pii> v;

    while (!cloud.empty()) {
        auto cur = cloud.back();
        cloud.pop_back();

        int ny = cur.first;
        int nx = cur.second;
        for (int i = 0; i < s; i++) {
            ny += dy[d];
            nx += dx[d];

            if (ny > n) ny = 1;
            if (nx > n) nx = 1;
            if (ny < 1) ny = n;
            if (nx < 1) nx = n;
        }

        v.push_back({ ny, nx });
    }

    cloud.clear();
    cloud.assign(v.begin(), v.end());
}

void rain() {
    for (auto nxt : cloud)
        A[nxt.first][nxt.second] += 1;
}

void copy() {
    for (auto nxt : cloud) {
        for (int dir : {1, 3, 5, 7}) {
            int ny = nxt.first + dy[dir];
            int nx = nxt.second + dx[dir];

            if (ny < 1 || nx < 1 || ny > n || nx > n) continue;
            if(A[ny][nx] > 0) A[nxt.first][nxt.second] += 1;
        }
    }
}

void create() {
    for (int i = 1; i <= n; i++)
        memset(chk[i], false, sizeof(chk[i]));

    while (!cloud.empty()) {
        auto nxt = cloud.back();
        cloud.pop_back();

        chk[nxt.first][nxt.second] = true;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (A[i][j] >= 2 && !chk[i][j]) {
                A[i][j] -= 2;
                cloud.push_back({ i,j });
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> A[i][j];

    cloud.push_back({ n,1 });
    cloud.push_back({ n,2 });
    cloud.push_back({ n - 1,1 });
    cloud.push_back({ n - 1,2 });

    while (m--) {
        cin >> d >> s;
        d--;

        move();
        rain();
        copy();
        create();
    }

    int ret = 0;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            ret += A[i][j];

    cout << ret;

    return 0;
}