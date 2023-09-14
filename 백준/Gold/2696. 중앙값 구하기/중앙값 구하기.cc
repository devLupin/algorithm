#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int TC;
    cin >> TC;

    while(TC--) {
        vector<int> ans;
        priority_queue<int> up;
        priority_queue<int, vector<int>, greater<int>> down;
        int n;

        cin >> n;
        for(int a, i=1; i<=n; i++) {
            cin >> a;

            if(i % 2 == 0) down.push(a);
            else {
                up.push(a);

                if(!down.empty() && !up.empty()) {
                    if(down.top() < up.top()) {
                        down.push(up.top());
                        up.pop();
                        up.push(down.top());
                        down.pop();
                    }
                }
            }

            if(i % 2 != 0) ans.push_back(up.top());
        }

        cout << ans.size() << '\n';
        for(int nxt : ans) cout << nxt << ' ';
        cout << '\n';
    }
}