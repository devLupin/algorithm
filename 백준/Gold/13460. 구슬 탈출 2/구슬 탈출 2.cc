#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

const int SZ = 10, MX = SZ + 1;
const int dy[] = {-1,1,0,0};
const int dx[] = {0,0,-1,1};
int n, m, ans = MX;
vector<string> board;

char get_first(int dir, int ry, int rx, int by, int bx) {
    if(dir==0) return ry < by ? 'R' : 'B';
    else if(dir==1) return ry > by ? 'R' : 'B';
    else if(dir==2) return rx < bx ? 'R' : 'B';
    else return rx > bx ? 'R' : 'B';
}

vector<string> move(int dir, vector<string> tmp, int cnt) {
    int ry, rx, by, bx;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(tmp[i][j] == 'R') tie(ry, rx) = {i, j};
            else if(tmp[i][j] == 'B') tie(by, bx) = {i,j};
        }
    }

    char first = get_first(dir, ry, rx, by, bx);
    bool r_chk = false, b_chk = false;

    if(first == 'R') {
        while(ry >= 0 && rx >= 0 && ry < n && rx < m) {
            int ny = ry + dy[dir];
            int nx = rx + dx[dir];

            if(tmp[ny][nx] == 'O') {
                tmp[ry][rx] = '.';
                r_chk = true;
                break;
            }
            else if(tmp[ny][nx] != '.') break;

            swap(tmp[ny][nx], tmp[ry][rx]);
            tie(ry, rx) = {ny, nx};
        }

        while(by >= 0 && bx >= 0 && by < n && bx < m) {
            int ny = by + dy[dir];
            int nx = bx + dx[dir];

            if(tmp[ny][nx] == 'O') {
                tmp[by][bx] = '.';
                b_chk = true;
                break;
            }
            else if(tmp[ny][nx] != '.') break;

            swap(tmp[ny][nx], tmp[by][bx]);
            tie(by, bx) = {ny, nx};
        }
    }

    else {
        while(by >= 0 && bx >= 0 && by < n && bx < m) {
            int ny = by + dy[dir];
            int nx = bx + dx[dir];

            if(tmp[ny][nx] == 'O') {
                tmp[by][bx] = '.';
                b_chk = true;
                break;
            }
            else if(tmp[ny][nx] != '.') break;

            swap(tmp[ny][nx], tmp[by][bx]);
            tie(by, bx) = {ny, nx};
        }

        while(ry >= 0 && rx >= 0 && ry < n && rx < m) {
            int ny = ry + dy[dir];
            int nx = rx + dx[dir];

            if(tmp[ny][nx] == 'O') {
                tmp[ry][rx] = '.';
                r_chk = true;
                break;
            }
            else if(tmp[ny][nx] != '.') break;

            swap(tmp[ny][nx], tmp[ry][rx]);
            tie(ry, rx) = {ny, nx};
        }
    }

    if(r_chk && b_chk) return {""};
    else if(r_chk) {
        ans = min(ans, cnt);
        return {""};
    }
    else if(b_chk) return {""};
    return tmp;
}

void solve(int cnt, vector<string> prev) {
    if(cnt > SZ || cnt >= ans) return;

    for(int dir=0; dir<4; dir++) {
        auto tmp = move(dir, prev, cnt);
        if(tmp[0] == "") continue;

        solve(cnt+1, tmp);
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i=0; i<n; i++) {
        string s;
        cin >> s;
        board.push_back(s);
    }

    solve(1, board);

    cout << (ans == MX ? -1 : ans);
    return 0;
}