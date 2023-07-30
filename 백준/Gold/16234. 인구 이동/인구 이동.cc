#include <bits/stdc++.h>
#define Y first
#define X second
using namespace std;
using pii = pair<int,int>;

const int SZ = 55;
const int dy[] = {-1,1,0,0};
const int dx[] = {0,0,-1,1};
int n, l, r, ans;
int A[SZ][SZ];
bool vis[SZ][SZ];

bool bfs(int y, int x) {
    int sum = 0;
    vector<pii> ret;
    queue<pii> q;

    q.push({y, x});
    ret.push_back({y, x});
    vis[y][x] = true;
    sum += A[y][x];

    while(!q.empty()) {
        pii cur = q.front();
        q.pop();

        for(int dir=0; dir<4; dir++) {
            int ny = cur.Y + dy[dir];
            int nx = cur.X + dx[dir];
            int cmp = abs(A[cur.Y][cur.X] - A[ny][nx]);

            if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
            if(!vis[ny][nx] && cmp >= l && cmp <= r) {
                vis[ny][nx] = true;
                q.push({ny, nx});
                
                ret.push_back({ny, nx});
                sum += A[ny][nx];
            }
        }
    }

    if(ret.size() > 1) {
        for(auto a : ret) 
            A[a.Y][a.X] = (sum / ret.size());
        return true;
    }

    return false;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> l >> r;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> A[i][j];
    
    while(true) {
        fill_n(&vis[0][0], SZ*SZ, false);
        bool flag = false;

        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                if(!vis[i][j] && bfs(i, j))
                    flag = true;

        if(!flag) break;
        ans++;
    }
    
    cout << ans;

    return 0;
}