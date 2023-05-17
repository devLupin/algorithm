#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int tc; cin >> tc;
    while (tc--) {
        int n, m; cin >> n >> m;
        priority_queue<int> pq;
        queue<pii> q;

        for (int tmp, i = 0; i < n; i++) {
            cin >> tmp;
            q.push({ i, tmp });
            pq.push(tmp);
        }

        int ans = 0;
        while (!q.empty()) {
            pii cur = q.front();
            q.pop();

            if (pq.top() == cur.second) {
                pq.pop();
                ans++;

                if (cur.first == m)
                    break;
            }
            else
                q.push(cur);
        }

        cout << ans << '\n';
    }
    return 0;
}