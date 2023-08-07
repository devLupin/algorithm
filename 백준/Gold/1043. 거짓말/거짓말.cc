#include <bits/stdc++.h>
using namespace std;

const int SZ = 55;
int n, m, t, tmp, prv, nxt, ans;
bool tr[SZ];
vector<int> pt[SZ];
vector<int> adj[SZ];

void bfs() {
    queue<int> q;
    for(int i = 1; i <= n; i++)
        if(tr[i]) q.push(i);
  
    while(!q.empty()) {
        int cur = q.front(); 
        q.pop();

        for(int nxt : adj[cur]) {
            if(tr[nxt]) continue;
            tr[nxt] = 1;
            q.push(nxt);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> t;
    while(t--) {
        cin >> tmp;
        tr[tmp] = true;
    }

    for(int i=0; i<m; i++) {
        cin >> tmp;

        cin >> prv;
        pt[i].push_back(prv);

        while(--tmp) {
            cin >> nxt;
            pt[i].push_back(nxt);
            adj[prv].push_back(nxt);
            adj[nxt].push_back(prv);
            prv = nxt;
        }
    }

    bfs();

    for(int i=0; i<m; i++) {
        bool chk = false;
        for(int p : pt[i]) if(tr[p]) chk = true;
        if(!chk) ans++;
    }

    cout << ans;

    return 0;
}