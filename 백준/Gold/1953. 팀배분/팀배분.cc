#include <bits/stdc++.h>
using namespace std;

const int SZ=105;
int n, cnt, tmp;
vector<int> adj[SZ];
vector<int> color;

void bfs() {
    for(int i=1; i<=n; i++) {
        if(color[i] != 0) continue;

        queue<int> q;
        q.push(i);
        color[i] = 1;

        while(!q.empty()) {
            int cur = q.front();
            q.pop();

            for(int nxt : adj[cur]) {
                if(color[nxt] != 0) continue;
                color[nxt] = color[cur] * -1;
                q.push(nxt);
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    color.assign(n+1, 0);

    for(int i=1; i<=n; i++) {
        cin >> cnt;
        while(cnt--) {
            cin >> tmp;
            adj[i].push_back(tmp);
            adj[tmp].push_back(i);
        }
    }

    bfs();

    vector<int> blue;
    vector<int> red;

    for(int i=1; i<=n; i++) {
        if(color[i] == 1) blue.push_back(i);
        else red.push_back(i);
    }

    cout << blue.size() << '\n';
    for(int x : blue) cout << x << ' ';

    cout << '\n' << red.size() << '\n';
    for(int x : red) cout << x << ' ';

    return 0;
}