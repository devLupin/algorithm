#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int a, b, c;

ll foo(ll y)
{
    if (y == 1) return a % c;
    ll val = foo(y / 2) % c;
    if (y % 2 == 0) return val*val%c;
    return val*val%c*a%c;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b >> c;
    cout << foo(b);
    return 0;
}