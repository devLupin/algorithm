#include <bits/stdc++.h>
using namespace std;

int n, m, k;
string target, board[10];
unordered_map<string, int> cnt;

const int dx[8] = {-1,-1,-1,0,0,1,1,1};
const int dy[8] = {-1,0,1,-1,1,-1,0,1};

void dfs(int y, int x, string s) {
    cnt[s]++;
    if(s.size() == 5) return;

    for(int dir=0; dir<8; dir++) {
        int ny = (y + dy[dir] + n) % n;
        int nx = (x + dx[dir] + m) % m;

        dfs(ny, nx, s + board[ny][nx]);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;
    for(int i=0; i<n; i++) cin >> board[i];

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            dfs(i, j, string(1, board[i][j]));

    while(k--) {
        cin >> target;
        cout << cnt[target] << '\n';
    }

    return 0;
}