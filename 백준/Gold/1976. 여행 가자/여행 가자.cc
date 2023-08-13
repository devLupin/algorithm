#include <bits/stdc++.h>
using namespace std;

const int SZ=202;
int n, m, x, P[SZ];

int Find(int v) {
    if(v == P[v]) return v;
    else return P[v] = Find(P[v]);
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

    for(int i=1; i<=n; i++) P[i] = i;

    for(int u=1; u<=n; u++) {
        for(int v=1; v<=n; v++) {
            cin >> x;
            if(x != 0) Union(u, v);
        }
    }

    int past, here, chk=1;
    cin >> past;
    for(int i=1; i<m; i++) {
        cin >> here;
        if(Find(past) != Find(here)) {
            chk = 0;
            break;
        }
        past = here;
    }

    cout << (chk==1 ? "YES" : "NO");

    return 0;
}