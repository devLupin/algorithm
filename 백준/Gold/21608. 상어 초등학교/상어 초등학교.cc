#include <bits/stdc++.h>
using namespace std;

typedef struct pos{
    int y, x, adj, emp;
};

const int dy[] = { -1,1,0,0 };
const int dx[] = { 0,0,-1,1 };
const int score[5] = { 0, 1, 10, 100, 1000 };

const int SZ = 21;
int a, n, A[SZ*SZ][4], board[SZ][SZ], ans;


// 문제 속 정렬 조건
bool compare(pos& a, pos& b) {
    if (a.adj == b.adj) {
        if (a.emp == b.emp) {
            if (a.y == b.y) return a.x < b.x;
            return a.y < b.y;
        }
        return a.emp > b.emp;
    }
    return a.adj > b.adj;
}

void place(int cur) {
    vector<pos> v;

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            if (board[y][x] != 0) continue;  // 다른 정점이 있는 곳은 패스

            v.push_back({ y,x,0,0 });
            
            // 빈칸, 좋아하는 학생의 개수를 센다
            for (int dir = 0; dir < 4; dir++) {
                int ny = y + dy[dir];
                int nx = x + dx[dir];

                if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
                
                if (board[ny][nx] == 0) {
                    v.back().emp += 1;
                    continue;
                }
                else {
                    for (int t : A[cur])
                        if (t == board[ny][nx]) v.back().adj += 1;
                }
            }
        }
    }

    sort(v.begin(), v.end(), compare);

    pos new_pos = v[0];  // 찾고자 하는 위치
    board[new_pos.y][new_pos.x] = cur;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 0; i < n*n; i++) {
        cin >> a;
        for (int j = 0; j < 4; j++) cin >> A[a][j];

        place(a);
    }

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            int cur = board[y][x];
            int cnt = 0;

            for (int dir = 0; dir < 4; dir++) {
                int ny = y + dy[dir];
                int nx = x + dx[dir];

                if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;

                int cmp = board[ny][nx];
                for (int nxt : A[cur])
                    if (cmp == nxt) cnt++;
            }

            ans += score[cnt];
        }
    }

    /*cout << '\n';
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++)
            cout << board[y][x] << ' ';
        cout << '\n';
    }*/

    cout << ans;
    return 0;
}