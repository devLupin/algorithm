#include <bits/stdc++.h>
using namespace std;

const int SZ = 1'002;
int n, m, cnt, a, b, deg[SZ];
vector<int> adj[SZ], res;
queue<int> q;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    while(m--) {
        cin >> cnt;
        cin >> a;
        for(int i=1; i<cnt; i++) {
            cin >> b;
            adj[a].push_back(b);
            deg[b]++;
            a = b;
        }
    }

    for(int i=1; i<=n; i++)
        if(deg[i] == 0) q.push(i);
    
    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        res.push_back(cur);

        for(int nxt : adj[cur]) {
            deg[nxt]--;
            if(deg[nxt] == 0) q.push(nxt);
        }
    }

    if(res.size() != n) cout << 0;
    else 
        for(int a : res) cout << a << '\n';

    return 0;
}