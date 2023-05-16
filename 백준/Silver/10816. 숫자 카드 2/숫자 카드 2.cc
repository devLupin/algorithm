#include <bits/stdc++.h>
using namespace std;

vector<int> a;
int N, M;

int lower_bound(int target) {
    int s = 0, e = a.size() - 1;
    while (s < e) {
        int m = (s + e) / 2;
        if (a[m] >= target) e = m;
        else s = m + 1;
    }
    return e;
}
int upper_bound(int target) {
    int s = 0, e = a.size() - 1;
    while (s < e) {
        int m = (s + e) / 2;
        if (a[m] > target) e = m;
        else s = m + 1;
    }
    return e;
}

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N; a.assign(N, 0);
    for (int i = 0; i < N; i++)
        cin >> a[i];
    
    sort(a.begin(), a.end());

    cin >> M;
    for (int tmp, i = 0; i < M; i++) {
        cin >> tmp;
        int lower = lower_bound(tmp);
        int upper = upper_bound(tmp);
        int ans = upper - lower;
        if (upper == N - 1 && a[N - 1] == tmp) ans++;

        cout << ans << ' ';
    }
    return 0;
}