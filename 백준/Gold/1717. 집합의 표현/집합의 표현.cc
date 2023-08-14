#include <bits/stdc++.h>
using namespace std;

const int SZ = 1'000'002;
int n, m, opt, a, b, P[SZ];

int Find(int u) {
    if(P[u] == u) return u;
    return P[u] = Find(P[u]);
}

void Union(int u, int v) {
    u = Find(u);
    v = Find(v);
    P[u] = v;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i=0; i<=n; i++) P[i] = i;

    while(m--) {
        cin >> opt >> a >> b;

        if(opt == 0) Union(a, b);
        else cout << (Find(a) == Find(b) ? "YES\n": "NO\n");
    }    

    return 0;
}