#include <bits/stdc++.h>
using namespace std;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stack<int> st;
    int N; cin >> N;
    vector<int> v;
    for (int i = 1; i <= N; i++)
        v.push_back(i);

    string ans = "+";
    int idx = 1;
    st.push(v[0]);

    for (int tmp, i = 0; i < N; i++) {
        cin >> tmp;

        if (st.empty()) {
            st.push(v[idx++]);
            ans += '+';
        }

        while (st.top() != tmp && idx < N) {
            st.push(v[idx++]);
            ans += '+';
        }

        if (!st.empty() && st.top() == tmp) {
            st.pop();
            ans += '-';
        }

        else {
            cout << "NO";
            exit(0);
        }
    }

    for (char c : ans) cout << c << '\n';
    return 0;
}