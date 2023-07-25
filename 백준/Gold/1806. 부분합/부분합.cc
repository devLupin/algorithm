#include <bits/stdc++.h>
using namespace std;

const int INF = 100000005;
int n, s, arr[100005], ans = INF;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> s;
    for(int i=0; i<n; i++)
        cin >> arr[i];

    int start=0, end=0, sum=0;

    while(start <= end) {
        if (sum >= s) {
            ans = min(ans, end-start);
            sum -= arr[start++];
        }
        else if(end == n) break;
        else sum += arr[end++];
    }

    cout << (ans == INF ? 0 : ans);
    return 0;
}