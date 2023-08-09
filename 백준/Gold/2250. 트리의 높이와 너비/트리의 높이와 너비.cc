#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

const int SZ=10'002, INF=987654321;
int n, p, l, r, root, idx=1;
pii tree[SZ];
int low[SZ], high[SZ], is_root[SZ];

void inorder(int cur, int d) {
    if(cur < 1) return;

    inorder(tree[cur].first, d+1);
    low[d] = min(low[d], idx);
    high[d] = max(high[d], idx++);
    inorder(tree[cur].second, d+1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    fill(low, low+n+1, INF);

    for(int i=1; i<=n; i++) {
        cin >> p >> l >> r;
        tree[p] = {l, r};

        is_root[p]++;
        if(l != 1) is_root[l]++;
        if(r != 1) is_root[r]++;
    }

    for(int i=1; i<=n; i++)
        if(is_root[i] == 1)
            root = i;

    inorder(root, 1);
    
    int lv = 1, width = high[1] - low[1] + 1;
    for(int i=2; i<=n; i++) {
        int cmp = high[i] - low[i] + 1;
        if(cmp > width) {
            width = cmp;
            lv = i;
        }
    }

    cout << lv << ' ' << width;

    return 0;
}