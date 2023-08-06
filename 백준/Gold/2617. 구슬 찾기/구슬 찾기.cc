#include <bits/stdc++.h>
using namespace std;

int n, m, p, c, ans;
vector<int> adj_h[100];
vector<int> adj_l[100];

bool solve(int start, vector<int> adj[]) {
    vector<bool> vis(n+1, false);
    
    queue<int> q;
    q.push(start);
    vis[start] = true;

    int cnt = 0;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for(int nxt : adj[cur]) {
            if(!vis[nxt]) {
                vis[nxt] = true;
                q.push(nxt);
                cnt++;
            }
        }
    }

    return cnt >= (n + 1)/2;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    while(m--) {
        cin >> p >> c;
        adj_h[p].push_back(c);
        adj_l[c].push_back(p);
    }

    for(int i=1; i<=n; i++)
        ans += (solve(i, adj_h) || solve(i, adj_l));
    cout << ans;

    return 0;
}