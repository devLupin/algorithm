#include <bits/stdc++.h>
using namespace std;

const int SZ = 105;
int n, arr[SZ];
bool vis[SZ];
vector<int> v;

void dfs(int start, int next, vector<int> tmp) {
    if (start == next) {
        for(int x : tmp) {
            vis[x] = true;
            v.push_back(x);
        }
        return;
    }
    if(vis[next]) return;

    tmp.push_back(next);
    vis[next] = true;
    dfs(start, arr[next], tmp);
    tmp.pop_back();
    vis[next] = false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i=1; i<=n; i++) 
        cin >> arr[i];
    
    for(int i=1; i<=n; i++) {
        if(i == arr[i]) {
            v.push_back(i);
            vis[i] = true;
        }
        else if(!vis[i]) dfs(i, arr[i], {i});
    }

    sort(v.begin(), v.end());
    cout << v.size() << '\n';
    for(int x : v) cout << x << '\n';

    return 0;
}