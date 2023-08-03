#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;

int n, d, c, mx;
ui ans;
vector<ui> v[200'005];
priority_queue<ui> pq;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    while(n--) {
        cin >> d >> c;
        v[d].push_back(c);
        mx = max(mx, d);
    }

    for(int i=mx; i !=0; i--) {
        for(ui a : v[i])
            pq.push(a);
        
        if(pq.empty()) continue;
        ans += pq.top();
        pq.pop();
    }

    cout << ans;

    return 0;
}