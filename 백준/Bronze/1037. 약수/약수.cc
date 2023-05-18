#include <bits/stdc++.h>
using namespace std;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    if (v.size() == 1)
        cout << pow(v[0], 2);
    else {
        sort(v.begin(), v.end());
        cout << v[0] * v[v.size() - 1];
    }

    return 0;
}