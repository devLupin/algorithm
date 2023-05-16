#include <bits/stdc++.h>
using namespace std;

struct Compare {
    bool operator() (const string& a, const string& b) const {
        if (a.size() == b.size())
            return a < b;
        return a.size() < b.size();
    }
};

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    set<string, Compare> s;
    for (int i = 0; i < N; i++) {
        string str; cin >> str;
        s.insert(str);
    }

    for (string str : s)
        cout << str << '\n';
    return 0;
}