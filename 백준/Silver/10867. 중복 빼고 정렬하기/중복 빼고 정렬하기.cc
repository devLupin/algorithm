#include <bits/stdc++.h>
using namespace std;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;
    set<int> s;
    for (int tmp, i = 0; i < N; i++) {
        cin >> tmp;
        s.insert(tmp);
    }

    for (int n : s)
        cout << n << ' ';
    return 0;
}