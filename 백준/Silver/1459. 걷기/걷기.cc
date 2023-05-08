#include <iostream>
using namespace std;
using ll = long long;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll x, y, w, s;
    cin >> x >> y >> w >> s;

    ll c1 = (x + y) * w;
    ll c2 = (x + y) % 2 == 0 ? (max(x, y) * s) : ((max(x, y) - 1) * s + w);
    ll c3 = min(x, y) * s + abs(x - y) * w;

    cout << min(c1, min(c2, c3));
    return 0;
}