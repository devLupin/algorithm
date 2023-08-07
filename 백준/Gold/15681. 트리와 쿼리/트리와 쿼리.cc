#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

const int SZ = 100'002;
int N, R, Q, U, V;
vector<int> adj[SZ];
int vis[SZ];
int sub_tree[SZ];

int count(int cur) {
    sub_tree[cur] = 1;
    
    for(int nxt : adj[cur]) {
        if(sub_tree[nxt] != 0) continue;
        sub_tree[cur] += count(nxt);
    }

    return sub_tree[cur];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> R >> Q;
    for(int i=1; i<N; i++) {
        cin >> U >> V;
        adj[U].push_back(V);
        adj[V].push_back(U);
    }

    count(R);

    while(Q--) {
        cin >> U;
        cout << sub_tree[U] << '\n';
    }

    return 0;
}