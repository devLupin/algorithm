#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int TC;
    cin >> TC;

    while(TC--) {
        vector<int> ans;
        priority_queue<int> maxq;
        priority_queue<int, vector<int>, greater<int>> minq;
        int n;

        cin >> n;
        for(int a, i=1; i<=n; i++) {
            cin >> a;

            if(i % 2 == 0) minq.push(a);
            else {
                maxq.push(a);

                if(!minq.empty() && !maxq.empty()) {
                    if(minq.top() < maxq.top()) {
                        minq.push(maxq.top());
                        maxq.pop();
                        maxq.push(minq.top());
                        minq.pop();
                    }
                }
            }

            if(i % 2 != 0) ans.push_back(maxq.top());
        }

        cout << ans.size() << '\n';
        for(int nxt : ans) cout << nxt << ' ';
        cout << '\n';
    }
}
