#include <bits/stdc++.h>
using namespace std;

bool visited[5001] = { false, };

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    queue<int> q;
    int N, div; cin >> N >> div;
    for (int i = 1; i <= N; i++)
        q.push(i);

    int idx = 1;
    vector<int> ans;
    while (!q.empty()) {
        while (idx % div != 0) {
            q.push(q.front());
            q.pop();
            idx++;
        }
        idx = 1;
        ans.push_back(q.front());
        q.pop();
    }

    cout << '<';
    for (int i = 0; i < ans.size() - 1; i++)
        cout << ans[i] << ", ";
    cout << ans[ans.size() - 1] << '>';
    return 0;
}