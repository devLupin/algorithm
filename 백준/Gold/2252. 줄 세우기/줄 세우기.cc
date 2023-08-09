#include <bits/stdc++.h>
using namespace std;

const int SZ = 32'002;
int n, m, from, to, deg[SZ];
vector<int> res;
vector<int> adj[SZ];
queue<int> q;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    while(m--) {
        cin >> from >> to;
        adj[from].push_back(to);
        deg[to]++;
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

    for(int a : res)
        cout << a << ' ';

    return 0;
}