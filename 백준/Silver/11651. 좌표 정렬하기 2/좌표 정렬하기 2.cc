#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

bool compare(const pii& a, const pii& b) {
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;
    vector<pii> v(N);
    for (int i = 0; i < N; i++)
        cin >> v[i].first >> v[i].second;

    sort(v.begin(), v.end(), compare);

    for (pii cur : v)
        cout << cur.first << ' ' << cur.second << '\n';
    return 0;
}